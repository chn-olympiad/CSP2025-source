#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i (l); i <= (r); ++ i)
#define rrp(i, l, r) for (int i (r); i >= (l); -- i)
#define eb emplace_back
#define pii pair <int, int>
using namespace std;
constexpr int N = 5e5 + 5, P = 998244353; //注意模数
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
int a[N][3], n;
vector <int> vec[3];
void solve () {
  n = rd ();
  rep (i, 1, n) a[i][0] = rd (), a[i][1] = rd (), a[i][2] = rd ();
  vec[0].clear (), vec[1].clear (), vec[2].clear ();
  int ans (0), c0 (0), c1 (0), c2 (0);
  rep (i, 1, n) {
    if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
      ans += a[i][0]; ++ c0;
      vec[0].eb (a[i][0] - max (a[i][1], a[i][2]));
    } else if (a[i][1] >= a[i][2]) {
      ans += a[i][1]; ++ c1;
      vec[1].eb (a[i][1] - max (a[i][0], a[i][2]));
    } else {
      ans += a[i][2]; ++ c2;
      vec[2].eb (a[i][2] - max (a[i][1], a[i][0]));
    }
  }
  rep (i, 0, 2)
  sort (vec[i].begin (), vec[i].end ());
  int now (0);
  while (c0 > n / 2) -- c0, ans -= vec[0][now], ++ now;
  while (c1 > n / 2) -- c1, ans -= vec[1][now], ++ now;
  while (c2 > n / 2) -- c2, ans -= vec[2][now], ++ now;
  cout << ans << endl;
}
int32_t main () {
  freopen ("club.in", "r", stdin);
  freopen ("club.out", "w", stdout);
  for (int T (rd ()); T; -- T) solve ();
}