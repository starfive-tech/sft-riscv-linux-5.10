/*
 ******************************************************************************
 * @file  starfive-vic-rng.h
 * @author  StarFive Technology
 * @version  V1.0
 * @date  08/13/2020
 * @brief
 ******************************************************************************
 * @copy
 *
 * THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, STARFIVE SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * COPYRIGHT 2020 Shanghai StarFive Technology Co., Ltd.
 */

#define VIC_CTRL		0x00
#define VIC_MODE		0x04
#define VIC_SMODE		0x08
#define VIC_STAT		0x0C
#define VIC_IE			0x10
#define VIC_ISTAT		0x14
#define VIC_ALARM		0x18
#define VIC_BUILD_ID		0x1C
#define VIC_FEATURES		0x20
#define VIC_RAND0		0x24
#define VIC_NPA_DATA0		0x34
#define VIC_SEED0		0x74
#define VIC_IA_RDATA		0xA4
#define VIC_IA_WDATA		0xA8
#define VIC_IA_ADDR		0xAC
#define VIC_IA_CMD		0xB0

/* CTRL */
#define VIC_CTRL_CMD_NOP		0
#define VIC_CTRL_CMD_GEN_NOISE		1
#define VIC_CTRL_CMD_GEN_NONCE		2
#define VIC_CTRL_CMD_CREATE_STATE	3
#define VIC_CTRL_CMD_RENEW_STATE	4
#define VIC_CTRL_CMD_REFRESH_ADDIN	5
#define VIC_CTRL_CMD_GEN_RANDOM		6
#define VIC_CTRL_CMD_ADVANCE_STATE	7
#define VIC_CTRL_CMD_KAT		8
#define VIC_CTRL_CMD_ZEROIZE		15

/* MODE */
#define _VIC_MODE_ADDIN_PRESENT		4
#define _VIC_MODE_PRED_RESIST		3
#define _VIC_MODE_KAT_SEL		2
#define _VIC_MODE_KAT_VEC		1
#define _VIC_MODE_SEC_ALG		0

#define VIC_MODE_ADDIN_PRESENT	(1UL << _VIC_MODE_ADDIN_PRESENT)
#define VIC_MODE_PRED_RESIST	(1UL << _VIC_MODE_PRED_RESIST)
#define VIC_MODE_KAT_SEL	(1UL << _VIC_MODE_KAT_SEL)
#define VIC_MODE_KAT_VEC	(1UL << _VIC_MODE_KAT_VEC)
#define VIC_MODE_SEC_ALG	(1UL << _VIC_MODE_SEC_ALG)

/* SMODE */
#define _VIC_SMODE_MAX_REJECTS	2
#define _VIC_SMODE_SECURE_EN	1
#define _VIC_SMODE_NONCE	0

#define VIC_SMODE_MAX_REJECTS(x)	((x) << _VIC_SMODE_MAX_REJECTS)
#define VIC_SMODE_SECURE_EN(x)		((x) << _VIC_SMODE_SECURE_EN)
#define VIC_SMODE_NONCE			(1UL << _VIC_SMODE_NONCE)

/* STAT */
#define _VIC_STAT_BUSY		31
#define _VIC_STAT_DRBG_STATE	7
#define _VIC_STAT_SECURE	6
#define _VIC_STAT_NONCE_MODE	5
#define _VIC_STAT_SEC_ALG	4
#define _VIC_STAT_LAST_CMD	0

#define VIC_STAT_BUSY		(1UL << _VIC_STAT_BUSY)
#define VIC_STAT_DRBG_STATE	(1UL << _VIC_STAT_DRBG_STATE)
#define VIC_STAT_SECURE		(1UL << _VIC_STAT_SECURE)
#define VIC_STAT_NONCE_MODE	(1UL << _VIC_STAT_NONCE_MODE)
#define VIC_STAT_SEC_ALG	(1UL << _VIC_STAT_SEC_ALG)
#define VIC_STAT_LAST_CMD(x)	(((x) >> _VIC_STAT_LAST_CMD) & 0xF)

/* IE */
#define _VIC_IE_GLBL		31
#define _VIC_IE_DONE		4
#define _VIC_IE_ALARMS		3
#define _VIC_IE_NOISE_RDY	2
#define _VIC_IE_KAT_COMPLETE	1
#define _VIC_IE_ZEROIZE		0

#define VIC_IE_GLBL		(1UL << _VIC_IE_GLBL)
#define VIC_IE_DONE		(1UL << _VIC_IE_DONE)
#define VIC_IE_ALARMS		(1UL << _VIC_IE_ALARMS)
#define VIC_IE_NOISE_RDY	(1UL << _VIC_IE_NOISE_RDY)
#define VIC_IE_KAT_COMPLETE	(1UL << _VIC_IE_KAT_COMPLETE)
#define VIC_IE_ZEROIZE		(1UL << _VIC_IE_ZEROIZE)
#define VIC_IE_ALL		(VIC_IE_GLBL | VIC_IE_DONE | VIC_IE_ALARMS | \
				 VIC_IE_NOISE_RDY | VIC_IE_KAT_COMPLETE | VIC_IE_ZEROIZE)

/* ISTAT */
#define _VIC_ISTAT_DONE		4
#define _VIC_ISTAT_ALARMS	3
#define _VIC_ISTAT_NOISE_RDY	2
#define _VIC_ISTAT_KAT_COMPLETE	1
#define _VIC_ISTAT_ZEROIZE	0

