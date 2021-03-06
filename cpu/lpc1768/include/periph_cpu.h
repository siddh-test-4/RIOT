/*
 * Copyright (C) 2015 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup         cpu_lpc1768
 * @{
 *
 * @file
 * @brief           CPU specific definitions for internal peripheral handling
 *
 * @author          Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @author          Bas Stottelaar <basstottelaar@gmail.com>
 */

#ifndef PERIPH_CPU_H
#define PERIPH_CPU_H

#include <stdint.h>

#include "cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name   Override the default GPIO type
 * @{
 */
#define HAVE_GPIO_T
typedef uint8_t gpio_t;
/** @} */

/**
 * @brief   Define a custom GPIO_PIN macro for the lpc1768
 */
#define GPIO_PIN(port, pin)     (gpio_t)((port << 5) | pin)

/**
 * @name    Override the default GPIO mode values
 * @{
 */
#define PIN_DIR_IN            (0x00 << 0)
#define PIN_DIR_OUT           (0x01 << 0)
#define PIN_MODE_PU           (0x00 << 1)
#define PIN_MODE_PD           (0x02 << 1)
#define PIN_MODE_NONE         (0x03 << 1)
#define PIN_MODE_OD           (0x01 << 3)

#define HAVE_GPIO_MODE_T
typedef enum {
    GPIO_IN    = (PIN_DIR_IN | PIN_MODE_NONE),              /**< in without pull-up/down */
    GPIO_IN_PD = (PIN_DIR_IN | PIN_MODE_PD),                /**< in with pull-down */
    GPIO_IN_PU = (PIN_DIR_IN | PIN_MODE_PU),                /**< in with pull-up */
    GPIO_OUT   = (PIN_DIR_OUT | PIN_MODE_NONE),             /**< push-pull output */
    GPIO_OD    = (PIN_DIR_OUT | PIN_MODE_OD),               /**< open-drain output */
    GPIO_OD_PU = (PIN_DIR_OUT | PIN_MODE_OD | PIN_MODE_PU)  /**< open-drain output with pull-up */
} gpio_mode_t;
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CPU_H */
/** @} */
