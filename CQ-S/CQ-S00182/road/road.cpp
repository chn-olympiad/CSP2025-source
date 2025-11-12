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
#include <tuple>
constexpr int N = 1e4 + 15, M = 1e6 + 5, K = 10;
std::tuple<u32,u32,u32> ve[1<<K][N], *ep[1<<K];
std::tuple<u32,u32,u32> vv[K][N]; u64 cost[1<<K];
u32 fa[N];
fn u32 getf(u32 x){return fa[x]==x?x:fa[x]=getf(fa[x]); }
fv _ord(u32 n, std::tuple<u32, u32, u32> *f, std::tuple<u32, u32, u32> *e, std::tuple<u32, u32, u32>*&ep) {
  L(i, 1, n) fa[i] = i;
  F(auto i = f; i != e; ++i) {
    auto  [w,u,v ] = *i;
    if (getf(u) != getf(v)) { *ep++ = *i; fa[fa[u]] = fa[v]; }
  }
}
int main() {
  freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
  u32 n = ur(), m =ur(), k =ur(), u, v, w;
  static std::tuple<u32, u32, u32> v0[M]; auto ev = v0;
  U(i, 0, m) u= ur(), v = ur(), w = ur(), *ev++ ={ w, u, v };
  ep[0] = ve[0]; std::sort(v0, ev), _ord(n + k, v0, ev, ep[0]);
  U(i, 0,k) { cost[1<<i] = ur(); auto &v = vv[i]; L(j, 1, n) v[j-1] = { ur(), n +  i + 1, j }; std::sort(v, v + n); }
  U(i, 1 ,1<<k) {
    static std::tuple<u32, u32, u32> bf[N<<1];
    std::merge(ve[i & i-1], ep[i  & i-1], vv[__builtin_ctz(i)], vv[__builtin_ctz(i)] + n, bf);
    auto cur = bf + n + (ep[i & i-1] - ve[i & i-1]); ep[i]= ve[i];
    _ord(n + k, bf, cur, ep[i]);
    cost[i] = cost[i & i-1] + cost[i & -i];
  }
  u64 ans = -1ull;
  U(i, 0, 1<<k) { u64 val = cost[i]; F(auto j = ve[i]; j != ep[i]; ++j) val +=std::get<0>(*j); ans = std::min(ans, val); }
  std::cout << ans << '\n';
  return 0;
}
