#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main() {
   freopen("replace.in", "r", stdin);
   freopen("replace.out", "w", stdout);
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n, q;
   cin >> n >> q;
   vector<string> s1(n + 1), s2(n + 1);
   vector<ull> h1(n + 1), h2(n + 1);
   for (int i = 1; i <= n; i++) {
      cin >> s1[i] >> s2[i];
      for (int j = 0; j < s1[i].size(); j++) h1[i] = h1[i] * 131 + s1[i][j], h2[i] = h2[i] * 131 + s2[i][j];
   }
   for (int i = 1; i <= q; i++) {
      string t1, t2;
      cin >> t1 >> t2;
      int m = t1.size();
      if (n * m > 1e8 || 1.0L * clock() / CLOCKS_PER_SEC > 0.9) {
         cout << "0\n";
         continue;
      }
      vector<ull> fac(m + 1);
      array<vector<ull>, 2> h;
      h[0].resize(m + 1), h[1].resize(m + 1), fac[0] = 1;
      for (int j = 1; j <= m; j++) h[0][j] = h[0][j - 1] * 131 + t1[j - 1], h[1][j] = h[1][j - 1] * 131 + t2[j - 1], fac[j] = fac[j - 1] * 131;
      auto get = [&](int p, int l, int r) -> ull { return l <= r ? h[p][r] - h[p][l - 1] * fac[r - l + 1] : 0; };
      int ans = 0;
      for (int j = 1; j <= n; j++)
         for (int k = 1; k <= m - (int)s1[j].size() + 1; k++) {
            int x = k + s1[j].size();
            if (get(0, 1, k - 1) == get(1, 1, k - 1) && get(0, k, x - 1) == h1[j] && get(1, k, x - 1) == h2[j] && get(0, x, m) == get(1, x, m)) ans++;
         }
      cout << ans << "\n";
   }
   return 0;
}