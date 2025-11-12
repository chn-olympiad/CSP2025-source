#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const int MOD = 998244353;

int n, a[N], num[N][N], max_long, ans;  // num[i][j]在前i个棍中和大于j的组合方式
int sum[N][N];                          // 在前i个棍中长度大于j的棍数

int main() {
  freopen("polygon.in", "r", stdin);
  freopen("polygon.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], max_long = max(max_long, a[i]);
  sort(a + 1, a + n + 1);
  for (int j = 1; j <= max_long; j++) {
    for (int i = 1; i <= n; i++) {
      sum[i][j] = sum[i - 1][j];
      if (a[i] >= j) sum[i][j]++;
      sum[i][j] %= MOD;
    }
  }
  for (int j = 1; j <= max_long; j++) {
    for (int i = 1; i <= n; i++) {
      if (j < a[i])
        num[i][j] = i - 1;
      else
        num[i][j] = sum[i - 1][j - a[i]];
      num[i][j] %= MOD;
    }
  }
  for (int m = 3; m <= n; m++) {
    for (int i = m; i <= n; i++) ans = (ans + num[i - 1][a[i]]) % MOD;
    for (int j = 1; j <= max_long; j++) {
      for (int i = m; i <= n; i++) {
        if (j < a[i])
          num[i][j] = i - 1;
        else
          num[i][j] = sum[i - 1][j - a[i]];
        num[i][j] %= MOD;
      }
    }
  }
  cout << ans << endl;
  return 0;
}