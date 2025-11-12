#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i (l); i <= (r); ++ i)
#define rrp(i, l, r) for (int i (r); i >= (l); -- i)
#define eb emplace_back
#define pii pair <int, int>
using namespace std;
constexpr int N = 2e4 + 5, M = 1e6 + 5, P = 998244353; //注意模数
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
int n, m, k;
class node {
  public:
  int u, v, w;
  friend bool operator < (const node &a, const node &b) {
    return a.w < b.w;
  }
} e[M], E[M];
int c[10];
int fa[N];
int find (int x) {
  return x == fa[x] ? x : fa[x] = find (fa[x]);
}
int32_t main () {
  freopen ("road.in", "r", stdin);
  freopen ("road.out", "w", stdout);
  n = rd (), m = rd (), k = rd ();
  rep (i, 1, m) {
    int u (rd ()), v (rd ()), w (rd ());
    e[i] = {u, v, w}; 
  } sort (e + 1, e + m + 1);
  rep (i, 1, n) fa[i] = i;
  int cnt (0);
  rep (i, 1, m) {
    if (find (e[i].u) != find (e[i].v)) {
      fa[find (e[i].u)] = find (e[i].v);
      E[++ cnt] = e[i];
    }
  }
  rep (i, 0, k - 1) {
    c[i] = rd ();
    rep (j, 1, n) {
      int w (rd ());
      E[++ cnt] = {n + i + 1, j, w};
    }
  }
  sort (E + 1, E + cnt + 1);
  int ans = 1e16;
  rep (s, 0, (1 << k) - 1) {
    int ret (0);
    rep (i, 0, k - 1) {
      if (s >> i & 1) {
        ret += c[i];
      }
    }
    rep (i, 1, n + k) fa[i] = i;
    rep (i, 1, cnt) {
      if (E[i].u <= n || (s >> (E[i].u - n - 1) & 1)) {
        if (find (E[i].u) != find (E[i].v)) {
          ret += E[i].w;
          fa[find (E[i].u)] = find (E[i].v);
          if (ret >= ans) break;
        }
      }
    }
    ans = min (ans, ret);
  } cout << ans; 
}