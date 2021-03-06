/**
    Copyright (C) powturbo 2013-2017
    GPL v2 License
  
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

    - homepage : https://sites.google.com/site/powturbo/
    - github   : https://github.com/powturbo
    - twitter  : https://twitter.com/powturbo
    - email    : powturbo [_AT_] gmail [_DOT_] com
**/
//    "Integer Compression" Turbo PforDelta 
#ifndef VP4_H_
#define VP4_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stddef.h>
//************************************************ High level API - n unlimited ****************************************************
// Compress integer array with n values to the buffer out. 
// Return value = number of bytes written to compressed buffer out
size_t p4nenc8(       uint8_t  *__restrict in, size_t n, unsigned char *__restrict out);
size_t p4nenc16(      uint16_t *__restrict in, size_t n, unsigned char *__restrict out);
size_t p4nenc32(      uint32_t *__restrict in, size_t n, unsigned char *__restrict out);
size_t p4nenc128v32(  uint32_t *__restrict in, size_t n, unsigned char *__restrict out); // SIMD (Vertical bitpacking)
size_t p4nenc256v32(  uint32_t *__restrict in, size_t n, unsigned char *__restrict out); 
size_t p4nenc64(      uint64_t *__restrict in, size_t n, unsigned char *__restrict out);

size_t p4ndenc8(      uint8_t  *__restrict in, size_t n, unsigned char *__restrict out);
size_t p4ndenc16(     uint16_t *__restrict in, size_t n, unsigned char *__restrict out);
size_t p4ndenc32(     uint32_t *__restrict in, size_t n, unsigned char *__restrict out);
size_t p4ndenc128v32( uint32_t *__restrict in, size_t n, unsigned char *__restrict out); 
size_t p4ndenc256v32( uint32_t *__restrict in, size_t n, unsigned char *__restrict out); 
size_t p4ndenc64(     uint64_t *__restrict in, size_t n, unsigned char *__restrict out);

size_t p4nd1enc8(     uint8_t  *__restrict in, size_t n, unsigned char *__restrict out);
size_t p4nd1enc16(    uint16_t *__restrict in, size_t n, unsigned char *__restrict out);
size_t p4nd1enc32(    uint32_t *__restrict in, size_t n, unsigned char *__restrict out);
size_t p4nd1enc128v32(uint32_t *__restrict in, size_t n, unsigned char *__restrict out); 
size_t p4nd1enc256v32(uint32_t *__restrict in, size_t n, unsigned char *__restrict out); 
size_t p4nd1enc64(    uint64_t *__restrict in, size_t n, unsigned char *__restrict out);

// Decompress the compressed n values in input buffer in to the integer array out. 
// Return value = number of bytes read from the ompressed buffer in
size_t p4ndec8(       unsigned char *__restrict in, size_t n, uint8_t  *__restrict out);
size_t p4ndec16(      unsigned char *__restrict in, size_t n, uint16_t *__restrict out);
size_t p4ndec32(      unsigned char *__restrict in, size_t n, uint32_t *__restrict out);  
size_t p4ndec128v32(  unsigned char *__restrict in, size_t n, uint32_t *__restrict out);  
size_t p4ndec256v32(  unsigned char *__restrict in, size_t n, uint32_t *__restrict out);  
size_t p4ndec64(      unsigned char *__restrict in, size_t n, uint64_t *__restrict out);

// Delta minimum = 0
size_t p4nddec8(      unsigned char *__restrict in, size_t n, uint8_t  *__restrict out);
size_t p4nddec16(     unsigned char *__restrict in, size_t n, uint16_t *__restrict out);
size_t p4nddec32(     unsigned char *__restrict in, size_t n, uint32_t *__restrict out);
size_t p4nddec128v32( unsigned char *__restrict in, size_t n, uint32_t *__restrict out); 
size_t p4nddec256v32( unsigned char *__restrict in, size_t n, uint32_t *__restrict out); 
size_t p4nddec64(     unsigned char *__restrict in, size_t n, uint64_t *__restrict out);
// Delta minimum = 1
size_t p4nd1dec8(     unsigned char *__restrict in, size_t n, uint8_t  *__restrict out);
size_t p4nd1dec16(    unsigned char *__restrict in, size_t n, uint16_t *__restrict out);
size_t p4nd1dec32(    unsigned char *__restrict in, size_t n, uint32_t *__restrict out);
size_t p4nd1dec128v32(unsigned char *__restrict in, size_t n, uint32_t *__restrict out); 
size_t p4nd1dec256v32(unsigned char *__restrict in, size_t n, uint32_t *__restrict out); 
size_t p4nd1dec64(    unsigned char *__restrict in, size_t n, uint64_t *__restrict out);


