#include<bits/stdc++.h>
#include<bits/extc++.h>
using ll = long long; using ull = unsigned long long;
#define ld std::cin
#define jyt std::cout
#define cmd std::cerr
#define REQ(i, l, r) for (int i = l; i <  r; ++i)
#define REP(i, l, r) for (int i = l; i <= r; ++i)
#define PER(i, l, r) for (int i = l; i >= r; --i)
namespace JoKing {
   const int N = 500 + 7;
   const int inf = 1e9 + 7;
   const int P = 998244353;
   int n, m, cnt0, cnt1, a[N], cnt[N], pcnt[N]; ll f[102][102][102], fac[N], inv[N];
   inline ll qpow(ll X, ll Y) {ll R = 1; for (; Y; (X *= X) %= P, Y >>= 1ll) if (Y & 1ll) (R *= X) %= P; return R;}
   inline ll C(int X, int Y) {return X < Y ? 0ll : fac[X] * inv[Y] % P * inv[X - Y] % P;}
   std::string S;
   signed main() {
      ld >> n >> m >> S, S = " " + S + "0", fac[0] = 1;
      REP(i, 1, 502) fac[i] = fac[i - 1] * i % P;
      inv[502] = qpow(fac[502], P - 2);
      PER(i, 502, 1) inv[i - 1] = inv[i] * i % P;
      REP(i, 1, n) cnt0 += (S[i] == '0'), cnt1 += (S[i] == '1');
      REP(i, 1, n) ld >> a[i], ++cnt[a[i]];
      pcnt[0] = cnt[0];
      REP(i, 1, n) pcnt[i] = pcnt[i - 1] + cnt[i];
      int pre0 = 0, pre1 = 0;
      if (S[1] == '0') {
         ++pre0;
         f[1][1][0] = 1;
      } else {
         ++pre1;
         f[1][0][1] = 1;
         f[1][1][0] = pcnt[0];
      }
      REP(i, 2, n) {
         if (S[i] == '0') {
            REP(j, 1, i) REP(k, 0, pre1) {
               ll fvv = 0;
               PER(other, i, 2) {
                  if (k < (i - other)) break;
                  ll Res = f[other - 1][j - 1][k - (i - other)];
                  (fvv += Res) %= P;
                  if (S[other - 1] == '0') break;
               }
               REP(other, 0, k) (f[i][j][k - other] += 1ll * fvv * C(k, other) % P * C(cnt[j], other) % P * fac[other] % P) %= P;
            }
         } else if (S[i] == '1') {
            REP(j, 1, i) REP(k, 0, pre1) {
               ll fvv = 0;
               PER(other, i, 2) {
                  if (k < (i - other)) break;
                  ll Res = f[other - 1][j - 1][k - (i - other)] * std::max(0, pcnt[j - 1] - (pre1 - k)) % P;
                  (fvv += Res) %= P;
                  if (S[other - 1] == '0') break;
               }
               REP(other, 0, k) (f[i][j][k - other] += 1ll * fvv * C(k, other) % P * C(cnt[j], other) % P * fac[other] % P) %= P;
            }
         }
         pre0 += (S[i] == '0');
         pre1 += (S[i] == '1');
      }
      ll Ans = 0;
      PER(i, n, 1) {
         REP(j, 0, n - m) REP(k, 0, n) if (f[i][j][k]) 
            (Ans += f[i][j][k] * C(pcnt[n] - pcnt[j], k + n - i) % P * fac[k + n - i] % P) %= P;
         if (S[i] == '0') break;
      }
      jyt << Ans * fac[pre0 - 1] % P << '\n';
      return 0;
   }
}
signed main() {
#ifdef WYY
   freopen("file/code.in", "r", stdin);
   freopen("file/code.out", "w", stdout);
#else
   freopen("employ.in", "r", stdin);
   freopen("employ.out", "w", stdout);
#endif
   std::ios::sync_with_stdio(false), ld.tie(0), jyt.tie(0);
   JoKing::main();
#ifdef WYY
   // while(true);
#endif
   return 0;
}
/*
nmd 怎么又不会了。

*/