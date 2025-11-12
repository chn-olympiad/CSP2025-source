#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
const int mod = 998244353;
const int MX = (1 << 18) + 5;
bool in(int i, int s) {
  return (s >> i) & 1;
}
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int n, m, c[N], fac[N];
string S;
struct SolA {
  int f[MX][19];
  void solve() {
    f[0][0] = 1;
    for (int s = 0; s < (1 << n); ++s) {
      int p = __builtin_popcount(s);
      for (int i = 0; i <= p; ++i) {
        if (!f[s][i]) continue;
        for (int j = 0; j < n; ++j) {
          if (in(j, s)) continue;
          bool flg = S[p + 1] == '1' && c[j + 1] > i;
          add(f[s | (1 << j)][i + !flg], f[s][i]);
        }
      }
    }
    int res = 0;
    for (int i = 0; n - i >= m; ++i) {
      add(res, f[(1 << n) - 1][i]);
    }
    cout << res << '\n';
  }
} A;
struct SolB {
  void solve() {
    int cnt = 0, fc = 1;
    for (int i = 1; i <= n; ++i) {
      cnt += (c[i] > 0);
      fc = 1ll * fc * i % mod;
    }
    if (cnt >= m) cout << fc << '\n';
    else cout << 0 << '\n';
  }
} B;
struct SolMn {
  void solve() {
    bool flg = 1;
    int fc = 1;
    for (int i = 1; i <= n; ++i) {
      flg &= (S[i] == '1');
      flg &= (c[i] > 0);
      fc = 1ll * fc * i % mod;
    }
    cout << (flg ? fc : 0) << '\n';
  }
} Mn;
struct SolM1 {
  void solve() {
    int res = 1, now = 0, tot = 0;
    for (int i = 1; i <= n; ++i) {
      if (S[i] == '0') continue;
      while (now < n && c[now + 1] < i) ++now;
      ++tot;
      if (now < tot) res = 0;
      res = 1ll * res * (now - (tot - 1)) % mod;
    }
    res = 1ll * res * fac[n - tot] % mod;
    res = fac[n] - res;
    if (res < 0) res += mod;
    cout << res << '\n';
  }
} M1;
signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios :: sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  fac[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = 1ll * fac[i - 1] * i % mod;
  }
  cin >> n >> m >> S;
  S = ' ' + S;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  sort(c + 1, c + n + 1);
  bool flg1 = 1;
  for (int i = 1; i <= n; ++i) {
    flg1 &= (S[i] == '1');
  }
  if (n <= 18) A.solve();
  else if (m == n) Mn.solve();
  else if (m == 1) M1.solve();
  else cout << fac[n] << '\n';
  // cerr << "used time: " << (signed)clock() * 1000 / CLOCKS_PER_SEC << '\n';
  return 0;
}