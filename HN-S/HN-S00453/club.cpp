#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int kN = 1e5 + 5;
int n;
int a[kN][3];
int type[kN];

void Solve() {
  cin >> n;
  int cnt[3] = {0, 0, 0};
  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
    int p = max_element(a[i], a[i] + 3) - a[i];
    type[i] = p;
    cnt[type[i]]++;
    ans += a[i][type[i]];
  }
  for(int i : {0, 1, 2}) {
    if(cnt[i] <= n / 2) continue;
    priority_queue<ll> q;
    for(int j = 1; j <= n; j++) {
      if(type[j] == i) {
        int mx = 0;
        for(int k : {0, 1, 2}) {
          if(k != i) mx = max(mx, a[j][k]);
        }
        q.push(mx - a[j][type[j]]);
      }
    }
    while(cnt[i]-- > n / 2) ans += q.top(), q.pop();
    break;
  }
  cout << ans << "\n";
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while(t--) Solve();
  return 0;
}