//************** Low level API - n limited to 128/256 ***************************************
#define P4D_MAX 256

// -------------- TurboPFor: Encode 
//#include <assert.h>
// Low level API: Single block n limited 
//compress integer array with n values to the buffer out. Return value = end of compressed buffer out
unsigned char *p4enc8(       uint8_t  *__restrict in, unsigned n, unsigned char *__restrict out);
unsigned char *p4enc16(      uint16_t *__restrict in, unsigned n, unsigned char *__restrict out);
unsigned char *p4enc32(      uint32_t *__restrict in, unsigned n, unsigned char *__restrict out);
unsigned char *p4enc128v32(  uint32_t *__restrict in, unsigned n, unsigned char *__restrict out); // SIMD (Vertical bitpacking)
unsigned char *p4enc256v32(  uint32_t *__restrict in, unsigned n, unsigned char *__restrict out); // SIMD (Vertical bitpacking)
unsigned char *p4enc64(      uint64_t *__restrict in, unsigned n, unsigned char *__restrict out);

unsigned char *p4encx8(      uint8_t  *__restrict in, unsigned n, unsigned char *__restrict out);// Direct access 
unsigned char *p4encx16(     uint16_t *__restrict in, unsigned n, unsigned char *__restrict out); 
unsigned char *p4encx32(     uint32_t *__restrict in, unsigned n, unsigned char *__restrict out);

unsigned char *p4denc8(      uint8_t  *__restrict in, unsigned n, unsigned char *__restrict out, uint8_t  start);
unsigned char *p4denc16(     uint16_t *__restrict in, unsigned n, unsigned char *__restrict out, uint16_t start);
unsigned char *p4denc32(     uint32_t *__restrict in, unsigned n, unsigned char *__restrict out, uint32_t start);
unsigned char *p4denc128v32( uint32_t *__restrict in, unsigned n, unsigned char *__restrict out, uint32_t start); // SIMD (Vertical bitpacking)
unsigned char *p4denc256v32( uint32_t *__restrict in, unsigned n, unsigned char *__restrict out, uint32_t start); 
unsigned char *p4denc64(     uint64_t *__restrict in, unsigned n, unsigned char *__restrict out, uint64_t start);

unsigned char *p4dencx8(     uint8_t  *__restrict in, unsigned n, unsigned char *__restrict out, uint8_t  start);// Direct access 
unsigned char *p4dencx16(    uint16_t *__restrict in, unsigned n, unsigned char *__restrict out, uint16_t start);
unsigned char *p4dencx32(    unsigned *__restrict in, unsigned n, unsigned char *__restrict out, uint32_t start);

unsigned char *p4d1enc8(     uint8_t  *__restrict in, unsigned n, unsigned char *__restrict out, uint8_t  start);
unsigned char *p4d1enc16(    uint16_t *__restrict in, unsigned n, unsigned char *__restrict out, uint16_t start);
unsigned char *p4d1enc32(    uint32_t *__restrict in, unsigned n, unsigned char *__restrict out, uint32_t start);
unsigned char *p4d1enc128v32(uint32_t *__restrict in, unsigned n, unsigned char *__restrict out, uint32_t start); // SIMD (Vertical bitpacking)
unsigned char *p4d1enc256v32(uint32_t *__restrict in, unsigned n, unsigned char *__restrict out, uint32_t start); 
unsigned char *p4d1enc64(    uint64_t *__restrict in, unsigned n, unsigned char *__restrict out, uint64_t start);

