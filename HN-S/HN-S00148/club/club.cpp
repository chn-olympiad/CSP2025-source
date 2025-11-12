#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kN = 1e5 + 7, kM = 207;

int T, n, d[kN][4], ans, f[kM][2];

int DFS(int x, int a, int b, int c, int res) {
  if (x == n + 1) return ans = max(ans, res), res;
  int p = 0;
  if (a < n / 2) p = max(p, DFS(x + 1, a + 1, b, c, res + d[x][1]));
  if (b < n / 2) p = max(p, DFS(x + 1, a, b + 1, c, res + d[x][2]));
  if (c < n / 2) p = max(p, DFS(x + 1, a, b, c + 1, res + d[x][3]));
  return p;
} 

signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (cin >> T; T--; ) {
    cin >> n, ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> d[i][1] >> d[i][2] >> d[i][3];
      f[i][0] = f[i][1] = 0;
    }
    if (n <= 10) {
      DFS(1, 0, 0, 0, 0);
      cout << ans << '\n';
      continue;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= min(i, n / 2); j++) {
        if (i - j > n / 2) continue;
        if (j == 0) {
          f[j][1] = f[j][0] + d[i][2];
          continue;
        }
        if (i - j == 0) {
          f[j][1] = f[j - 1][0] + d[i][1];
          continue;
        }
        f[j][1] = max(f[j - 1][0] + d[i][1], f[j][0] + d[i][2]);
      }
      for (int j = 0; j <= min(i, n / 2); j++) {
        f[j][0] = f[j][1], f[j][1] = 0;
      }
    }
    cout << f[n / 2][0] << '\n';
  }

  return 0;
}
