#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;
int main() {
   freopen("employ.in", "r", stdin);
   freopen("employ.out", "w", stdout);
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n, m;
   string s;
   cin >> n >> m >> s;
   if (n > 18) cout << 0, exit(0);
   vector<int> c(n);
   for (int i = 0; i < n; i++) cin >> c[i];
   vector<vector<int>> f(n + 1, vector<int>(1 << n));
   f[0][0] = 1;
   auto add = [&](int &x, int y) -> void { (x += y) >= mod && (x -= mod); };
   for (int i = 1; i < 1 << n; i++) {
      int p = __builtin_popcount(i);
      for (int j = 0; j < n; j++)
         if (i >> j & 1)
            for (int k = 0; k <= n; k++)
               if (p - k <= c[j] && s[p - 1] & 1 && k < n) add(f[k + 1][i], f[k][i ^ 1 << j]);
               else if (p - k > c[j] || !(s[p - 1] & 1)) add(f[k][i], f[k][i ^ 1 << j]);
   }
   int ans = 0;
   for (int i = m; i <= n; i++) add(ans, f[i][(1 << n) - 1]);
   cout << ans;
   return 0;
}