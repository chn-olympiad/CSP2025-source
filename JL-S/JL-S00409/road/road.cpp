#include <bits/stdc++.h>

namespace daiari {
  using ll = long long;
  const int maxn = 1e4 + 50, maxm = 1e6 + 2e5 + 10;

  int n, m, k;
  struct Edge {
    int u, v; ll w;
    bool operator< (const Edge &b) const {
      return w < b.w;
    }
  } e[maxm];
  ll ans; int top;

  int fa[maxn], siz[maxn];
  int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
  void merge(int u, int v) {
    if (siz[u] > siz[v]) std::swap(u, v);
    fa[u] = v;
    siz[v] += siz[u];
  }

  int c[15], d[15][maxn];
  void solve(int s) {
    // std::clog << s << std::endl;
    int t = __builtin_popcount(s), E = n - 1 + t, z = 0, i;
    ll sum = 0;
    for (i = 0; i < k; ++i) if (s >> i & 1) sum += c[i + 1];
    std::iota(fa + 1, fa + 1 + n + k, 1);
    std::fill(siz + 1, siz + 1 + n + k, 1);
    for (i = 1; i <= top; ++i) {
      auto [ u, v, w ] = e[i];
      if (v > n && !(s >> (v - n - 1) & 1)) continue;
      if (sum + w * (E - z) >= ans) return;
      u = find(u), v = find(v);
      if (u != v) {
        merge(u, v);
        sum += w;
        if (++z >= E) break;
      }
    }
    if (!s) top = i;
    ans = std::min(ans, sum);
    // std::clog << s << ' ' << ans << std::endl;
  }

#define S(x) if (x::check()) x::solve(); else
  int main() {
    std::cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; ++i) {
      std::cin >> u >> v >> w;
      e[i] = { u, v, w };
    }
    for (int i = 1; i <= k; ++i) {
      std::cin >> c[i]; int p = 0;
      for (int j = 1; j <= n; ++j) {
        std::cin >> d[i][j];
        if (!d[i][j]) p = j;
      }
      if (!c[i] && p) {
        for (int j = 1; j <= n; ++j)
          e[++m] = { j, p, d[i][j] };
        --k; --i;
      } else {
        for (int j = 1; j <= n; ++j)
          e[++m] = { j, i + n, d[i][j] };
      }
    }
    std::sort(e + 1, e + 1 + m);

    ans = 0x3f3f3f3f3f3f3f3fll; top = m;
    std::vector<int> v; int t = 1 << k;
    for (int s = 0; s < t; ++s) {
      if (__builtin_popcount(s) > 1) v.push_back(s);
    }
    solve(0);
    for (int i = 0; i < k; ++i) solve(1 << i);
    std::mt19937 rng(std::random_device{}());
    std::shuffle(v.begin(), v.end(), rng);
    for (auto i : v) solve(i);
    
    std::cout << ans << '\n';
    return 0;
  }
#undef S
}

int main() {
  using namespace std;
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  daiari::main();
  cout.flush();
  return 0;
}
