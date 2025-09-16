/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "keycodes.h"
#include "keymap_us.h"
#include "modifiers.h"
#include QMK_KEYBOARD_H

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_ADJUST,
    LAYER_POINTER,
};

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#define LOWER LT(LAYER_LOWER, KC_SPC)
#define RAISE LT(LAYER_RAISE, KC_SPC)
#define ADJUST LT(LAYER_ADJUST, KC_SPC)
#define POINTER MO(LAYER_POINTER)

#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

#define HRL_A  MT(MOD_LCTL, KC_A)
#define HRL_S  MT(MOD_LSFT, KC_S)
#define HRL_D  MT(MOD_RALT, KC_D)
#define HRL_F  MT(MOD_LGUI, KC_F)

#define BRL_Z  MT(MOD_LCTL, KC_Z)
#define BRL_X  MT(MOD_LSFT, KC_X)
#define BRL_C  MT(MOD_RALT, KC_C)
#define BRL_V  MT(MOD_LGUI, KC_V)

#define HRR_J  MT(MOD_RGUI, KC_J)
#define HRR_K  MT(MOD_RALT, KC_K)
#define HRR_L  MT(MOD_RSFT, KC_L)
#define HRR_SC MT(MOD_RCTL, KC_SCLN)

#define BRR_M    MT(MOD_RGUI, KC_M)
#define BRR_COMM MT(MOD_RALT, KC_COMM)
#define BRR_DOT  MT(MOD_RSFT, KC_DOT)
#define BRR_SLSH MT(MOD_RCTL, KC_SLSH)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────╮
        KC_ESC,    KC_1,   KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,  KC_8,     KC_9,    KC_0,     KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────┤
        KC_ESC,    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,  KC_I,     KC_O,    KC_P,     KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────┤
        POINTER,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────┤
        POINTER,   BRL_Z,   BRL_X,  BRL_C,   BRL_V,   KC_B,       KC_N,    BRR_M, BRR_COMM, BRR_DOT, BRR_SLSH, POINTER,
  // ╰──────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────╯
                         KC_LALT, KC_BSPC,   LOWER,  RAISE,    LOWER,   RAISE,  KC_DEL,  KC_MUTE
  //                    ╰───────────────────────────────────╯ ╰─────────────────────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC,    KC_AMPR, KC_ASTR, KC_LPRN,    KC_RPRN,    KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
       KC_NO,   KC_ESC,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC,    KC_AMPR, KC_ASTR, KC_UNDS,    KC_BSPC,    KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
       KC_NO,   KC_TAB,  KC_MINS, KC_EQL,  S(KC_1), KC_SCLN,   KC_BSLS,    KC_GRV,  KC_LPRN, KC_RPRN,    KC_ENT,     KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
       KC_NO,   KC_COMM, KC_DOT,  KC_BSLS, KC_QUOT, KC_GRV,    S(KC_BSLS), KC_LBRC, KC_RBRC, S(KC_LBRC), S(KC_RBRC), KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                         KC_TRNS, KC_TRNS, KC_TRNS, ADJUST,    KC_TRNS,    ADJUST,  KC_TRNS, KC_TRNS
  //                    ╰───────────────────────────────────╯ ╰─────────────────────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_F12, KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,     KC_F11,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO,  KC_ESC,     S(KC_9),    S(KC_LBRC), KC_LBRC, KC_NO,      KC_EQL,  KC_7,    KC_8,    KC_9,   KC_BSPC,    KC_NO,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO,  KC_TAB,     S(KC_MINS), S(KC_EQL),  S(KC_0), KC_NO,      KC_MINS, KC_4,    KC_5,    KC_6,   KC_ENT,     KC_NO,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO,  S(KC_COMM), S(KC_DOT),  S(KC_BSLS), KC_DQT,  KC_TILD,    KC_0,    KC_1,    KC_2,    KC_3,   S(KC_SLSH), KC_NO,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_TRNS, KC_TRNS, ADJUST, KC_TRNS,    ADJUST, KC_TRNS, KC_TRNS, KC_TRNS
  //                             ╰──────────────────────────────────╯ ╰──────────────────────────────────╯
  ),

  [LAYER_ADJUST] = LAYOUT(
  // ╭────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────╮
       KC_TRNS, KC_TRNS, KC_TRNS, EE_CLR,   QK_BOOT,  DB_TOGG,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
  // ├────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────┤
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC,  KC_TRNS,
  // ├────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────┤
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_ENT,  KC_TRNS,
  // ├────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────┤
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_TRNS, KC_TRNS,
  // ╰────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────╯
                          KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  //                     ╰────────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, EE_CLR,  QK_BOOT,    QK_BOOT, EE_CLR,  SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1, KC_BTN2, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLEE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif // RGB_MATRIX_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_LOWER]      = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_RAISE]      = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_POINTER]    = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE

// const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
//   // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
//            'L',     'L',     'L',     'L',     'L',     'L',        'R',     'R',     'R',     'R',     'R',     'R',
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//            'L',     'L',     'L',     'L',     'L',     'L',        'R',     'R',     'R',     'R',     'R',     'R',
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//            'L',     'L',     'L',     'L',     'L',     'L',        'R',     'R',     'R',     'R',     'R',     'R',
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//            'L',     'L',     'L',     'L',     'L',     'L',        'R',     'R',     'R',     'R',     'R',     'R',
//   // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
//                              'L',     'L',     'L',     'L',        'R',     'R',     'R',     'R'
//  //                     ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
// );
