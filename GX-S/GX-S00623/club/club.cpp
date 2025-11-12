#include <bits/stdc++.h>
#define int long long
const int N = 1e5 +10;
using namespace std;

struct node{
  int id, f, val;
  bool operator < (const node& a) const {return val < a.val;}
  bool operator > (const node& a) const {return val > a.val;}
};

int T;
int n, a[N][5];
int ans, cnt[5], fa[N];
priority_queue<node>q;

void clean(){
  cnt[1] = cnt[2] = cnt[3] = 0;
  ans = 0;
  priority_queue<node>().swap(q);
}

void input(){
  cin>>n;
  for(int i = 1; i <= n; i ++){
    cin>>a[i][1]>>a[i][2]>>a[i][3];
  }
}

void tx(){
  for(int i = 1; i <= n; i ++){
    int mx = max({a[i][1], a[i][2], a[i][3]});
    if(a[i][1] == mx){
      cnt[1] ++;
      ans += a[i][1];
      fa[i] = 1;
    }
    else if(a[i][2] == mx){
      cnt[2] ++;
      ans += a[i][2];
      fa[i] = 2;
    }
    else if(a[i][3] == mx){
      cnt[3] ++;
      ans += a[i][3];
      fa[i] = 3;
    }
  }
}

void tj(int _){
  if(_ == 1){
    for(int i = 1; i <= n; i ++){
      if(fa[i] != _) continue;
      q.push({i, 2, a[i][2] - a[i][_]});
      q.push({i, 3, a[i][3] - a[i][_]});
    }
  }
  else if(_ == 2){
    for(int i = 1; i <= n; i ++){
      if(fa[i] != _) continue;
      q.push({i, 1, a[i][1] - a[i][_]});
      q.push({i, 3, a[i][3] - a[i][_]});
    }
  }
  else if(_ == 3){
    for(int i = 1; i <= n; i ++){
      if(fa[i] != _) continue;
      q.push({i, 1, a[i][1] - a[i][_]});
      q.push({i, 2, a[i][2] - a[i][_]});
    }
  }
  while(!q.empty()){
      int i = q.top().id, f = q.top().f, val = q.top().val;
      q.pop();
      if(fa[i] != _) continue;//already moved
      cnt[_] --;
      fa[i] = f;
      ans += val;
      if(cnt[_] <= n / 2) return;
    }
}

void solve(){
  clean();
  input();
  tx();
  if(cnt[1] > n / 2) tj(1);
  else if(cnt[2] > n / 2) tj(2);
  else if(cnt[3] > n / 2) tj(3);
  cout<<ans<<"\n";
}

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin>>T;
  while(T--){
    solve();
  }

  return 0;
}
