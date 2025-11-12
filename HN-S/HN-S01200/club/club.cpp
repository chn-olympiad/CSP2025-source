#include <bits/stdc++.h>

using namespace std;

vector<int> b[3];
int T, n, ans, a[3];

void Solve() {
  cin >> n, ans = 0;
  b[0].clear(), b[1].clear(), b[2].clear();
  for (int i = 1; i <= n; i++) {
    cin >> a[0] >> a[1] >> a[2];
    int mx = max({a[0], a[1], a[2]});
    ans += mx;
    if (mx == a[0]) {
      b[0].push_back(a[0] - max(a[1], a[2]));
    } else if (mx == a[1]) {
      b[1].push_back(a[1] - max(a[0], a[2]));
    } else {
      b[2].push_back(a[2] - max(a[0], a[1]));
    }
  }
  if (b[0].size() < b[1].size()) swap(b[0], b[1]);
  if (b[0].size() < b[2].size()) swap(b[0], b[2]);
  sort(b[0].begin(), b[0].end());
  int k = max(0, int(b[0].size()) - n / 2);
  for (auto u : b[0]) {
    if (!k) break;
    k--, ans -= u;
  }
  cout << ans << '\n';
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  for (cin >> T; T--; ) {
    Solve();
  }
  return 0;
}
