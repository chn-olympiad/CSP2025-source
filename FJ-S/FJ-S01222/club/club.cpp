#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define pb emplace_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

constexpr int N = 1e5 + 5;
int n, a[N][3], b[N][3];

void work() {
  cin >> n;
  int c[3] {}, ans = 0;//10^5 * 2*10^4
  vector<int> vec;
  for (int i = 1; i <= n; ++i) {
    for (auto &j : a[i]) {
      cin >> j;
    }
    iota(b[i], b[i] + 3, 0);
    sort(b[i], b[i] + 3, [&](int x, int y) {
      return a[i][x] > a[i][y];
    });
    ++c[b[i][0]];
    ans += a[i][b[i][0]];
  }
  int mx = max_element(c, c + 3) - c;
  for (int i = 1; i <= n; ++i) {
    if (mx == b[i][0]) {
      vec.pb(a[i][b[i][1]] - a[i][b[i][0]]);
    }
  }
  sort(all(vec), greater<int>());
//  clog << "#" << ans << ' ' << c[mx] << ' ' << mx << endl;
  for (auto v : vec) {
    if (c[mx] > n / 2) {
      --c[mx];
      ans += v;
    }
  }
  cout << ans << '\n';
}

signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int test;
  for (cin >> test; test--; ) {
    work();
  }
  return 0;
}
