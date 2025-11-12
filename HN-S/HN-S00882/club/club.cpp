#include <bits/stdc++.h>
using namespace std;
int main() {
   freopen("club.in", "r", stdin);
   freopen("club.out", "w", stdout);
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      vector<array<int, 3>> a(n + 1);
      for (int i = 1; i <= n; i++)
         for (int j = 0; j < 3; j++)
            cin >> a[i][j];
      array<vector<int>, 3> f;
      int ans = 0;
      for (int i = 1; i <= n; i++)
         if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) f[0].emplace_back(a[i][0] - max(a[i][1], a[i][2])), ans += a[i][0];
         else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) f[1].emplace_back(a[i][1] - max(a[i][0], a[i][2])), ans += a[i][1];
         else f[2].emplace_back(a[i][2] - max(a[i][0], a[i][1])), ans += a[i][2];
      sort(f[0].begin(), f[0].end()), sort(f[1].begin(), f[1].end()), sort(f[2].begin(), f[2].end());
      if (f[0].size() > n >> 1)
         for (int i = 0; i < f[0].size() - (n >> 1); i++)
            ans -= f[0][i];
      if (f[1].size() > n >> 1)
         for (int i = 0; i < f[1].size() - (n >> 1); i++)
            ans -= f[1][i];
      if (f[2].size() > n >> 1)
         for (int i = 0; i < f[2].size() - (n >> 1); i++)
            ans -= f[2][i];
      cout << ans << "\n";
   }
   return 0;
}