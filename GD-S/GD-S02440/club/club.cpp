#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=100005;
int n,a[N][4],cnt[4],vis[N],ans,v[N];
void clear(){
  for(int i=1;i<=n;i++) a[i][1]=a[i][2]=a[i][3]=v[i]=vis[i]=0;
  cnt[1]=cnt[2]=cnt[3]=ans=0;
}
void solve(){
  cin>>n;
  clear();
  priority_queue<tuple<int,int,int>> q;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=3;j++)
      cin>>a[i][j]; 
  for(int i=1;i<=n;i++){
    if(a[i][1]==max(max(a[i][1],a[i][2]),a[i][3])) q.emplace(a[i][1]-max(a[i][2],a[i][3]),i,1),v[i]=1;
    else if(a[i][2]==max(max(a[i][1],a[i][2]),a[i][3])) q.emplace(a[i][2]-max(a[i][1],a[i][3]),i,2),v[i]=2;
    else if(a[i][3]==max(max(a[i][1],a[i][2]),a[i][3])) q.emplace(a[i][3]-max(a[i][2],a[i][1]),i,3),v[i]=3;
  }
  while(!q.empty()){
    auto [val,id,x]=q.top();q.pop();
    if(cnt[x]<n/2) cnt[x]++,ans+=a[id][x],vis[id]=1;
    // cout<<val<<' '<<a[id][x]<<' '<<id<<' '<<x<<endl;
  }
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      if(v[i]==1){
        if(a[i][2]>a[i][3]) q.emplace(a[i][2]-a[i][3],i,2);
        else q.emplace(a[i][3]-a[i][2],i,3);
      }
      else if(v[i]==2){
        if(a[i][1]>a[i][3]) q.emplace(a[i][1]-a[i][3],i,1);
        else q.emplace(a[i][3]-a[i][1],i,3);
      }
      else if(v[i]==3){
        if(a[i][1]>a[i][2]) q.emplace(a[i][1]-a[i][2],i,1);
        else q.emplace(a[i][2]-a[i][1],i,2);
      }
    }
  }
  while(!q.empty()){
    auto [val,id,x]=q.top();q.pop();
    if(cnt[x]<n/2) cnt[x]++,ans+=a[id][x],vis[id]=1;
    // cout<<val<<' '<<a[id][x]<<' '<<id<<' '<<x<<endl;
  }
  cout<<ans<<endl;
}
signed main(){
  cin.tie(0)->ios::sync_with_stdio(0);
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  int T;cin>>T;
  while(T--){
    solve();
  }
  return 0;
}
