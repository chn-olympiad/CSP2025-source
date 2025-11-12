/*
Coder : CJSY242203 CXM
tips : 033999
Password : Ren5Jie4Di4Ling5%
Pass all simple On :
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e4 + 5, M = 1e6 + 5, K = 15;

struct Dsu {
  int siz, x;
} fa[N];

struct Edge {
  int u, v, w;
} e[M];

int Test, n, m, k, c[K], b[K][N];

bool cmp (const Edge &i, const Edge &j) {
  return i.w < j.w;
}

int seek (int x) { return fa[x].x == x ? x : fa[x].x = seek (fa[x].x); }

void inco (int x, int y) {
  x = seek (x), y = seek (y);
  if (x ^ y) {
    if (fa[x].siz < fa[y].siz) swap (x, y);
    fa[x].siz += fa[y].siz, fa[y] = {0, x};
  }
}

void solve () {
  cin >> n >> m >> k;
  for (register int i = 1; i <= n; ++i) {
    fa[i] = {1, i};
  }
  for (register int i = 1; i <= m; ++i) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  sort (e + 1, e + m + 1, cmp);
  vector<Edge> E;
  ll ans = 0;
  for (register int i = 1; i <= m; ++i) {
    if (seek (e[i].u) != seek (e[i].v)) {
      inco (e[i].u, e[i].v);
      E.push_back (e[i]), ans += e[i].w;
    }
  }
  for (register int i = 0; i < k; ++i) {
    cin >> c[i];
    for (int j = 1; j <= n; ++j) {
      cin >> b[i][j];
    }
  }
  for (register int i = 0; i < (1 << k); ++i) {
    vector<Edge> choose = E;
    ll res = 0, cnt = 0;
    for (register int j = 0; j < k; ++j) {
      if (i >> j & 1) {
        res += c[j];
        for (int pos = 1; pos <= n; ++pos) {
          if (pos ^ j) {
            choose.push_back ({j + 1 + n, pos, b[j][pos]});
          }
        }
      }
    }
    for (register int j = 1; j <= n + k; ++j) {
      fa[j] = {1, j};
    }
    random_shuffle (choose.begin (), choose.end ());
    sort (choose.begin (), choose.end (), cmp);
    for (auto i : choose) {
      if (seek (i.u) ^ seek (i.v)) {
        inco (i.u, i.v);
        ++cnt, res += i.w;
      }
      if (cnt == n + k - 1) break;
    }
    ans = (ans > res ? res : ans);
  }
  cout << ans;
}

int main () {
  freopen ("road.in", "r", stdin);
  freopen ("road.out", "w", stdout);
  ios :: sync_with_stdio (0), cin.tie (0);
  for (Test = 1; Test--; solve ()) {
  }
  return 0;
}
/*
// freopen ()
  this is a never gonna give you up sentence.
  to day (11.1) is cxm's birthday, and I hope :
  CSP_J = 400, CSP_S = max (CSP_S, 300), rp += inf;
*/
