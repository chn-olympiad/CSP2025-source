#include<bits/stdc++.h>
using ll = long long;
using namespace std;
ll a[100005][3], c[100005], n, ans = 0;
vector<ll> v[3];
priority_queue<ll> q;
void solve() {
  cin >> n;
  ans = 0;
  while(!q.empty()) q.pop();
  for(int i = 0; i < 3; ++i) v[i].clear();
  for(int i = 1; i <= n; ++i) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    int t = 0, ww = 0;
    for(int j = 1; j < 3; ++j) {
      t = (a[i][t] > a[i][j] ? t : j);
    }
    v[t].push_back(i);
    if(t == 0) ww = (a[i][1] > a[i][2] ? 1 : 2);
    if(t == 1) ww = (a[i][0] > a[i][2] ? 0 : 2);
    if(t == 2) ww = (a[i][0] > a[i][1] ? 0 : 1);
    c[i] = a[i][t] - a[i][ww];
    ans += a[i][t];
  }
  ll Fx = v[0].size(), Fy = v[1].size(), Fz = v[2].size(), rt = 0;
  ll zz = 0;
  if(Fx <= n / 2 && Fy <= n / 2 && Fz <= n / 2) {
    cout << ans << endl;
    return;
  }
  if(Fx > n / 2) rt = 0, zz = Fx;
  if(Fy > n / 2) rt = 1, zz = Fy;
  if(Fz > n / 2) rt = 2, zz = Fz;
  for(auto x : v[rt]) q.push(-c[x]);
  while(zz > n / 2) {
    ans += q.top();
    q.pop();
    --zz;
  }
  cout << ans << endl;
}
int main() {
  // don't forget the erase the number!!!
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
