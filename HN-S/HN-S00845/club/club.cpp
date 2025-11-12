// g++ -std=c++14 -O2 -fsanitize=address,undefined -o club club.cpp && ./club
#include <bits/stdc++.h>

#define int int64_t

const int kMaxN = 1e5 + 5;

int n;
int a[kMaxN][3], op[kMaxN];

void dickdreamer() {
  std::cin >> n;
  int sum = 0, cnt[3] = {0};
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    int mx = std::max({a[i][0], a[i][1], a[i][2]});
    sum += mx;
    if (a[i][0] == mx) op[i] = 0;
    else if (a[i][1] == mx) op[i] = 1;
    else op[i] = 2;
    ++cnt[op[i]];
  }
  int o = -1;
  if (cnt[0] > n / 2) o = 0;
  else if (cnt[1] > n / 2) o = 1;
  else if (cnt[2] > n / 2) o = 2;
  if (o != -1) {
    std::vector<int> vec;
    for (int i = 1; i <= n; ++i) {
      if (op[i] == o) {
        if (o == 0) vec.emplace_back(a[i][0] - std::max(a[i][1], a[i][2]));
        else if (o == 1) vec.emplace_back(a[i][1] - std::max(a[i][0], a[i][2]));
        else vec.emplace_back(a[i][2] - std::max(a[i][0], a[i][1]));
      }
    }
    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < cnt[o] - n / 2; ++i) assert(i < vec.size()), sum -= vec[i];
  }
  std::cout << sum << '\n';
}

int32_t main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  int T = 1;
  std::cin >> T;
  while (T--) dickdreamer();
  // std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}