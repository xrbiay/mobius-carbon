/*===---- asm.h - Assembler macros and defines -----------------------------===
 *
 * Part of the Carbon kernel, under the GNU GPL v3.0 license.
 * See https://www.gnu.org/licenses/gpl-3.0.en.html
 * for license inFormation.
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __i386_ASM_H_
#define __i386_ASM_H_

#ifdef __assembler__

// Entry macros
#   define LOC(x) x:
#   define GLOB(x) .globl x; x:
#   define FSYM(x) .section .text; .type x,@function;
#   define DSYM(x) .section .data; .type x,@object;
#   define AUOUT_SYM(x) _##x:

// ISR macros
// The error code is already pushed by the CPU
#   define ISR(x) \
  .align   4;\
  .globl isr_stub_##x; \
  .type isr_stub_##x,@function; \
  isr_stub_##x: ;\
  pushal;\
  cld;\
  call exstub;\
  popal;\
  iret;

#   define ISR_NO_EXCEPT(x) \
  .align   4;\
  .globl isr_stub_##x; \
  .type isr_stub_##x,@function; \
  isr_stub_##x: ;\
  pushal;\
  cld;\
  call exstub;\
  popal;\
  iret;

#else
// ignore for C/C++
#endif

#endif // __i386_ASM_H_