#include <bits/stdc++.h>

const int N = 3e6;
using ll = long long;

bool mst;

struct map {
  std::vector<std::pair<int, int>> ve;
  auto count(int u) -> bool {
    auto it = std::lower_bound(ve.begin(), ve.end(), u, [](auto a, auto b) { return a.first < b; });
    return it != ve.end() && it->first == u;
  }
  auto &operator[](int u) {
    auto it = std::lower_bound(ve.begin(), ve.end(), u, [](auto a, auto b) { return a.first < b; });
    return ve[it - ve.begin()].second;
  }
  auto insert(std::pair<int, int> c) {
    auto it = std::lower_bound(ve.begin(), ve.end(), c);
    ve.insert(it, c);
  }
};

std::array<map, N> g;
std::array<int, N> fi, dep, lb, len, cnt;
bool med;

int main() {

  std::cin.tie(0)->sync_with_stdio(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);

  // std::cerr << (&med - &mst) / 1024.0 / 1024 << '\n';
  int nt = 1;

  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::string s, t;
    std::cin >> s >> t;
    int u = 1;
    for (int i = 0; i < (int)s.size(); i++) {
      int c = (s[i] - 'a') * 26 + (t[i] - 'a');
      if (!g[u].count(c)) {
        g[u].insert({c, ++nt});
        len[nt] = i + 1;
      }
      u = g[u][c];
    }
    cnt[u]++;
  }

  // std::cerr << nt << '\n';  
  std::queue<int> q;
  for (auto [c, v] : g[1].ve) fi[v] = 1, q.push(v);
  while (q.size()) {
    int u = q.front();
    q.pop();
    cnt[u] += cnt[fi[u]];
    dep[u] = dep[fi[u]] + 1;
    lb[u] = dep[fi[u]] - dep[lb[fi[u]]] == dep[lb[fi[u]]] - dep[lb[lb[fi[u]]]] ? lb[lb[fi[u]]] : fi[u];

    for (auto [c, v] : g[u].ve) {
      fi[v] = fi[u];
      while (fi[v] != 1 && !g[fi[v]].count(c)) fi[v] = fi[fi[v]];
      if (g[fi[v]].count(c)) fi[v] = g[fi[v]][c];
      q.push(v);
    }
  }
  while (m--) {
    std::string a, b;
    std::cin >> a >> b;
    int k = a.size();
    int pr = -1, pl = k;
    for (int i = 0; i < k; i++) {
      if (a[i] != b[i]) {
        if (pl == k) pl = i;
        pr = i;
      } 
    }
    int u = 1;
    ll ans = 0;
    for (int i = 0; i < k; i++) {
      int c = (a[i] - 'a') * 26 + (b[i] - 'a');
      while (u != 1 && !g[u].count(c)) u = fi[u];
      if (g[u].count(c)) u = g[u][c];
      if (i >= pr) {
        ans += cnt[u];
        int tu = u, mnl = std::max(i - pl, 0) + 1;
        while (len[tu] >= mnl) {
          if (len[lb[tu]] >= mnl) tu = lb[tu];
          else tu = fi[tu];
        }
        ans -= cnt[tu];
      }
    }
    std::cout << ans << '\n';
  }



}