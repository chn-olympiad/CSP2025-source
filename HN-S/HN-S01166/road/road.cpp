#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, k, ans;

signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    ans += w;
  }
  cout << ans << '\n';
  return 0;
}
