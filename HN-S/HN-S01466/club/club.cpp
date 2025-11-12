#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int MAXN = 1e5 + 3;

int n, a[MAXN][4], op[MAXN];
int tmp[3];

void work(){
  cin >> n;
  LL ans = 0;
  tmp[0] = tmp[1] = tmp[2] = 0;
  for(int i = 1; i <= n; i++){
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    int mx = max({a[i][0], a[i][1], a[i][2]});
    if(mx == a[i][0]){
      tmp[0]++, op[i] = 0;
    }else if(mx == a[i][1]){
      tmp[1]++, op[i] = 1;
    }else{
      tmp[2]++, op[i] = 2;
    }
    ans += a[i][op[i]];
  }
  if(max({tmp[0], tmp[1], tmp[2]}) <= n/2){
    cout << ans << "\n";
    return;
  }
  int o = 0;
  if(tmp[0] > n/2) o = 0;
  else if(tmp[1] > n/2) o = 1;
  else o = 2;
  int s = tmp[o] - n/2;
  vector<int> vt;
  for(int i = 1; i <= n; i++){
    if(op[i] == o){
      int xx, yy;
      if(o == 0) xx = a[i][1]-a[i][0], yy = a[i][2]-a[i][0];
      if(o == 1) xx = a[i][0]-a[i][1], yy = a[i][2]-a[i][1];
      if(o == 2) xx = a[i][0]-a[i][2], yy = a[i][1]-a[i][2];
      vt.push_back(max(xx, yy));
    }
  }
  sort(vt.begin(), vt.end());
  while(s > 0) s--, ans += vt.back(), vt.pop_back();
  cout << ans << "\n";
}
// g++ run.cpp -o run -std=c++14 -O2 -g -Wall -Wextra -fsanitize=address,undefined && time ./run
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  int T;
  cin >> T;
  while(T--){
    work();
  }
  return 0;
}