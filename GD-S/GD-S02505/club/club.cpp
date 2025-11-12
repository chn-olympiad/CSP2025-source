#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr, ##__VA_ARGS__)
#else
#define debug(...) void(0)
#define endl "\n"
#endif
using LL = long long;
constexpr int N = 1e5 + 10;
int n, a[N][3];
int mian() {
  cin >> n;
  vector<int> vec[3];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) cin >> a[i][j];
    vec[max_element(a[i], a[i] + 3) - a[i]].push_back(i);
  }
  LL ans = 0;
  for (int j = 0; j < 3; j++) {
    int j1 = (j + 1) % 3, j2 = (j + 2) % 3;
    auto key = [&](int i) { return max(a[i][j1], a[i][j2]) - a[i][j]; };
    sort(vec[j].begin(), vec[j].end(), [&](int x, int y) { return key(x) < key(y); });
    for (int i = 0; i < min(n / 2, (int)vec[j].size()); i++) ans += a[vec[j][i]][j];
    for (int i = n / 2; i < (int)vec[j].size(); i++) ans += key(vec[j][i]) + a[vec[j][i]][j];
  }
  cout << ans << endl;
  return 0;
}
int main() {
#ifndef LOCAL
#ifndef NF
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
#endif
  int t;
  cin >> t;
  while (t--) mian();
  return 0;
}
