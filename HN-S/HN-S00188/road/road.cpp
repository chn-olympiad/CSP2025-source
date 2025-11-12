// BLuemoon_
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 1e4 + 15, kMaxM = 1e6 + 5, kMaxK = 15;
const LL kP = 1e9 + 7;

LL T = 1, n, m, k, a[kMaxN], ans = 1e18, c[kMaxK], f[kMaxK][kMaxN], dis[kMaxN], vis[kMaxN], u[kMaxM], v[kMaxM], w[kMaxM];
vector<pair<int, LL>> g[kMaxN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
  for (; T; T--, ans = 0) {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
      cin >> u[i] >> v[i] >> w[i], g[u[i]].push_back({v[i], w[i]}), g[v[i]].push_back({u[i], w[i]});
    }
    for (int i = 1; i <= k; i++) {
      cin >> c[i];
      for (int j = 1; j <= n; j++) {
        cin >> f[i][j];
      }
    }
    for (int i = 0; i < 1 << k; i++) {
      LL tot = n, cnt = 0;
      for (int j = 1; j <= k; j++) {
        if (i >> j - 1 & 1) {
          tot++, cnt += c[j];
          for (int l = 1; l <= n; l++) {
            g[tot].push_back({l, f[j][l]}), g[l].push_back({tot, f[j][l]});
          }
        }
      }
      fill(dis + 2, dis + tot + 1, 1e18), fill(vis + 1, vis + tot + 1, 0), vis[1] = 1, dis[1] = 0;
      for (pair<int, LL> j : g[1]) {
        int v = j.first, w = j.second;
        dis[v] = min(dis[v], 1ll * w);
      }
      for (int j = 1; j < tot; j++) {
        LL mn = 1e18, u;
        for (int l = 1; l <= tot; l++) {
          if (!vis[l] && mn >= dis[l]) {
            mn = dis[l], u = l;
          }
        }
        cnt += dis[u], dis[u] = 0, vis[u] = 1;
        for (pair<int, LL> l : g[u]) {
          int v = l.first, w = l.second;
          dis[v] = min(dis[v], 1ll * w);
        }
      }
      ans = min(ans, cnt);
      for (int j = 1; j <= n; j++) {
        for (int l = 1; l <= tot - n; l++) {
          g[j].pop_back();
        }
      }
      for (int j = n + 1; j <= tot; j++) {
        g[j].clear();
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
// ulimit -s 102400 && g++ road.cpp -o road -O2 -std=c++14 -Wall && ./road