#define VIC_ISTAT_DONE		(1UL << _VIC_ISTAT_DONE)
#define VIC_ISTAT_ALARMS	(1UL << _VIC_ISTAT_ALARMS)
#define VIC_ISTAT_NOISE_RDY	(1UL << _VIC_ISTAT_NOISE_RDY)
#define VIC_ISTAT_KAT_COMPLETE	(1UL << _VIC_ISTAT_KAT_COMPLETE)
#define VIC_ISTAT_ZEROIZE	(1UL << _VIC_ISTAT_ZEROIZE)

/* ALARMS */
#define VIC_ALARM_ILLEGAL_CMD_SEQ			(1UL << 4)
#define VIC_ALARM_FAILED_TEST_ID_OK			0
#define VIC_ALARM_FAILED_TEST_ID_KAT_STAT		1
#define VIC_ALARM_FAILED_TEST_ID_KAT			2
#define VIC_ALARM_FAILED_TEST_ID_MONOBIT		3
#define VIC_ALARM_FAILED_TEST_ID_RUN			4
#define VIC_ALARM_FAILED_TEST_ID_LONGRUN		5
#define VIC_ALARM_FAILED_TEST_ID_AUTOCORRELATION	6
#define VIC_ALARM_FAILED_TEST_ID_POKER			7
#define VIC_ALARM_FAILED_TEST_ID_REPETITION_COUNT	8
#define VIC_ALARM_FAILED_TEST_ID_ADAPATIVE_PROPORTION	9

/* BUILD_ID */
#define VIC_BUILD_ID_STEPPING(x)		(((x) >> 28) & 0xF)
#define VIC_BUILD_ID_EPN(x)			((x) & 0xFFFF)

/* FEATURES */
#define VIC_FEATURES_AES_256(x)			(((x) >> 9) & 1)
#define VIC_FEATURES_EXTRA_PS_PRESENT(x)	(((x) >> 8) & 1)
#define VIC_FEATURES_DIAG_LEVEL_NS(x)		(((x) >> 7) & 1)
#define VIC_FEATURES_DIAG_LEVEL_CLP800(x)	(((x) >> 4) & 7)
#define VIC_FEATURES_DIAG_LEVEL_ST_HLT(x)	(((x) >> 1) & 7)
#define VIC_FEATURES_SECURE_RST_STATE(x)	((x) & 1)

/* IA_CMD */
#define VIC_IA_CMD_GO			(1UL << 31)
#define VIC_IA_CMD_WR			(1)

#define _VIC_SMODE_MAX_REJECTS_MASK	255UL
#define _VIC_SMODE_SECURE_EN_MASK	1UL
#define _VIC_SMODE_NONCE_MASK		1UL
#define _VIC_MODE_SEC_ALG_MASK		1UL
#define _VIC_MODE_ADDIN_PRESENT_MASK	1UL
#define _VIC_MODE_PRED_RESIST_MASK	1UL

#define VIC_SMODE_SET_MAX_REJECTS(y, x)	(((y) & ~(_VIC_SMODE_MAX_REJECTS_MASK << _VIC_SMODE_MAX_REJECTS)) | ((x) << _VIC_SMODE_MAX_REJECTS))
#define VIC_SMODE_SET_SECURE_EN(y, x)	(((y) & ~(_VIC_SMODE_SECURE_EN_MASK   << _VIC_SMODE_SECURE_EN))   | ((x) << _VIC_SMODE_SECURE_EN))
#define VIC_SMODE_SET_NONCE(y, x)	(((y) & ~(_VIC_SMODE_NONCE_MASK       << _VIC_SMODE_NONCE))       | ((x) << _VIC_SMODE_NONCE))
#define VIC_SMODE_GET_MAX_REJECTS(x)	(((x) >> _VIC_SMODE_MAX_REJECTS) & _VIC_SMODE_MAX_REJECTS_MASK)
#define VIC_SMODE_GET_SECURE_EN(x)	(((x) >> _VIC_SMODE_SECURE_EN)   & _VIC_SMODE_SECURE_EN_MASK)
#define VIC_SMODE_GET_NONCE(x)		(((x) >> _VIC_SMODE_NONCE)       & _VIC_SMODE_NONCE_MASK)

#define VIC_MODE_SET_SEC_ALG(y, x)	(((y) & ~(_VIC_MODE_SEC_ALG_MASK       << _VIC_MODE_SEC_ALG))	| ((x) << _VIC_MODE_SEC_ALG))
#define VIC_MODE_SET_PRED_RESIST(y, x)	(((y) & ~(_VIC_MODE_PRED_RESIST_MASK   << _VIC_MODE_PRED_RESIST))    | ((x) << _VIC_MODE_PRED_RESIST))
#define VIC_MODE_SET_ADDIN_PRESENT(y, x) (((y) & ~(_VIC_MODE_ADDIN_PRESENT_MASK << _VIC_MODE_ADDIN_PRESENT))  | ((x) << _VIC_MODE_ADDIN_PRESENT))
#define VIC_MODE_GET_SEC_ALG(x)		(((x) >> _VIC_MODE_SEC_ALG)       & _VIC_MODE_SEC_ALG_MASK)
#define VIC_MODE_GET_PRED_RESIST(x)	(((x) >> _VIC_MODE_PRED_RESIST)   & _VIC_MODE_PRED_RESIST_MASK)
#define VIC_MODE_GET_ADDIN_PRESENT(x)	(((x) >> _VIC_MODE_ADDIN_PRESENT) & _VIC_MODE_ADDIN_PRESENT_MASK)

#define VIC_RAND_LEN 4
