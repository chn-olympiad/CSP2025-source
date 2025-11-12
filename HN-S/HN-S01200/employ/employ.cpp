#include <bits/stdc++.h>

using namespace std;

const int MAXN = (1 << 18), Mod = 998244353;

string s;
int n, m, a[MAXN], dp[MAXN][20];

void Plus(int &u, int x) {
  u += x, (u >= Mod) && (u -= Mod);
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n <= 18) {
    dp[0][0] = 1;
    for (int i = 0; i < (1 << n); i++) {
      int o = 0;
      for (int x = 0; x < n; x++) {
        o += ((i >> x) & 1);
      }
      for (int x = 0; x < n; x++) {
        if ((i >> x) & 1) continue;
        for (int c = 0; c < n; c++) {
          //cout << i << ' ' << c << ' ' << dp[i][c] << '\n';
          Plus(dp[i | (1 << x)][c + (c >= a[x] || s[o] == '0')], dp[i][c]);
        }
      }
    }
    int ans = 0;
    for (int c = 0; c <= n - m; c++) {
      Plus(ans, dp[(1 << n) - 1][c]);
    }
    cout << ans;
  } else {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      ans = 1ll * ans * i % Mod;
    }
    cout << ans;
  }
  return 0;
}
