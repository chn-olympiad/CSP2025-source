#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define pb emplace_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

unsigned char buf[1 << 21], *iS, *iT;
#define getchar() ((iS == iT) && (iT = buf + fread(iS = buf, 1, 1 << 21, stdin)), (iS == iT) ? EOF : *iS++)

int read() {
  char c;
  while (!isdigit(c = getchar())) ;
  int x = c ^ 48;
  while (isdigit(c = getchar())) {
    x = x * 10 + (c ^ 48);
  }
  return x;
}

constexpr int N = 1e4 + 500, M = 1e6 + 5;
int n, m, k;
int a[15][N], fa[N], c[15], rk[15][N];

vector<tuple<int, int, int>> E1, E2;

int getf(int x) {
  return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  n = read(), m = read(), k = read();
  E1.resize(m);
  iota(fa + 1, fa + 1 + n + k, 1);
  for (auto &[w, u, v] : E1) {
    u = read();
    v = read();
    w = read();
  }
  sort(all(E1));
  for (auto [w, u, v] : E1) {
    if (getf(u) != getf(v)) {
      E2.pb(w, u, v);
      fa[getf(u)] = getf(v);
    }
  }
  for (int i = 1; i <= k; ++i) {
    c[i] = read();
    for (int j = 1; j <= n; ++j) {
      a[i][j] = read();
    }
    iota(rk[i] + 1, rk[i] + 1 + n, 1);
    sort(rk[i] + 1, rk[i] + 1 + n, [&](int x, int y) {
      return a[i][x] < a[i][y];
    });
  }
  LL ans = 1e18;//10^4 * 10^9
  for (int i = 0; i < (1 << k); ++i) {
    LL res = 0;
    for (int j = 1; j <= k; ++j) {
      if (i >> (j - 1) & 1) {
        res += c[j];
      }
    }
    
    iota(fa + 1, fa + 1 + n + k, 1);
    int ptr[15] {}, PTR = 0;
    fill_n(ptr + 1, k, 1);
    
    for (; ; ) {
      tuple<int, int, int> E(2e9, 0, 0);
      for (int j = 1; j <= k; ++j) {
        if (i >> (j - 1) & 1) {
          while (ptr[j] <= n && getf(j + n) == getf(rk[j][ptr[j]])) {
            ++ptr[j];
          }
          if (ptr[j] <= n) {
            E = min(E, make_tuple(a[j][rk[j][ptr[j]]], j + n, rk[j][ptr[j]]));
          }
        }
      }
      while (PTR < sz(E2)) {
        auto [w, u, v] = E2[PTR];
        if (getf(u) == getf(v)) {
          ++PTR;
        }else {
          break;
        }
      }
      if (PTR < sz(E2)) {
        E = min(E, E2[PTR]);
      }
      auto [w, u, v] = E;
      if (!u) {
        break;
      }
      res += w;
      fa[getf(u)] = getf(v);
    }
    ans = min(ans, res);
  }
  cout << ans << '\n';
  return 0;
}
