#include QMK_KEYBOARD_H

#include "keymap_finnish.h"
#include "sendstring_finnish.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _SYMB 1
#define _SYMB2 2
#define _NAV 3
#define _NAV2 4
#define _ADJUST 5 

#define KC_PLPS KC_MEDIA_PLAY_PAUSE
#define KC_NEXT TD(NEXT_PREV)
#define KC_VOLU KC_AUDIO_VOL_UP
#define KC_VOLD KC_AUDIO_VOL_DOWN

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  NAV2,
  ADJUST,
  ARROW,
  DEFINE,
  CTRL_V,
  DEGREE_S,
  MICRO_S,
  ALT_TAB,
  KC_UP_RIGHT,
  KC_UP_LEFT,
  KC_DOWN_RIGHT,
  KC_DOWN_LEFT,
};

// Tap Dance declarations
enum {
    NEXT_PREV,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [NEXT_PREV] = ACTION_TAP_DANCE_DOUBLE(KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK),
};


// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB2)
#define NAV_L   TT(_NAV)

#define KC_ALAS LALT_T(FI_LABK)
#define KC_CTPL RCTL_T(FI_MINS)

#define KC_ADGR LT(_ADJUST, KC_ESC)
#define KC_ADMI LT(_ADJUST, FI_PLUS)

#define KC_NA_I LT(_NAV, KC_I)
#define KC_SY_H LT(_SYMB, KC_H)

#define KC_N2_A LT(_NAV2, KC_A)
#define KC_N2_S LT(_NAV2, KC_S)

#define KC_SYEN LT(_SYMB, KC_END)
#define KC_SYHO LT(_SYMB, KC_HOME)

#define KC_NADE LT(_NAV2, KC_DEL)

