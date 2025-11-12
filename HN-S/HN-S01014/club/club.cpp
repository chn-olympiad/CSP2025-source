#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define sz(x) (int)(x).size()
using ll = long long;

const int N = 1e5 + 10;
int n, a[N][3];

void proc() {
  cin >> n;
  rep(i, 1, n)
    rep(j, 0, 2) cin >> a[i][j];
  vector<int> id[3];
  ll ans = 0;
  rep(i, 1, n) {
    int j = max_element(a[i], a[i] + 3) - a[i];
    id[j].push_back(i);
    ans += a[i][j];
  }
  rep(i, 0, 2) {
    if(sz(id[i]) <= n / 2) continue;
    vector<int> cost;
    for(int j : id[i]) {
      int mi = 1e9;
      rep(k, 0, 2)
        if(k != i) mi = min(mi, a[j][i] - a[j][k]);
      cost.push_back(mi);
    }
    sort(begin(cost), end(cost));
    rep(j, 0, sz(id[i]) - n / 2 - 1) ans -= cost[j];
  }
  cout << ans << "\n";
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) proc();
}