unsigned char *p4d1encx8(    uint8_t  *__restrict in, unsigned n, unsigned char *__restrict out, uint8_t  start);// Direct access 
unsigned char *p4d1encx16(   uint16_t *__restrict in, unsigned n, unsigned char *__restrict out, uint16_t start);
unsigned char *p4d1encx32(   uint32_t *__restrict in, unsigned n, unsigned char *__restrict out, uint32_t start);

// same as p4enc, but with b and bx as parameters. Call after _p4bitsXX
ALWAYS_INLINE unsigned char *_p4enc8(      uint8_t  *__restrict in, unsigned n, unsigned char *__restrict out, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4enc16(     uint16_t *__restrict in, unsigned n, unsigned char *__restrict out, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4enc32(     uint32_t *__restrict in, unsigned n, unsigned char *__restrict out, unsigned b, unsigned bx); 
ALWAYS_INLINE unsigned char *_p4enc128v32( uint32_t *__restrict in, unsigned n, unsigned char *__restrict out, unsigned b, unsigned bx); // SIMD (Vertical bitpacking)
ALWAYS_INLINE unsigned char *_p4enc256v32( uint32_t *__restrict in, unsigned n, unsigned char *__restrict out, unsigned b, unsigned bx); 
ALWAYS_INLINE unsigned char *_p4enc64(     uint64_t *__restrict in, unsigned n, unsigned char *__restrict out, unsigned b, unsigned bx);
// calculate the best bit sizes b and bx, return b. 
ALWAYS_INLINE unsigned _p4bits8(           uint8_t  *__restrict in, unsigned n, unsigned *pbx);
ALWAYS_INLINE unsigned _p4bits16(          uint16_t *__restrict in, unsigned n, unsigned *pbx);
ALWAYS_INLINE unsigned _p4bits32(          uint32_t *__restrict in, unsigned n, unsigned *pbx);
ALWAYS_INLINE unsigned _p4bits64(          uint64_t *__restrict in, unsigned n, unsigned *pbx);

#define P4EB(_b_) (_b_ << 1)
#define P4EBX(_b_, _bx_) (_bx_ << 8 | _b_ << 1 | 1) 
#define P4SAVE(_out_, _b_, _bx_) do { if(!_bx_) *_out_++ = P4EB(_b_);else *(uint16_t *)_out_ = P4EBX(_b_, _bx_), _out_ += 2; } while(0)

//********************************************** TurboPFor: Decode *****************************************************************************
//----TurboPFor low level API: single block. n limited to P4D_MAX -------------------------------------------------------
// decompress a previously (with p4enc32) 32/64 bits packed array. Return value = end of packed buffer in 
//-- scalar. (see p4getx32 for direct access)
// b and bx specified (not stored within the compressed stream header)
ALWAYS_INLINE unsigned char *_p4dec8(       unsigned char *__restrict in, unsigned n, uint8_t  *__restrict out, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4dec16(      unsigned char *__restrict in, unsigned n, uint16_t *__restrict out, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4dec32(      unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4dec128v32(  unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, unsigned b, unsigned bx); // SIMD (Vertical BitPacking)
ALWAYS_INLINE unsigned char *_p4dec64(      unsigned char *__restrict in, unsigned n, uint64_t *__restrict out, unsigned b, unsigned bx);

// 
unsigned char *p4dec8(        unsigned char *__restrict in, unsigned n, uint8_t  *__restrict out);
unsigned char *p4dec16(       unsigned char *__restrict in, unsigned n, uint16_t *__restrict out);
unsigned char *p4dec32(       unsigned char *__restrict in, unsigned n, uint32_t *__restrict out);  
unsigned char *p4dec128v32(   unsigned char *__restrict in, unsigned n, uint32_t *__restrict out);  // SIMD (Vertical BitPacking)
unsigned char *p4dec256v32(   unsigned char *__restrict in, unsigned n, uint32_t *__restrict out);  
unsigned char *p4dec64(       unsigned char *__restrict in, unsigned n, uint64_t *__restrict out);
//------ Delta decoding --------------------------- Return value = end of packed input buffer in ---------------------------
//-- Increasing integer lists. out[i] = out[i-1] + in[i]          	   
// b and bx specified
ALWAYS_INLINE unsigned char *_p4ddec8(      unsigned char *__restrict in, unsigned n, uint8_t  *__restrict out, uint8_t  start, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4ddec16(     unsigned char *__restrict in, unsigned n, uint16_t *__restrict out, uint16_t start, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4ddec32(     unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, uint32_t start, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4ddec128v32( unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, uint32_t start, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4ddec256v32( unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, uint32_t start, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4ddec64(     unsigned char *__restrict in, unsigned n, uint64_t *__restrict out, uint64_t start, unsigned b, unsigned bx);

// Low level: n limited to P4D_MAX
unsigned char *p4ddec8(       unsigned char *__restrict in, unsigned n, uint8_t  *__restrict out, uint8_t  start);
unsigned char *p4ddec16(      unsigned char *__restrict in, unsigned n, uint16_t *__restrict out, uint16_t start);
unsigned char *p4ddec32(      unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, uint32_t start);
unsigned char *p4ddec128v32(  unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, uint32_t start); // SIMD (Vertical BitPacking)
unsigned char *p4ddec256v32(  unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, uint32_t start); 
unsigned char *p4ddec64(      unsigned char *__restrict in, unsigned n, uint64_t *__restrict out, uint64_t start);

//-- Strictly increasing (never remaining constant or decreasing) integer lists. out[i] = out[i-1] + in[i] +  1
// b and bx specified (see idxcr.c/idxqry.c for an example)
ALWAYS_INLINE unsigned char *_p4d1dec8(     unsigned char *__restrict in, unsigned n, uint8_t  *__restrict out, uint8_t  start, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4d1dec16(    unsigned char *__restrict in, unsigned n, uint16_t *__restrict out, uint16_t start, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4d1dec32(    unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, uint32_t start, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4d1dec128v32(unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, uint32_t start, unsigned b, unsigned bx); // SIMD (Vertical BitPacking)
ALWAYS_INLINE unsigned char *_p4d1dec256v32(unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, uint32_t start, unsigned b, unsigned bx);
ALWAYS_INLINE unsigned char *_p4d1dec64(    unsigned char *__restrict in, unsigned n, uint64_t *__restrict out, uint64_t start, unsigned b, unsigned bx);

// Low level: n limited to P4D_MAX
unsigned char *p4d1dec8(      unsigned char *__restrict in, unsigned n, uint8_t  *__restrict out, uint8_t  start);
unsigned char *p4d1dec16(     unsigned char *__restrict in, unsigned n, uint16_t *__restrict out, uint16_t start);
unsigned char *p4d1dec32(     unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, uint32_t start);
unsigned char *p4d1dec128v32( unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, uint32_t start); // SIMD (Vertical BitPacking)
unsigned char *p4d1dec256v32( unsigned char *__restrict in, unsigned n, uint32_t *__restrict out, uint32_t start); 
unsigned char *p4d1dec64(     unsigned char *__restrict in, unsigned n, uint64_t *__restrict out, uint64_t start);

//---------------- Direct Access functions to compressed TurboPFor array p4encx16/p4encx32 -------------------------------------------------------
  #ifndef NTURBOPFOR_DAC
#define P4D_PAD8(_x_) 		( (((_x_)+8-1)/8) )
#define P4D_B(_x_)  		(((_x_) >> 1) & 0x3f)
#define P4D_XB(_x_)  		(((_x_) & 1)?((_x_) >> 8):0)
#define P4D_ININC(_in_, _x_) _in_ += 1+(_x_ & 1)

static inline unsigned p4bits(unsigned char *__restrict in, int *bx) { unsigned i = ctou16(in); *bx = P4D_XB(i); return P4D_B(i); }

struct p4 {
  unsigned long long *xmap;
  unsigned char *ex;
  unsigned i,bx,cum[P4D_MAX/64+1];
  int oval,idx;
};

static unsigned long long p4xmap[P4D_MAX/64+1] = { 0 };

// prepare direct access usage
static inline void p4ini(struct p4 *p4, unsigned char **pin, unsigned n, unsigned *b) { unsigned char *in = *pin;
  unsigned p4i = ctou16(in);
  p4->i      = p4i;
  *b         = P4D_B(p4i);
  p4->bx     = P4D_XB(p4i); 										  //assert(n <= P4D_MAX);
  *pin = p4->ex = ++in; 
  if(p4i&1) { ++in;
    p4->xmap = (unsigned long long *)in;
    unsigned num=0,j; 
    for(j=0; j < n/64; j++) { p4->cum[j] = num; num += popcnt64(ctou64(in+j*8)); } //p4->cum[j] = num; 
    if(n & 0x3f) num += popcnt64(ctou64(in+j*8) & ((1ull<<(n&0x3f))-1) );
    unsigned char *p;
    p4->ex = p = in + (n+7)/8;   				
    *pin   = p = p4->ex+((num*p4->bx+7)/8); 
  } else p4->xmap = p4xmap;
  p4->oval = p4->idx  = -1;
}

//---------- Get a single value with index "idx" from a "p4enc32" packed array
static ALWAYS_INLINE uint8_t p4getx8(struct p4 *p4, unsigned char *in, unsigned idx, unsigned b) { unsigned bi, cl, u = _bitgetx8(in, idx*b, b);
  if(/*(*p4->i&1) &&*/ unlikely(p4->xmap[bi = idx>>6] & (1ull<<(cl = (idx & 0x3f))))) u |= _bitgetx8(p4->ex, (p4->cum[bi] + popcnt64(p4->xmap[bi] & ~((~0ull)<<cl)))*p4->bx, p4->bx ) << b;
  return u;
}

static ALWAYS_INLINE uint16_t p4getx16(struct p4 *p4, unsigned char *in, unsigned idx, unsigned b) { unsigned bi, cl, u = _bitgetx16(in, idx*b, b);
  if(/*(*p4->i&1) &&*/ unlikely(p4->xmap[bi = idx>>6] & (1ull<<(cl = (idx & 0x3f))))) u |= _bitgetx16(p4->ex, (p4->cum[bi] + popcnt64(p4->xmap[bi] & ~((~0ull)<<cl)))*p4->bx, p4->bx ) << b;
  return u;
}
static ALWAYS_INLINE uint32_t p4getx32(struct p4 *p4, unsigned char *in, unsigned idx, unsigned b) { unsigned bi, cl, u = _bitgetx32(in, idx*b, b),bx=p4->bx;																
  if(/*(p4->i&1) &&*/ unlikely(p4->xmap[bi = idx>>6] & (1ull<<(cl = (idx & 0x3f))))) u |= _bitgetx32(p4->ex, (p4->cum[bi] + popcnt64(p4->xmap[bi] & ~((~0ull)<<cl)))*bx, p4->bx ) << b;
  return u;
}

// Get the next single value greater of equal to val
static ALWAYS_INLINE uint16_t p4geqx16(struct p4 *p4, unsigned char *in, unsigned b, uint16_t val) { do p4->oval += p4getx16(p4, in, ++p4->idx, b)+1; while(p4->oval < val); return p4->oval; }
static ALWAYS_INLINE uint32_t p4geqx32(struct p4 *p4, unsigned char *in, unsigned b, unsigned       val) { do p4->oval += p4getx32(p4, in, ++p4->idx, b)+1; while(p4->oval < val); return p4->oval; }
//static ALWAYS_INLINE uint64_t       p4geq64(struct p4 *p4, unsigned char *__restrict in, unsigned b, uint64_t       val) { do p4->oval += p4getx64(p4, in, ++p4->idx, b)+1; while(p4->oval < val); return p4->oval; }
 
/* DO NOT USE : like p4dec32 but using direct access. This is only a demo showing direct access usage. Use p4dec32 instead for decompressing entire blocks */
unsigned char *p4decx32(  unsigned char *in, unsigned n, unsigned *out);  // unsorted
unsigned char *p4f0decx32(unsigned char *in, unsigned n, unsigned *out, unsigned start); // FOR increasing 
unsigned char *p4fdecx32( unsigned char *in, unsigned n, unsigned *out, unsigned start); // FOR strictly increasing
  #endif

#ifdef __cplusplus
}
#endif

#endif

