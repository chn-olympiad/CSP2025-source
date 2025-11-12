#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e4+50,M=1e6+10;
int n,m,k,f[N],ans=1e18,cnt,tot,a[11][N],c[11];
int find(int k){
  if(f[k]==k) return k;
  return f[k]=find(f[k]);
}
struct edge{
  int u,v,w;
  friend bool operator <(edge x,edge y){
    return x.w<y.w;
  }
}e[2000010],e1[2000010],e2[2000010];
void solve(int st){
  for(int i=1;i<=n+k+1;i++) f[i]=i;
  tot=cnt;
  int ret=0;
  for(int i=1;i<=k;i++){
    if(st&(1<<(i-1))){
      ret+=c[i];
      for(int j=1;j<=n;j++) e1[++tot]={i+n,j,a[i][j]}; 
    }
  }
  sort(e1+1,e1+tot+1);  
  for(int i=1;i<=tot;i++){
    int fu=find(e1[i].u),fv=find(e1[i].v);
    if(fu!=fv) f[fv]=fu,ret+=e1[i].w;
  }
  ans=min(ans,ret);
}
signed main(){
  cin.tie(0)->ios::sync_with_stdio(0);
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++) f[i]=i;
  for(int i=1;i<=m;i++){
    int u,v,w;cin>>u>>v>>w;
    e[i]={u,v,w};
  }
  for(int i=1;i<=k;i++){
    cin>>c[i];
    for(int j=1;j<=n;j++) cin>>a[i][j];
  }
  sort(e+1,e+m+1);
  for(int i=1;i<=m;i++){
    int fu=find(e[i].u),fv=find(e[i].v);
    if(fu!=fv) e1[++cnt]={e[i].u,e[i].v,e[i].w},f[fv]=fu,ans+=e[i].w,e2[cnt]=e1[cnt];
  }
  for(int st=0;st<(1<<k);st++){
    solve(st);
    for(int i=1;i<=cnt;i++) e1[i]=e2[i];
  }
  cout<<ans<<endl;
  return 0;
}

/*
k is small
O(k^2*mlogn) bruce
*/
