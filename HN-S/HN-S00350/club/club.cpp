#include<bits/stdc++.h>
using namespace std;
using ll =long long;
using ull = unsigned long long;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
using ar3 = array<int,3>;
#define fi first
#define se second
#define ep emplace
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define ffor(i,l,r) for(int i=(l),_=(r);i<=_;i++)
#define rfor(i,r,l) for(int i=(r),_=(l);i>=_;i--)
void solve(){
  int n;
  cin>>n;
  vector<vector<int>>a(n+1,vector<int>(4,0));
  vector<int>bel[4];
  ffor(i,1,n)ffor(j,1,3)cin>>a[i][j];
  ll ans=0;
  ffor(i,1,n){
    int mx=max({a[i][1],a[i][2],a[i][3]});
    ans+=mx;
    if(mx==a[i][1])bel[1].eb(i);
    else if(mx==a[i][2])bel[2].eb(i);
    else if(mx==a[i][3])bel[3].eb(i);
  }
  int sz=bel[1].size();
  if(sz>n/2){
    // cerr<<"SB1";
    sort(all(bel[1]),[&](int x,int y){return a[x][1]-max(a[x][2],a[x][3])<a[y][1]-max(a[y][2],a[y][3]);});
    for(auto v:bel[1]){
      ans-=a[v][1]-max(a[v][2],a[v][3]);
      if(--sz<=n/2)break;
    }
  }
  sz=bel[2].size();
  if(sz>n/2){
    // cerr<<"SB2";
    sort(all(bel[2]),[&](int x,int y){return a[x][2]-max(a[x][1],a[x][3])<a[y][2]-max(a[y][1],a[y][3]);});
    for(auto v:bel[2]){
      ans-=a[v][2]-max(a[v][1],a[v][3]);
      if(--sz<=n/2)break;
    }
  }
  sz=bel[3].size();
  if(sz>n/2){
    sort(all(bel[3]),[&](int x,int y){return a[x][3]-max(a[x][2],a[x][1])<a[y][3]-max(a[y][2],a[y][1]);});
    for(auto v:bel[3]){
      ans-=a[v][3]-max(a[v][2],a[v][1]);
      if(--sz<=n/2)break;
    }
  }
  cout<<ans<<'\n';
}
int main(){
  cin.tie(0)->ios::sync_with_stdio(0);
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  int T;
  cin>>T;
  while(T--)solve();
  return 0;
}
//g++ -o2 code.cpp -o code -std=c++14 -Wall -Wextra -fsanitize=address,leak,undefined && time ./code 