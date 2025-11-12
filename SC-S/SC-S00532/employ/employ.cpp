#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

void add(int &a, int b) {
  (a += b) %= mod;
}

namespace sub0 {
  void solve(int n, int m, vector<char> a, vector<int> c) {
    for (int i = 1; i <= n; i++) if (a[i] == '0') return cout << 0 << endl, void();
    for (int i = 1; i <= n; i++) if (!c[i]) return cout << 0 << endl, void();
    int ans = 1;
    for (int i = 1; i <= n; i++) ans = (1ll * ans * i) % mod;
    cout << ans << endl;
  }
}

namespace BF {
  int dp[20][20][1 << 18];
  void solve(int n, int m, vector<char> a, vector<int> c) {
    memset(dp, 0, sizeof dp), dp[0][0][0] = 1;
    //cerr << n << ' ' << m << ' ' << (1 << n) << endl;
    for (int i = 0; i < n; i++) for (int j = 0; j <= i; j++) {
      for (int st = 0; st < 1 << n; st++) if (dp[i][j][st]) {
        for (int k = 0; k < n; k++) if (((st >> k) & 1) == 0) {
          //if (i <= 2) cerr << i << ' ' << j << ' ' << k << ' ' << st << ' ' << dp[i][j][st] << endl;
          if (i - j < c[k + 1] && a[i + 1] == '1') add(dp[i + 1][j + 1][st | (1 << k)], dp[i][j][st]);
          else add(dp[i + 1][j][st | (1 << k)], dp[i][j][st]);
        }
      }
    }
    int ans = 0;
    for (int st = 0; st < 1 << n; st++) 
      for (int i = m; i <= n; i++) add(ans, dp[n][i][st]);
    cout << ans << endl;
  }
}

signed main() {
  freopen("employ.in", "r", stdin),
  freopen("employ.out", "w", stdout);
  int n, m; cin >> n >> m;
  vector<char> a(n + 5);
  vector<int> c(n + 5);
  int sub1f = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0) sub1f = 0;
  }
  for (int i = 1; i <= n; i++) cin >> c[i];
  if (n <= 18) return BF::solve(n, m, a, c), 0;
  if (m == n) return sub0::solve(n, m, a, c), 0;
  return 0;
}