#define KC_ALF4  LALT(KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { 

  [_DVORAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ADGR ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_ADMI ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,FI_DOT  ,FI_ODIA ,FI_ADIA ,KC_P    ,KC_Y    ,ARROW   ,                          DEFINE  ,KC_F    ,KC_G    ,KC_K    ,KC_R    ,KC_B    ,FI_EQL ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC ,KC_N2_A ,KC_O    ,KC_E    ,KC_NA_I ,KC_U    ,FI_QUOT ,                          FI_DQUO ,KC_D    ,KC_SY_H ,KC_T    ,KC_N    ,KC_N2_S ,FI_COMM ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,FI_UNDS ,KC_Q    ,KC_J    ,KC_C    ,KC_X    ,KC_PLPS ,KC_NEXT ,        KC_VOLD ,KC_VOLU ,KC_L    ,KC_M    ,KC_W    ,KC_V    ,KC_Z    ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,FI_QUES ,KC_PPLS ,KC_ALAS ,     SYM_L   ,    KC_SPC  ,KC_CTPL ,        KC_NADE ,KC_ENT  ,     SYM_L,      DM_PLY1 ,DM_PLY2 ,KC_APP  ,KC_LGUI 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     FI_TILD  ,_______ ,_______ ,_______  ,_______ ,_______,                                            _______ ,_______ ,_______ ,_______ ,_______  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,FI_AT   ,FI_LCBR ,FI_RCBR ,FI_PIPE ,FI_CIRC ,                          _______ ,_______ ,_______ ,KC_PPLS ,KC_PMNS ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,FI_HASH ,FI_EQL  ,FI_LPRN ,FI_RPRN ,FI_SCLN ,FI_DLR  ,                          _______ ,_______ ,_______ ,FI_EQL  ,FI_RABK ,FI_LABK ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,FI_PERC ,FI_BSLS ,FI_LBRC ,FI_RBRC ,FI_AMPR ,DEGREE_S,MICRO_S ,        _______ ,_______ ,_______  ,_______,KC_PAST, KC_PSLS ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,FI_ACUT ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

    [_SYMB2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     FI_TILD   ,_______ ,_______ ,_______  ,_______ ,_______,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,FI_AT   ,FI_LCBR ,FI_RCBR ,FI_PIPE ,FI_CIRC ,                          _______ ,_______ ,KC_P7 ,KC_P8 ,KC_P9 ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,FI_HASH ,FI_EQL  ,FI_LPRN ,FI_RPRN ,FI_SCLN ,FI_DLR  ,                          _______ ,_______ ,KC_P4 ,KC_P5 ,KC_P6 ,KC_DEL ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,FI_PERC ,FI_BSLS ,FI_LBRC ,FI_RBRC ,FI_AMPR ,DEGREE_S,MICRO_S ,        _______ ,_______ ,_______  ,KC_P1 ,KC_P2 ,KC_P3 ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,FI_ACUT ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_P0 ,     KC_P0 ,KC_PDOT ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ALF4 ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,C(KC_S) ,C(KC_Y) ,C(KC_F) ,_______ ,_______ ,_______ ,                          _______ ,KC_PSLS ,KC_HOME ,KC_UP   ,KC_END  ,_______ ,_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,C(KC_X) ,C(KC_C) ,CTRL_V ,_______ ,_______ ,_______ ,                          _______ ,KC_PAST ,KC_LEFT ,KC_DOWN ,KC_RIGHT,KC_DEL  ,_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,C(KC_Z) ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,KC_PGUP ,_______ ,KC_PGDN ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        ALT_TAB ,_______ ,    XXXXXXX ,     DM_REC1 ,DM_REC2 ,_______ ,DM_RSTP 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_WH_U ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_UP_LEFT ,KC_MS_U ,KC_UP_RIGHT ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_WH_L ,KC_WH_D ,KC_WH_R ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_DOWN_LEFT ,XXXXXXX ,KC_DOWN_RIGHT ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        KC_BTN2 ,KC_BTN1 ,    KC_BTN3 ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NLCK ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                          RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    DM_RSTP ,     DM_REC1 ,DM_PLY1 ,DM_REC2 ,DM_PLY2 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

void send_altcode(uint16_t mask, keyrecord_t *record) {
	
	/* Sends the "alt code" defined in mask, i.e. send_altcode(1234) 
	holds left alt while sending KP_1, KP_2, KP_3 and KP_4 taps, 
	then releases left alt if it wasn't being held by the user. 
	
	NOTE: If your alt code starts with a 0, leave that out, else the
	mask will be treated as octal and your firmware won't compile.
	send_altcode(123) will output KP_0, KP_1, KP_2 and KP_3. */
	
	// Check & save mod state
	
	static uint8_t lalt_mask;
	lalt_mask = keyboard_report->mods & KC_LALT;
	
	// Split up the mask into its 4 decimals
	
	static uint16_t kp[4];
	
	kp[0] = mask / 1000;
	kp[1] = mask / 100 - kp[0] * 100;
	kp[2] = mask / 10 - kp[0] * 1000 - kp[1] * 10;
	kp[3] = mask - kp[0] * 1000 - kp[1] * 100 - kp[2] * 10;
	
	// Convert to keycodes
	
	for (uint8_t i=0; i<=3; i++) {
		switch(kp[i]) {
			case 0:
				kp[i] = KC_KP_0; break;
			case 1:
				kp[i] = KC_KP_1; break;
			case 2:
				kp[i] = KC_KP_2; break;
			case 3:
				kp[i] = KC_KP_3; break;
			case 4:
				kp[i] = KC_KP_4; break;
			case 5:
				kp[i] = KC_KP_5; break;
			case 6:
				kp[i] = KC_KP_6; break;
			case 7:
				kp[i] = KC_KP_7; break;
			case 8:
				kp[i] = KC_KP_8; break;
			case 9:
				kp[i] = KC_KP_9; break;
		}
	}
	
	// Put ALT into pressed state
	
	if (!lalt_mask) {
		register_code(KC_LALT);
		send_keyboard_report();
	}
	
	// The send_keyboard_report() spam is not pretty, but necessary.
	
	add_key(kp[0]);
	send_keyboard_report();
	del_key(kp[0]);
	send_keyboard_report();
	add_key(kp[1]);
	send_keyboard_report();		
	del_key(kp[1]);
	send_keyboard_report();
	add_key(kp[2]);
	send_keyboard_report();		
	del_key(kp[2]);
	send_keyboard_report();
	add_key(kp[3]);
	send_keyboard_report();
	del_key(kp[3]);
	send_keyboard_report();
	
	// If user wasn't pressing ALT, release it
	
	if (!lalt_mask) {
		unregister_code(KC_LALT);
	}
	
	send_keyboard_report();

}

// Special cases for some characters
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ARROW:
    {    
       if(record->event.pressed)
       {
         SEND_STRING("->");
       }
      
    }
    break;
    case DEFINE:
    { 
       if(record->event.pressed)
       {
         SEND_STRING("#define ");
       }
    }
    break;
    case CTRL_V:
    {
       if(!record->event.pressed)
       {
          if(layer_state_is(_NAV))
            SEND_STRING(SS_LCTL("v"));
          else
            SEND_STRING("ie");
       }
    }
    break;
    case DEGREE_S:
    {
      if(record->event.pressed)
       {
         send_altcode(176, record);
       } 
    }
    break;
    case MICRO_S:
    {
      if(record->event.pressed)
       {
         send_altcode(181, record);
       } 
    }
    break;
    case ALT_TAB:
    {
       if(record->event.pressed)
       {
         register_code(KC_LALT);
         tap_code(KC_TAB);
       } else
       {
         unregister_code(KC_LALT);
       }
       break;
    }
   case KC_UP_RIGHT:
      if (record->event.pressed) {
            // when keycode KC_UP_RIGHT is pressed
            register_code(KC_MS_UP);  // press the key
            register_code(KC_MS_RIGHT);  // press the key
      } else {
            // when keycode KC_UP_RIGHT is released
            unregister_code(KC_MS_RIGHT);  // release the key
            unregister_code(KC_MS_UP);  // release the key
      }
      break;

   case KC_UP_LEFT:
      if (record->event.pressed) {
            // when keycode KC_UP_LEFT is pressed
            register_code(KC_MS_UP);  // press the key
            register_code(KC_MS_LEFT);  // press the key
      } else {
            // when keycode KC_UP_RIGHT is released
            unregister_code(KC_MS_LEFT);  // release the key
            unregister_code(KC_MS_UP);  // release the key
      }
      break;

   case KC_DOWN_RIGHT:
      if (record->event.pressed) {
            // when keycode KC_UP_RIGHT is pressed
            register_code(KC_MS_DOWN);  // press the key
            register_code(KC_MS_RIGHT);  // press the key
      } else {
            // when keycode KC_UP_RIGHT is released
            unregister_code(KC_MS_RIGHT);  // release the key
            unregister_code(KC_MS_DOWN);  // release the key
      }
      break;

   case KC_DOWN_LEFT:
      if (record->event.pressed) {
            // when keycode KC_UP_RIGHT is pressed
            register_code(KC_MS_DOWN);  // press the key
            register_code(KC_MS_LEFT);  // press the key
      } else {
            // when keycode KC_UP_RIGHT is released
            unregister_code(KC_MS_LEFT);  // release the key
            unregister_code(KC_MS_DOWN);  // release the key
      }
      break;

    default:
      return true;
  }
  return true;
}
