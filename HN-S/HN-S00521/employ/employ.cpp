#include <bits/stdc++.h>
#define rep(i, l, r) for (int i (l); i <= (r); ++ i)
#define rrp(i, l, r) for (int i (r); i >= (l); -- i)
#define eb emplace_back
#define pii pair <int, int>
using namespace std;
constexpr int N = 500 + 5, P = 998244353; //注意模数
inline int rd () {
  int x (0), f (1);
  char ch = getchar ();
  while (! isdigit (ch)) {
    if (ch == '-') f = -1;
    ch = getchar ();
  }
  while (isdigit (ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar ();
  } return x * f;
} //冷静
int qpow (int x, int y) {
  int ret (1);
  for (; y; y >>= 1, x = x * x % P) if (y & 1) ret = ret * x % P;
  return ret;
}
int n, m;
char s[N];
int sum[N];
int c[N];
int f[1 << 18][N];
void add (int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
int pos[N], pre[N], suf[N];
int ss[N];
int32_t main () {
  freopen ("employ.in", "r", stdin);
  freopen ("employ.out", "w", stdout);
  n = rd (), m = rd ();
  scanf ("%s", s + 1);
  rep (i, 1, n) c[i] = rd ();
  rep (i, 0, n - 1) rep (j, 1, n) ss[i] += c[j] <= i;
  if (n <= 18) {
    f[0][0] = 1;
    rep (i, 0, (1 << n) - 2) {
      rep (j, 0, n - 1) {
        int now = __builtin_popcount (i);
        rep (k, 0, n - 1) {
          if (i >> k & 1) continue;
          if (s[now + 1] == '0') add (f[i | (1 << k)][j + 1], f[i][j]);
          else {
            if (j < c[k + 1]) add (f[i | (1 << k)][j], f[i][j]);
            else add (f[i | (1 << k)][j + 1], f[i][j]);
          }
        }
      }
    }
    int ans (0);
    rep (i, 0, n - m) add (ans, f[(1 << n) - 1][i]);
    cout << ans;
    return 0;
  }
  if (m == n) {
    rep (i, 1, n) if (s[i] == '0') return puts ("0") * 0;
    rep (i, 1, n) if (! c[i]) return puts ("0") * 0;
    int ans (1);
    rep (i, 1, n) ans = 1ll * ans * i % P;
    cout << ans; return 0;
  }
  int cnt (1);
  int now (0);
  rep (i, 1, n) if (s[i] == '1') {
    cnt = 1ll * cnt * (ss[i - 1] - now) % P; ++ now;
  }
  rep (i, 1, n - now) cnt = 1ll * cnt * i % P;
  int t (1);
  rep (i, 1, n) t = 1ll * t * i % P;
  cout << (t - cnt + P) % P;
}