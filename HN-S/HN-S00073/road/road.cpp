#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e4 + 5, M = 1e6 + 5, K = 15, F = M + N * K;
LL n, m, k, l, t, c[K], a[K][N], f[N + K], r = 1e18, vl[F];
unordered_map<int, int> h;
vector<pair<int, int>> q[F];
array<LL, 3> e[M], g[F];
int R(int x) {
  return f[x] == x ? x : f[x] = R(f[x]);
}
LL S(int C) {
  LL s = 0, z = 0;
  for (int i = 0; i < k; i++) {
    if (!((C >> i) & 1)) continue;
    s += c[i], z++;
    for (int j = 1; j <= n; j++)
      q[a[i][j]].push_back({n + i + 1, j});
  }
  iota(f + 1, f + n + k + 1, 1);
  for (int r = 1, j = 1; r <= t; r++)
    for (auto i : q[r]) {
      int u = R(i.first), v = R(i.second);
      u != v && (f[u] = v, j++, s += vl[r]);
      if (j == n + z) {
        for (int x = 0; x < k; x++)
          for (int y = 1; y <= n && ((C >> x) & 1); y++) q[a[x][y]].pop_back();
        return s;
      }
    }
}
int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> e[i][1] >> e[i][2] >> e[i][0], vl[++t] = e[i][0];
  }
  for (int i = 0; i < k; i++) {
    cin >> c[i];
    for (int j = 1; j <= n; j++) cin >> a[i][j], vl[++t] = a[i][j];
  }
  sort(vl + 1, vl + t + 1);
  t = unique(vl + 1, vl + t + 1) - vl - 1;
  for (int i = 1; i <= m; i++) {
    e[i][0] = lower_bound(vl + 1, vl + t + 1, e[i][0]) - vl;
    q[e[i][0]].push_back({e[i][1], e[i][2]});
  }
  for (int i = 0; i < k; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] = lower_bound(vl + 1, vl + t + 1, a[i][j]) - vl;
  for (int v = 0; v < (1 << k); v++) r = min(r, S(v));
  cout << r;
  return 0;
}
/*
直接看到 k <= 10
于是想到直接枚举城市化的乡村，模拟即可

发现做法假了，心态崩了呜呜呜

重新思考，只想到了 72分的做法，不过还是开始写了 

很快就写出来了，开始想正解 

过了很久

没想出来，放弃了，看看 T3 

写完 T3暴力后还是没思路，只好优化一下，希望 CCF神机一秒 3e9！ 

我草！优化完大样例全部跑进 1s！有希望！ 
*/
