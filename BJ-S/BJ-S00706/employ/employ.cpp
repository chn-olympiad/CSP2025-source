#include <bits/stdc++.h>
using namespace std;
const int N = 19, P = 998244353;
int n, m, c[N], f[(1 << N - 1) + 1][N][N], sum[(1 << N - 1) + 1][N];
string s;
int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> s;
  s = '%' + s;
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= n; i++) {
    int st = (1 << i - 1);
    if (c[i]) f[st][i][0] = sum[st][0] = 1;
    else f[st][i][1] = sum[st][1] = 1;
  }
  for (int i = 0; i < (1 << n); i++) {
    int cnt = __builtin_popcount(i);
    if (cnt <= 1) continue;
    for (int j = 1; j <= n; j++) {
      if (!(i >> (j - 1) & 1)) continue;
      int lst = i ^ (1 << j - 1);
      for (int k = 0; k <= cnt; k++) {
        if (s[cnt] == '1') {
          if (c[j] > k) f[i][j][k] = sum[lst][k];
          else if (c[j] <= k - 1) f[i][j][k] = sum[lst][k - 1];
        }
        else {
          f[i][j][k] = sum[lst][k - 1];
        }
        sum[i][k] = (sum[i][k] + f[i][j][k]) % P;
      }
    }
  }
  int ans = 0;
  for (int i = m; i <= n; i++) {
    ans = (ans + sum[(1 << n) - 1][n - i]) % P;
  }
  cout << ans << '\n';
  return 0;
}