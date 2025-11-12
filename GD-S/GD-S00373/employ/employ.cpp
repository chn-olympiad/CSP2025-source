#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 15;
constexpr int MOD = 998244353;

int a[N], b[N];

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);

  cin.tie(nullptr)->sync_with_stdio(false);


  int n, m;
  string s;
  cin >> n >> m >> s;
  s = ' ' + s;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n <= 10) {
    for (int i = 1; i <= n; i++) b[i] = i;
    int res = 0;
    do {
      int cnt = 0, p = 0;
      for (int i = 1; i <= n; i++) {
        if (cnt < a[b[i]] && s[i] == '1') {
          p++;
        } else {
          cnt++;
        }
      }
      if (p >= m) res++;
    } while (next_permutation(b + 1, b + n + 1));
    cout << res << endl;
    return 0;
  }

  bool flag = true;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0' || a[i] == 0) {
      flag = false;
      break;
    }
  }

  i64 fac = 1;
  for (int i = 1; i <= n; i++) (fac *= i) %= MOD;

  if (n == m) {
    if (flag) cout << fac << endl;
    else cout << 0 << endl;
  }
  

  return 0;
}
