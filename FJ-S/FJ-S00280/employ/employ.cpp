#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

using LL = long long;
using namespace std;

const int N = 510, P = 998244353;
string S;
int c[N], n, m;

namespace Sub1 {
  const int N = 18;
  int f[1 << N][N + 1];
  void main() {
    f[0][0] = 1;
    for (int s = 0; s < (1 << n); s++) {
      int k = __builtin_popcount(s);
      for (int i = 0; i <= n; i++) {
        if (f[s][i]) {
          for (int j = 0; j < n; j++) {
            if (~s >> j & 1) {
              int nc = i + (S[k] == '0' || c[j + 1] <= i);
              (f[s | (1 << j)][nc] += f[s][i]) %= P;
            }
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= n - m; i++) {
      (ans += f[(1 << n) - 1][i]) %= P;
    }
    cout << ans << '\n';
  }
}

namespace Sub2 {
  void main() {
    if (count(all(S), '1') != n) {
      cout << 0 << '\n';
      return ;
    }
    if (count(c + 1, c + n + 1, 0)) {
      cout << 0 << '\n';
      return ;
    }
    sort(c + 1, c + n + 1);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      ans = 1LL * ans * i % P;
    }
    cout << ans << '\n';
  }
}

namespace Sub3 {
  int sum[N];
  void main() {
    for (int i = 1; i <= n; i++) {
      sum[c[i]]++;
    }
    for (int i = 1; i <= n; i++) {
      sum[i] += sum[i - 1];
    }
    int res = 1, cnt = n, now = 0;
    for (int i = 0; i < n; i++) {
      if (S[i] == '1') {
        cnt--;
        res = 1LL * res * max(0, (sum[i] - now)) % P;
        now++;
      }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      ans = 1LL * ans * i % P;
    }
    for (int i = 1; i <= cnt; i++) {
      res = 1LL * res * i % P;
    }
    cout << (ans - res + P) % P;
  }
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  cin >> S;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  if (n <= 18) {
    Sub1::main();
  }
  else if (m == n) {
    Sub2::main();
  }
  else if (m == 1) {
    Sub3::main();
  }
  return 0;
}