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
constexpr int N = 2e5 + 5;
int main() {
  freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
  u32 t = ur();
  W(t--) {
    u32 n = ur(), a, b, c;
    static std::vector<u32> ve[3];
    u64 ans = 0;
    U(i, 0, n) {
      a = ur(), b = ur(), c = ur();
      if (a >= b && a >= c) {
        ans += a, ve[0].eb(a - std::max(b, c));
      } else if (b >= c) {
        ans += b, ve[1].eb(b - std::max(a, c));
      } else {
        ans += c, ve[2].eb(c - std::max(a, b));
      }
    }
    auto test = [&](auto &a) {
      if (a.size() <= n >> 1) { a.clear(); return; }
      std::sort(a.begin(), a.end(), std::greater<u32>());
      W(a.size() > n >> 1) ans -= a.back(), a.pop_back(); a.clear();
    };
    test(ve[0]), test(ve[1]), test(ve[2]);
    std::cout << ans << '\n';
  }
  return 0;
}
