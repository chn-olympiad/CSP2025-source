#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 1;

int a[MAX][3], tt[3];

priority_queue<int> d;

int t, n, u = 0, ans = 0;

inline void wk(int ux){
  u = 0;
  while(d.size()) d.pop();
  for(int i = 1, x = 0; i <= n; i++){
    if(!ux) x = 1;
    else x = 0;
    for(int j = 0; j < 3; j++){
      if(j == ux) continue;
      if(a[i][x] < a[i][j]) x = j;
    }
    u += a[i][x];
    d.push(a[i][ux] - a[i][x]);
  }
  for(int i = 1; i <= n / 2; i++){
    u += d.top();
    d.pop();
  }
  ans = max(ans, u);
}

inline void cl(){
  memset(tt, 0, sizeof(tt));
  ans = u = 0;
}

inline void solve(){
  cin >> n;
  cl();
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 3; j++){
      cin >> a[i][j];
    }
  }
  for(int i = 1, ux = 0; i <= n; i++){
    for(int j = 0; j < 3; j++){
      if(a[i][ux] < a[i][j]) ux = j;
    }
    if(tt[ux] >= n / 2){
      u = 0;
      break;
    }
    ++tt[ux];
    u += a[i][ux];
  }
  ans = max(ans, u);
  for(int i = 0; i < 3; i++){
    wk(i);
  }
  cout << ans << '\n';
}

int main(){
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
