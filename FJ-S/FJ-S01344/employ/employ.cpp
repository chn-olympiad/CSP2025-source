#include<bits/stdc++.h>
using ll = long long;
using namespace std;
constexpr ll mod = 998244353;
ll n, m, c[555], dp[19][524299], ans = 0;
string s;
int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> s;
  for(int i = 1; i <= n; ++i) cin >> c[i];
  dp[0][0] = 1;
  for(int i = 0; i <= n; ++i) {
    for(int j = 0; j < (1 << n); ++j) {
      int ct = 0;
      for(int k = 0; k < n; ++k) if((j >> k) & 1) ++ct;
      if(ct < i) continue;
      for(int k = 0; k < n; ++k)
        if((j >> k) & 1) continue;
        else {
          if(i >= c[k + 1] || s[ct] == '0') {
            (dp[i + 1][j ^ (1 << k)] += dp[i][j]) %= mod;
          } else {
            (dp[i][j ^ (1 << k)] += dp[i][j]) %= mod;
          }
        }
    }
  }
  for(int i = m; i <= n; ++i)
    (ans += dp[n - i][(1 << n) - 1]) %= mod;
  cout << ans;
  return 0;
}
