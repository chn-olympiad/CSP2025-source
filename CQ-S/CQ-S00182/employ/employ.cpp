#include<vector>//{{{
#include<iostream>
#include<algorithm>
#define F for
#define W while
#define fi first
#define se second
#define fv inline void
#define eb emplace_back
#define fn inline static
#define gc getchar_unlocked
#define mset __builtin_memset
#define mcpy __builtin_memcpy
#define mmov __builtin_memmove
#define U(i,a,b) F(int i=(a);i<(int)(b);++i)
#define L(i,a,b) F(int i=(a);i<=(int)(b);++i)
#define R(i,a,b) F(int i=(a);i>=(int)(b);--i)
using u8=unsigned char;using u16=unsigned short;using u32=unsigned;using u64=unsigned long long;using u128=__uint128_t;using i8=char;using i16=short;using i64=long long;using i128=__int128_t; template<typename T=u32>fn T ur(){u32 c;W(!__builtin_isdigit(c=gc()));T r=c&15;W(__builtin_isdigit(c=gc()))r=(r<<3)+(r<<1)+(c&15);return r;}template<typename T=int>fn T sr(){u32 c;bool x=false;W(!__builtin_isdigit(c=gc()))x=c=='-';T r=c&15;W(__builtin_isdigit(c=gc()))r=(r<<3)+(r<<1)+(c&15);return x?-r:r;}//}}}
constexpr int N = 15;
int main() {
  freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
  u32 n = ur(), m = ur();
  static char s[N];
  std::cin >> s;
  static u32 c[N];
  U(i, 0, n) std::cin >> c[i];
  static u32 p[10];
  U(i, 0, n) {
    p[i] = i;
  }
  static u32 ps[N];
  u32 tot = 0;
  U(i, 0, n) if(s[i] == '1') ps[i] = tot++;
  static u32 hlp[1<<N];
  do {
    u32 cnt = 0, vv = 0;
    U(i, 0, n) {
      if (s[i] == '0' || cnt >= c[p[i]]) {
        ++cnt;
      } else {
        vv |= 1<<ps[i];
      }
    }
    ++hlp[vv];
  } W(std::next_permutation(p, p + n));
  u32 ans = 0;
  U(i, 0, 1<<tot) if (__builtin_popcount(i) >= m)
  // std::cerr << hlp[i] << ' ', ans += hlp[i];
  ans += hlp[i];
  std::cout <<ans;
  return 0;
}
