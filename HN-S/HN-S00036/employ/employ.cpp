#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e2 + 10, MOD = 998244353;

int n, m, c[MAXN];
string s;

namespace N10 {
  int p[MAXN];
  void Solve() {
    iota(p + 1, p + n + 1, 1);
    int ans = 0;
    do {
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (c[p[i]] <= cnt || s[i] == '0') {
          cnt++;
        }
      }
      ans += cnt <= n - m;
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans << '\n';
  }
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> s;
  s = '#' + s;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  if (n <= 10) {
    N10::Solve();
    return 0;
  }
  return 0;
}

