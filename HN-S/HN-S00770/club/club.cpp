#include <bits/stdc++.h>

using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

constexpr int N = 1E5 + 5;

int n, ans;
std::array<int, N> id;
std::array<std::array<int, 3>, N> a;
void Proc() {
  std::cin >> n, ans = 0;
  std::array<int, 3> d{0, 0, 0};
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    id[i] = std::max_element(begin(a[i]), end(a[i])) - begin(a[i]);
    ++d[id[i]], ans += a[i][id[i]];
  }
  int maj = std::max_element(begin(d), end(d)) - begin(d);
  if (d[maj] <= (n >> 1)) return void(std::cout << ans << '\n');
  std::vector<int> reg;
  for (int i = 1; i <= n; ++i) {
    if (id[i] - maj) continue;
    int mx = 0;
    for (int c : {0, 1, 2})
      if (c - maj) mx = std::max(mx, a[i][c]);
    reg.push_back(a[i][maj] - mx);
  }
  std::sort(begin(reg), end(reg));
  for (int i = 0; i < d[maj] - (n >> 1); ++i) ans -= reg[i];
  std::cout << ans << '\n';
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) Proc();

  return 0;
}