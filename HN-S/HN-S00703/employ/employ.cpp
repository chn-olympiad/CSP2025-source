#include <fstream>
#include <string>

using namespace std;
using LL = long long;

const int kMaxN = 19, kMod = 998244353;

ifstream cin("employ.in");
ofstream cout("employ.out");

int a[kMaxN], f[kMaxN], dp[1 << kMaxN][kMaxN], n, m, ans;
string s;

int popcount(int x) {
  int cnt = 0;
  for (; x; x -= x & -x) {
    cnt++;
  }
  return cnt;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> s;
  s = " " + s;
  for (LL i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 1;
  for (LL i = 0; i < 1 << n; i++) {
    LL tot = popcount(i);
    for (LL j = 0; j <= tot; j++) {
      LL fail = tot - j;
      for (LL k = 1; k <= n; k++) {
        if (i & (1 << (k - 1))) {
          continue;
        }
        LL d = s[tot + 1] == '1' && fail < a[k];
        dp[i | (1 << (k - 1))][j + d] = (dp[i | (1 << (k - 1))][j + d] + dp[i][j]) % kMod;
      }
    }
  }
  for (LL i = m; i <= n; i++) {
    ans = (ans + dp[(1 << n) - 1][i]) % kMod;
  }
  cout << ans << '\n';
  return 0;
}
