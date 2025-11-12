#include <bits/stdc++.h>
using namespace std;

int t, n, x, y, z, ans;
multiset<int, greater<int> > st[3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  for(cin >> t; t--; ) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> x >> y >> z;
      ans += max({x, y, z});
      if(x == max({x, y, z})) st[0].insert(max(y, z) - x);
      else if(y == max({x, y, z})) st[1].insert(max(x, z) - y);
      else st[2].insert(max(x, y) - z);
    }
    for(int i = 0; i < 3; i++) {
      for(; st[i].size() > n / 2; st[i].erase(st[i].begin())) ans += *st[i].begin();
    }
    cout << ans << '\n';
    st[0].clear(), st[1].clear(), st[2].clear(), ans = 0;
  }
	return 0;
}
