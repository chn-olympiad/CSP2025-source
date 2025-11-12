#include <bits/stdc++.h>


namespace daiari {
  using ll = long long;
  const int maxn = 1e5 + 5;
  int n, m, w[maxn][3];
  int p[maxn], c[3];
  void adjust(int id) {
    std::vector<std::tuple<int, int, int>> cand;
    for (int i = 1; i <= n; ++i) {
      if (p[i] == id) {
        for (int j = 0; j < 3; ++j) {
          if (j != id) cand.emplace_back(w[i][j] - w[i][id], i, j);
        }
      }
    }
    std::sort(cand.begin(), cand.end(), std::greater<std::tuple<int, int, int>>{});
    for (auto [ x, k, j ] : cand) {
      if (p[k] != id) continue;
      p[k] = j; ++c[j];
      if (--c[id] <= m) return;
    }
  }
  void solve() {
    std::cin >> n; m = n >> 1;
    for (int i = 0; i < 3; ++i) c[i] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 3; ++j) std::cin >> w[i][j];
      p[i] = 0; for (int j = 1; j < 3; ++j) if (w[i][j] > w[i][p[i]]) p[i] = j;
      ++c[p[i]];
    }
    for (int i = 0; i < 3; ++i) {
      if (c[i] > m) {
        adjust(i);
        break;
      }
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
      res += w[i][p[i]];
    }
    std::cout << res << '\n';
  }
  int main() {
    int t;
    std::cin >> t;
    while (t--) {
      solve();
    }
    return 0;
  }
}

int main() {
  using namespace std;
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  daiari::main();
  cout.flush();
  return 0;
}
