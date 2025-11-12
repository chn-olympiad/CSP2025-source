#include <bits/stdc++.h>
template <class T>
using V = std::vector<T>;

using ll = long long;

int main() {
  std::cin.tie(0)->sync_with_stdio(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::array<V<int>, 3> a;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      std::array<std::pair<int, int>, 3> z{};
      for (int j : {0, 1, 2})
        std::cin >> z[j].first, z[j].second = j;
      sort(z.begin(), z.end(), std::greater<>());
      a[z[0].second].push_back(z[0].first - z[1].first);
      ans += z[0].first;
    }
    for (auto &ve : a) {
      if (ve.size() > n / 2) {
        std::sort(ve.begin(), ve.end(), std::greater<>());
        while (ve.size() > n / 2) ans -= ve.back(), ve.pop_back();
      }
    }
    std::cout << ans << '\n';
  }
}