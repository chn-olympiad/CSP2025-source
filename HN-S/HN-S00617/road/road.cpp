#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 2e4 + 5, kMaxM = 2e6 + 5;
const int kMaxK = 15;
const LL kInf = 1e18;

struct E {
  LL u, v, w;

  bool operator< (const E &a) const {
    return w < a.w;
  }
} e[kMaxM], a[kMaxM], _e[kMaxK][kMaxN], to[kMaxM];

int fa[kMaxN], vis[kMaxM], _vis[kMaxN], n, m, k, cnt;
LL ans, v[kMaxN];

int Find(int x) {
  return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

LL Kruskal(E *e, int cnt) {
  LL ans = 0;
  for (int i = 1; i <= n + k; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= cnt; i++) {
    if (Find(e[i].u) != Find(e[i].v)) {
      fa[Find(e[i].u)] = Find(e[i].v);
      ans += e[i].w;
      vis[i] = 1;
    }
  }
  int c = 0;
  for (int i = 1; i <= n + k; i++) {
    c += Find(i) == i && _vis[i];
  }
  return c > 1 ? kInf : ans;
}

int Work(int id) {
  int len = 0;
  for (int i = 1; i <= m; i++) {
    e[++len] = a[i];
  }
  for (int i = 1; i <= k; i++) {
    if (id & (1 << i - 1)) {
      int p = 0;
      for (int x = 1, y = 1; x <= len || y <= n;) {
        if (x <= len && (y > n || e[x].w < _e[i][y].w)) {
          to[++p] = e[x], x++;
        } else {
          to[++p] = _e[i][y], y++;
        }
      }
      len = p;
      for (int j = 1; j <= len; j++) {
        e[j] = to[j];
      }
    }
  }
  // for (int i = 1; i <= len; i++) {
  //   cout << e[i].u << " " << e[i].v << " " << e[i].w << "\n";
  // }
  return len;
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a[i].u >> a[i].v >> a[i].w;
  }
  sort(a + 1, a + m + 1);
  ans = Kruskal(a, m);
  for (int i = 1; i <= m; i++) {
    if (vis[i]) {
      a[++cnt] = a[i];
    }
  }
  m = cnt;
  for (int i = 1, x; i <= k; i++) {
    cin >> v[i];
    for (int j = 1; j <= n; j++) {
      cin >> x;
      _e[i][j] = {i + n, j, x};
    }
    sort(_e[i] + 1, _e[i] + n + 1);
  }
  for (int i = 1; i <= n; i++) {
    vis[i] = 1;
  }
  for (int i = 0; i < 1 << k; i++) {
    LL sum = 0;
    for (int j = 1; j <= k; j++) {
      _vis[j] = bool(i & (1 << j - 1));
      sum += bool(i & (1 << j - 1)) * v[j];
    }
    int len = Work(i);
    // cout << sum << "\n";
    ans = min(ans, Kruskal(e, len) + sum);
  }
  cout << ans;
  // cout << "\n" << " " << clock() / 1000;
  return 0;
}
// g++ road.cpp -o road -std=c++14 -O2 -Wall && ./road