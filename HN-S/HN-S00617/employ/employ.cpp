#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 505, kMaxS = 1 << 19, kL = 19;
const int kM = 998244353;

int f[kL][kMaxS], a[kMaxN], cnt[kMaxS], n, m;
int pos[kMaxN], c[kMaxN], _cnt;
LL p[kMaxN];
string s;

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> s;
  s = ' ' + s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c[a[i]]++;
    _cnt += s[i] == '1';
  }
  if (n <= 18) {
    for (int i = 1; i < 1 << n; i++) {
      cnt[i] = cnt[i - (i & -i)] + 1;
    }
    f[0][0] = 1;
    for (int i = 0; i < 1 << n; i++) {
      for (int j = 0; j <= m; j++) {
        for (int k = 1; k <= n; k++) {
          if (!(i & (1 << k - 1))) {
            int nxt = j + (a[k] <= j || s[cnt[i | (1 << k - 1)]] == '0');
            f[nxt][i | (1 << k - 1)] = (f[nxt][i | (1 << k - 1)] + f[j][i]) % kM;
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= n - m; i++) {
      ans = (ans + f[i][(1 << n) - 1]) % kM;
    }
    cout << ans;
  } else if (n == m) {
    for (int i = 1; i <= n; i++) {
      if (s[i] == '0' || a[i] == 0) {
        cout << 0;
        return 0;
      }
    }
    LL ans = 1;
    for (int i = 1; i <= n; i++) {
      ans = ans * i % kM;
    }
    cout << ans;
  } else if (m == 1) {
    int len = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '1') {
        pos[++len] = i - 1;
      }
      c[i] += c[i - 1];
    } 
    LL ans = 1, val = 1;
    for (int i = 1; i <= n; i++) {
      val = val * i % kM;
    }
    for (int i = 1; i <= len; i++) {
      ans = ans * max(0, c[pos[i]] - i + 1) % kM;
    }
    for (int i = 1; i <= n - len; i++) {
      ans = ans * i % kM;
    }
    cout << (val - ans + kM) % kM;
  }
  return 0;
}
// g++ employ.cpp -o employ -std=c++14 -O2 -Wall && ./employ