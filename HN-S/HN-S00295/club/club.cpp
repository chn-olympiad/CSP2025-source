#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int T, n, cnt[5], a[N][5];
vector<long long> g[5];

void Solve(){
  cin >> n;
  long long ans = 0;
  for(int i = 1; i <= 3; i++) cnt[i] = 0;
  for(int i = 1; i <= 3; i++) g[i].clear();
  for(int i = 1; i <= n; i++){
    cin >> a[i][1] >> a[i][2] >> a[i][3];
    int mx = -1, h = 0, mmx = -1;
    for(int j = 1; j <= 3; j++){
      if(a[i][j] > mx){
        mmx = mx;
        mx = a[i][j], h = j;
      }
      else if(a[i][j] > mmx){
        mmx = a[i][j];
      }
    }
    cnt[h]++;
    ans += mx;
    g[h].push_back(mx - mmx);
  }
  for(int i = 1; i <= 3; i++){
    if(cnt[i] > n / 2){
      sort(g[i].begin(), g[i].end());
      reverse(g[i].begin(), g[i].end());
      while(cnt[i] > n / 2){
        cnt[i]--;
        ans -= g[i].back();
        g[i].pop_back();
      }
    }
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  for(cin >> T; T--; Solve()){
  }
  return 0;
}
