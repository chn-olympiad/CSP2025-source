#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
  int n, ans = 0; cin >> n;
  using pii = pair<int, int>;
  vector<vector<pii>> s(3);
  vector<int> a(3);
  for (int i = 1; i <= n; i++) {
    cin >> a[0] >> a[1] >> a[2];
    auto b = a;
    sort(b.begin(), b.end());

    int mx = b[2], val = b[2] - b[1];
    if (mx == a[0]) s[0].push_back({i, val});
    else if (mx == a[1]) s[1].push_back({i, val});
    else s[2].push_back({i, val});

    ans += mx;
  }
  int cnt = -1;
  for (int i : {0, 1, 2}) 
    if (s[i].size() > n / 2) cnt = i;
  if (cnt == -1) return cout << ans << endl, void();
  sort(s[cnt].begin(), s[cnt].end(), [&](pii x, pii y) {
    return x.second > y.second;
  });

  for (int i = n / 2; i < s[cnt].size(); i++)
    ans -= s[cnt][i].second;
  cout << ans << endl;
  return;
}
signed main() {
  freopen("club.in", "r", stdin), 
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  int T; cin >> T; while (T--) solve();
  return 0;
}