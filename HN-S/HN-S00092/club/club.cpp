#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int>e;
int id[N], pa[N], pb[N], T, n, a, b, c, ans, cnt[4], maxx;

void Solve(){
  cin >> n;
  ans = 0;
  cnt[1] = cnt[2] = cnt[3] = 0;
  for(int i = 1; i <= n; ++i){
    cin >> a >> b >> c;
    maxx = max({a, b, c});
    if(maxx == a){
      id[i] = 1;
      pa[i] = a, pb[i] = max(b, c);
    }
    else if(maxx == b){
      id[i] = 2;
      pa[i] = b, pb[i] = max(a, c);
    }
    else{
      id[i] = 3;
      pa[i] = c, pb[i] = max(a, b);
    }
    cnt[id[i]]++;
    ans += pa[i];
  }
  //cout << ans << '\n';
  int pp = 1;
  if(cnt[2] > n / 2){
    pp = 2;
    swap(cnt[1], cnt[2]);
  }
  if(cnt[3] > n / 2){
    swap(cnt[1], cnt[3]);
    pp = 3;
  }
  if(cnt[1] <= n / 2){
    cout << ans << '\n';
    return ;
  }
  e.clear();
  for(int i = 1; i <= n; ++i){
    if(id[i] == pp){
      e.push_back(-pa[i] + pb[i]);
    }
  }
  sort(e.begin(), e.end());
  for(; cnt[1] > n / 2; cnt[1]--, e.pop_back()){
    ans += e.back();
  }
  cout << ans << '\n';
}

int main(){
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  for(cin >> T; T--; Solve()){
  }
  return 0;
}
/*

1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
