/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  long Funct(long arg1, long arg2, ...) {
      /* brief description of how your implementation works */
      long var1 = Expr1;
      ...
      long varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. (Long) integer constants 0 through 255 (0xFFL), inclusive. You are
      not allowed to use big constants such as 0xffffffffL.
  3. Function arguments and local variables (no global variables).
  4. Local variables of type int and long
  5. Unary integer operations ! ~
     - Their arguments can have types int or long
     - Note that ! always returns int, even if the argument is long
  6. Binary integer operations & ^ | + << >>
     - Their arguments can have types int or long
  7. Casting from int to long and from long to int
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting other than between int and long.
  7. Use any data type other than int or long.  This implies that you
     cannot use arrays, structs, or unions.
 
  You may assume that your machine:
  1. Uses 2s complement representations for int and long.
  2. Data type int is 32 bits, long is 64.
  3. Performs right shifts arithmetically.
  4. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31 (int) or 63 (long)

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 63
   */
  long pow2plus1(long x) {
     /* exploit ability of shifts to compute powers of 2 */
     /* Note that the 'L' indicates a long constant */
     return (1L << x) + 1L;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 63
   */
  long pow2plus4(long x) {
     /* exploit ability of shifts to compute powers of 2 */
     long result = (1L << x);
     result += 4L;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
//1
/*
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and &
 *   Example: bitMatch(0x7L, 0xEL) = 0xFFFFFFFFFFFFFFF6L
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
long bitMatch(long x, long y) {
  long result=(~(~x&y))&(~(~y&x));
  return result;
}
//2
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Examples:
 *     copyLSB(5L) = 0xFFFFFFFFFFFFFFFFL,
 *     copyLSB(6L) = 0x0000000000000000L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
long copyLSB(long x) {
  long result;
   result=x<<63;
   result=result>>63;
  return result;
}
/*
 * distinctNegation - returns 1 if x != -x.
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 5
 *   Rating: 2
 */
long distinctNegation(long x) {
  	long negation=~x+1;
    long result=!(!(x^negation));
    return result;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96L) = 0x20L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
long leastBitPos(long x) {
  long nagetive=~x;
  long leastBit=nagetive+1;
    
  return leastBit&x;
}
/* 
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 62
 *  Round toward zero
 *   Examples: dividePower2(15L,1L) = 7L, dividePower2(-33L,4L) = -2L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
long dividePower2(long x, long n) {
    long sign=x>>63;
    return ((~sign)&(x>>n))|((sign)&((x+(1L<<n)+(~0) )>>n));
}
//3
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4L,5L) = 4L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
long conditional(long x, long y, long z) {
  	long mask = !!(x);
    	mask=(mask<<63)>>63;
    	return ((~mask)&z)|((mask)&y);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4L,5L) = 1L.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
long isLessOrEqual(long x, long y) {
  long signOfx=(x>>63)&1;
    long signOfy=(y>>63)&1;
    long sameSign=!(signOfx^signOfy);//1->same; 0->diff
    return ((sameSign)&(!((y+(~x+1))>>63)))|((~sameSign)&(signOfx)) ;
}
//4
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples:
 *    trueThreeFourths(11L) = 8
 *    trueThreeFourths(-9L) = -6
 *    trueThreeFourths(4611686018427387904L) = 3458764513820540928L (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
long trueThreeFourths(long x)
{
    long twoDigit=x&0x3L;
    //as if we get a x could be integer divide by 4, thus, we can derectly divide by 4 without rounding. 
    long xDividsTwo=x>>2;
    
    long x_d_mul3=xDividsTwo+xDividsTwo+xDividsTwo;
    long xSign=x>>63;//All 111111..if nagetive ; 000000...if positive.
    //same algrothrim as dividepowerof2, if x is nagetive , we should add (1<<n -1) to x to make x round toward 0.

    long remainder= ((twoDigit+twoDigit+twoDigit)+(xSign&((1L<<2)+(~0))))>>2;
    return x_d_mul3+remainder;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5L) = 2, bitCount(7L) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
long bitCount(long x) {
	
	long mask1=0xFFL;
    long mask2;
    long mask3;
    long mask4;
    long mask5;
    long mask6;
    long count;

    mask1=mask1|(mask1<<8);
    mask1=mask1|(mask1<<16);
    
    mask2=mask1^(mask1<<16);
    mask3=mask2^(mask2<<8);
    mask4=mask3^(mask3<<4);
    mask5=mask4^(mask4<<2);
    mask6=mask5^(mask5<<1);
    
    
    count=(mask6&x)+(mask6&(x>>1));
    //printf("%d\n",count);
    count=(count&mask5)+((count>>2)&mask5);
    //printf("%d\n",count);
    count=(count&mask4)+((count>>4)&mask4);
    //printf("%d\n",count);
    count=(count&mask3)+((count>>8)&mask3);
    //printf("%d\n",count);
    count=(count&mask2)+((count>>16)&mask2);
    //printf("%d\n",count);
    count=(count&mask1)+((count>>32)&mask1);
    //printf("%d\n",count);
    return count;
}
/*
 * isPalindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPalindrome(0x6F0F0123c480F0F6L) = 1L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
long isPalindrome(long x) {
    long mask1=0xFFL;
    long mask2;
    long mask3;
    long mask4;
    long mask5;
    long mask6;
    long swap1;
    long swap2;
    long swap3;
    long swap4;
    long swap5;
    long swap6;

	mask1=mask1|(mask1<<8);
	mask1=mask1|(mask1<<16);
	mask2=mask1^(mask1<<16);
	mask3=mask2^(mask2<<8);
	mask4=mask3^(mask3<<4);
	mask5=mask4^(mask4<<2);
	mask6=mask5^(mask5<<1);
    
    swap1=((x>>32)&mask1)|(x<<32);
    swap2=((swap1>>16)&(mask2))|((swap1<<16)&(~mask2));
    swap3=((swap2>>8)&(mask3))|((swap2<<8)&(~mask3));
    swap4=((swap3>>4)&(mask4))|((swap3<<4)&(~mask4));
    swap5=((swap4>>2)&(mask5))|((swap4<<2)&(~mask5));
    swap6=((swap5>>1)&(mask6))|((swap5<<1)&(~mask6));
    
    return !(swap6^x);
}
/*
 * integerLog2 - return floor(log base 2 of x), where x > 0
 *   Example: integerLog2(16L) = 4L, integerLog2(31L) = 4L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 60
 *   Rating: 4
 */
long integerLog2(long x) {
    long result;
    result=(!!(x>>32))<<5;
    result+=(!!(x>>(16+result)))<<4;
    result+=(!!(x>>(8+result)))<<3;
    result+=(!!(x>>(4+result)))<<2;
    result+=(!!(x>>(2+result)))<<1;
    result+=(!!(x>>(1+result)));
    return result;
}
//float
/* 
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug) {
    int mask1=0x7F;
    int mask2=0x7F;
    mask1=(mask1<<8)|0xFF;
    mask1=(mask1<<8)|0xFF;
    mask1=(mask1<<8)|0xFF;
    
    
    mask2=(mask2<<8)|0x80;
    mask2=mask2<<16;
    return (!(uf^ug)||((((uf<<1)|0)==0)&&(((ug<<1)|0)==0)))&&((uf&mask1)<=mask2)&&((ug&mask1)<=mask2);
}
/* 
 * floatScale4 - Return bit-level equivalent of expression 4*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale4(unsigned uf) {
    int count=2;
    int mask1=0x7F;
    int mask2=0x7F;
    int mask3=0x1<<31;//0x1000000000000000....
    int mask4=0x1<<23;//0x0000000010000000....
    
    mask1=(mask1<<8)|0xFF;
    mask1=(mask1<<8)|0xFF;
    mask1=(mask1<<8)|0xFF;//0x7fffffff
    
    mask2=(mask2<<8)|0x80;
    mask2=mask2<<16;//0x011111110000000..
    if ((uf&mask1)>mask2){
        return uf;
    }
    
    while (count>0){
    		
        if (!!(uf&mask2)){
            //if full do nothing.
            if ((uf&mask2)!=mask2){//not full
            	 
                uf+=mask4;
            }
        }else {
            uf=(uf&mask3)|(uf<<1);
        }
        
 
        count--;
        if (((uf&mask2)==mask2)){
        	//check if uf becomes a inf number and eliminate the digit in siginificand.
            	uf=uf&(mask2|mask3);
        	}
    }
    
    return uf;
}
/* 
 * floatUnsigned2Float - Return bit-level equivalent of expression (float) u
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatUnsigned2Float(unsigned u) {
    int count=-1;
    int mark1=1<<31;
    int temp=u;
    int bias=127;
    int exp;
    int siginificant_diff_expo;
    int G;
    int R;
    int S;
    int increment;
    int shift;
    
    if (!!(u&mark1)){
        count =31;
    }
    while(temp>0){
        temp=temp>>1;
        count++;
    }
    if (count==-1){
        return 0;
    }
    exp=bias+count;
    siginificant_diff_expo=23-count;
    if (count<23){
        return (exp<<23)|((u<<siginificant_diff_expo)&0x7FFFFF);
    }else{
        siginificant_diff_expo=-siginificant_diff_expo;
        G=u&(1<<siginificant_diff_expo);
        R=u&(1<<(siginificant_diff_expo-1));
        shift=33-siginificant_diff_expo;
        
        S=u<<(shift);//check if the rest digit contain 1 or not.
        u=u>>siginificant_diff_expo;
	   
	   if (shift>=32)
        	   S=0;

        increment=(G||S)&&R;
        
        //printf("%d",u^(0x7FFFFF));
        if ((((u&0x7FFFFF)^(0x7FFFFF))==0)&&increment){
        	  //printf("hihihihihih");
            exp+=1;
        }
       //printf("%d",increment);
        
        u+=increment;
        
        //printf("%d\n",G);
        
        //printf("%d\n",S);
	   
        return (exp<<23)|(u&0x7FFFFF);
    }
}

