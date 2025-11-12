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
#define g0 std::get<0>
#define g1 std::get<1>
#define g2 std::get<2>
#define g3 std::get<3>
constexpr int N = 2.5e6  +5, Q = 2e5 + 5, Z =26;
u32 zz[N]; std::vector<std::pair<u32, u32> > gf[N];
struct ac_automaton {
  u32 sn[Z][N], dfn[N], ri[N], fa[N], tot, cnt, len[N];
  std::vector<u32>G[N];
  fv clr() { U(i, 0, Z) mset(sn[i], 0x00,tot + 1<< 2); mset(dfn, 0x00,tot + 1 <<2),mset(ri, 0x00, tot+ 1 << 2), mset(fa, 0x00, tot + 1 << 2), cnt = tot = 0, mset(len, 0x00, tot + 1 << 2); }
  u32 ins(char *f) {
    u32 x = 0, c, l = 0;
    W(*f) {
      c = *f++ - 'a', ++l;
      if (!sn[c][x]) sn[c][x] = ++tot, len[tot] = l;
      x = sn[c][x];
    }
    return x;
  }
  fv build() {
    static u32 q[N]; auto f = q, e = q;
    U(i, 0, Z) if (sn[i][0]) *e++ = sn[i][0];
    u32 x, y;
    W(f != e) {
      x = *f++;
      U(i, 0, Z) {
        ((y = sn[i][x]) ? fa[*e++ = y] : sn[i][x]) = sn[i][fa[x]];
        // fa[*e++ = y] = sn[i][fa[x]];
      } // else { sn[i][x] = sn[i][fa[x]]; }
    }
    L(i, 1, tot) G[fa[i]].eb(i);
  }
  fv dfs(u32 x) { dfn[x] = cnt++; F(const u32 &y : G[x]) dfs(y); ri[dfn[x]] = cnt; }
} S, T;
std::pair<u32,u32> _stk[N], *_tp = _stk;
fv dfs1(u32 x) {
  *_tp++ = {S.len[x],x};
  F(const auto&[d,id] : gf[x]) {
    zz[id] = std::lower_bound(_stk, _tp, std::pair<u32, u32> { d, 0 })[-1].se;
  }
  F(const u32 &y : S.G[x]) dfs1(y);
  --_tp;
}
struct BIT { // maybe cube(x)?
  u32 a[N];
  fv add(u32 x) { W(x < N) ++a[x], x += x & -x;}
  fv sub(u32 x) { W(x < N) --a[x], x += x & -x;}
  u32 qry(u32 x)const {u32 r=a[x];W(x&=x-1)r += a[x];return r;}
} tr;
u32 ans[Q];
int main() {
  freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
  u32 n, q ; std::cin >> n >> q;
  static char s[N], t[N];
  static std::pair<u32, u32> vv[Q];
  U(i, 0, n) std::cin >> s >> t, vv[i] = { S.ins(s), T.ins(t) }; // std::cerr << vv[i].fi << ' ' << vv[i].se << '\n';
  // std::cerr << "--\n";
  S.build(), S.dfs(0);
  T.build(), T.dfs(0);
  static std::vector<u32> ad[N], dl[N];
  static std::vector<std::pair<u32, u32> > qy[N];
  U(i, 0, n) {
    const u32 a = S.dfn[vv[i].fi], b = T.dfn[vv[i].se], c = S.ri[a], d =T.ri[b];
    ad[a].eb(b), dl[c].eb(b), dl[a].eb(d), ad[c].eb(d);
  }
  static std::tuple<u32, u32, u32, u32> *z[Q], h[N], *tp = h;
  U(i, 0, q) {
    std::cin >> s >> t;
    const u32 l0 =  __builtin_strlen(s), l1 = __builtin_strlen(t);
    if (l0 != l1)continue; u32 p = l0, q = 0;
    W(s[p-1] == t[p-1]) --p;
    W(s[q] == t[q]) ++q;
    u32 a = 0, b = 0;
    z[i] = tp;
    L(h, 1, l0) {
      a = S.sn[s[h-1]-'a'][a], b = T.sn[t[h-1]-'a'][b];
      // std::cerr << a << ' ' << b << ' ' << (h >= p)<< ' ' << h-q << '\n';
      if (h >= p) *tp++ = { a, b, h - q, i };
    }
  }
  z[q] = tp;
  const u32 sz = tp - h;
  U(i, 0, sz) gf[g0(h[i])].eb(g2(h[i]), i);
  dfs1(0);
  U(i, 0, sz) if (zz[i] != g0(h[i])) {
    //std::cerr << g0(h[i]) << ' ' << zz[i] << ' ' << g1(h[i]) << '\n';
    qy[S.dfn[g0(h[i])]].eb(T.dfn[g1(h[i])], g3(h[i]));
    qy[S.dfn[zz[i]]].eb(-T.dfn[g1(h[i])], g3(h[i]));
  }
  L(i, 1, S.tot) {
    F(const u32 &y : ad[i]) tr.add(y);
    F(const u32 &y : dl[i]) tr.sub(y);
    F(const auto &[v, id] : qy[i]) if ((int)v < 0) {
      ans[id] -= tr.qry(-v);
    } else {
      ans[id] += tr.qry(v);
    }
  }
  U(i, 0, q) std::cout << ans[i] << '\n';
  return 0;
}
