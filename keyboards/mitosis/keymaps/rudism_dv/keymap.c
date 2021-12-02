// This is the Dvorak-friendly layout for the Mitosis by CarVac (/u/CarVac)
// It features space on the left thumb, shift on the right thumb, a
//  number layer with all the numbers on the home row, and a function layer
//  that provides mouse keys among other things.

#include QMK_KEYBOARD_H

enum mitosis_layers
{
    _STD,
    _NUM,
    _FN,
    _MACRO
};

enum custom_keycodes
{
    PLPYTOG = SAFE_RANGE,
    PLPYHLD
};

//Mousekeys
#define MOUSEKEY_DELAY 300
#define MOUSEKEY_INTERNAL 50
#define MOUSEKEY_MAX_SPEED 20
#define MOUSEKEY_TIME_TO_MAX 30
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#define LT_FN LT(_FN,KC_ENT)
#define LT_NUM LT(_NUM,KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* QWERTY
    * .--------------------------------------------..--------------------------------------------.
    * | Q      | W      | E      | R      | T      || Y      | U      | I      | O      | P      |
    * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
    * | A      | S      | D      | F      | G      || J      | H      | K      | L      | ;      |
    * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
    * | Z      | X      | C      | V      | B      || N      | M      | ,      | .      | /      |
    * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
    *          | MOUSE2 | MOUSE1 | LCTRL  | CAPS   || BSPACE | LALT   | PRTSCR | VOL+   |
    *          |--------+--------+--------+--------||--------+--------+--------+--------|
    *          | SCRHLD | LSHIFT | LGUI   | ENTER  || SPACE  | RGUI   | RSHIFT | VOL-   |
    *          '-----------------------------------''-----------------------------------'
    */
    [_STD] = LAYOUT( /* Standard; as compatible with dvorak and qwerty as possible
                        hold ENTER for FN layer, hold SPACE for NUM layer */
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
               KC_BTN2, KC_BTN1, KC_LCTL, KC_CAPS, KC_BSPC, KC_LALT, KC_PSCR, KC_VOLU,
               PLPYHLD, KC_LSFT, KC_LGUI, LT_FN,   LT_NUM,  KC_RGUI, KC_RSFT, KC_VOLD
    ),

   /* Number layout, for data entry and programming purposes (Dvorak result in parens)
    * .--------------------------------------------..--------------------------------------------.
    * | ('")   |   (,<) |   (.>) | - ([{) | = (]}) || ] (=+) | ' (-_) | `      | [ (/?) | \      |
    * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
    * | 1      | 2      | 3      | 4      | 5      || 6      | 7      | 8      | 9      | 0      |
    * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
    * | F1     | F2     | F3     | F4     | F5     || F6     | F7     | F8     | F9     | F10    |
    * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
    *          |        |        |        |        ||        |        |        |        |
    *          |--------+--------+--------+--------||--------+--------+--------+--------|
    *          |        |        |        |        ||        |        |        |        |
    *          '-----------------------------------''-----------------------------------'
    */
    [_NUM] = LAYOUT( /* Number layout along the home row for maximum speed*/
        _______, _______, _______, KC_MINS, KC_EQL,  KC_RBRC, KC_QUOT, KC_GRV,  KC_LBRC, KC_BSLS,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
                 _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______
    ),


   /* Fn layout, mouse buttons and cursor movement
    * .--------------------------------------------..--------------------------------------------.
    * | PRTSCR | SCRTOG | UP     | MOUSE1 | MOUSE2 || ENTER  | SPACE  | PGUP   | INS    | DEL    |
    * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
    * | MOUSE3 | LEFT   | DOWN   | RIGHT  | SCRHLD || TAB    | HOME   | PGDN   | END    | BCKSPC |
    * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
    * | BACK   | FORWRD | SEARCH | STOP   | REFRSH || F11    | F12    | EXEC   | COPY   | PASTE  |
    * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
    *          |        |        |        |        ||        |        |        |        |
    *          |--------+--------+--------+--------||--------+--------+--------+--------|
    *          | MOUSE3 |        |        |        ||        |        |        |        |
    *          '-----------------------------------''-----------------------------------'
    */
    [_FN] = LAYOUT( /* Function Layer, primary alternative layer featuring numpad on right hand,
                       cursor keys on left hand, and all symbols*/
        KC_PSCR, PLPYTOG, KC_UP,   KC_BTN1, KC_BTN2, KC_ENT,  KC_SPC,  KC_PGUP, KC_INS,  KC_DEL,
        KC_BTN3, KC_LEFT, KC_DOWN, KC_RGHT, PLPYHLD, KC_TAB,  KC_HOME, KC_PGDN, KC_END,  KC_BSPC,
        KC_WBAK, KC_WFWD, KC_WSCH, KC_WSTP, KC_WREF, KC_F11,  KC_F12,  KC_EXEC, KC_COPY, KC_PSTE,
                 _______, _______, _______, _______, _______, _______, _______, _______,
                 KC_BTN3, _______, _______, _______, _______, _______, _______, _______
    ),

   /* blank key layout template
    * .--------------------------------------------..--------------------------------------------.
    * |        |        |        |        |        ||        |        |        |        |        |
    * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
    * |        |        |        |        |        ||        |        |        |        |        |
    * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
    * |        |        |        |        |        ||        |        |        |        |        |
    * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
    *          |        |        |        |        ||        |        |        |        |
    *          |--------+--------+--------+--------||--------+--------+--------+--------|
    *          |        |        |        |        ||        |        |        |        |
    *          '-----------------------------------''-----------------------------------'
    */
    [_MACRO] = LAYOUT( /* Macro layer when holding both FN and NUM layer keys together */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

void matrix_scan_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

    switch (layer) {
        case _STD:
            set_led_off;
            break;
        case _FN:
            set_led_blue;
            break;
        case _NUM:
            set_led_red;
            break;
        case _MACRO:
            set_led_magenta;
            break;
        default:
            break;
    }
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PLPYTOG:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_NLCK) SS_DELAY(15) SS_TAP(X_NLCK));
            }
            break;
        case PLPYHLD:
            SEND_STRING(SS_TAP(X_NLCK) SS_DELAY(15) SS_TAP(X_NLCK));
            break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _FN, _NUM, _MACRO);
}
