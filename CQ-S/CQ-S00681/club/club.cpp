#include<bits/stdc++.h>
#include<bits/extc++.h>
using ll = long long; using ull = unsigned long long;
#define ld std::cin
#define jyt std::cout
#define cmd std::cerr
#define REQ(i, l, r) for (int i = l; i <  r; ++i)
#define REP(i, l, r) for (int i = l; i <= r; ++i)
#define PER(i, l, r) for (int i = l; i >= r; --i)
namespace JoKing { // JoKing 10min Accepted
   const int N = 2e5 + 7;
   const int inf = 2e9 + 7;
   const int P = 998244353;
   int n, a[N][4], bel[N], cnt[4], Ans = 0, p[N], pc = 0;
   signed main() {
      ld >> n;
      REP(i, 1, n) {
         int Max = -1, Id = -1;
         REP(j, 1, 3) if (ld >> a[i][j], Max < a[i][j]) Max = a[i][j], Id = j;
         Ans += Max, ++cnt[Id], bel[i] = Id;
      }
      REP(j, 1, 3) if (cnt[j] > (n >> 1)) {
         REP(i, 1, n) if (bel[i] == j) p[++pc] = a[i][j] - std::max(a[i][(j + 0) % 3 + 1], a[i][(j + 1) % 3 + 1]);
         std::sort(p + 1, p + pc + 1);
         REP(i, 1, cnt[j] - (n >> 1)) Ans -= p[i];
      }
      jyt << Ans << '\n';
      cnt[1] = cnt[2] = cnt[3] = pc = Ans = 0;
      REP(i, 1, n) a[i][1] = a[i][2] = a[i][3] = p[i] = bel[i] = 0;
      return 0;
   }
}
signed main() {
#ifdef WYY
   freopen("club3.in", "r", stdin);
   freopen("file/code.out", "w", stdout);
#else
   freopen("club.in", "r", stdin);
   freopen("club.out", "w", stdout);
#endif
   std::ios::sync_with_stdio(false), ld.tie(0), jyt.tie(0);
   int T = 0; ld >> T;
   while (T--) JoKing::main();
#ifdef WYY
   // while(true);
#endif
   return 0;
}