#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10][10005],cnt,f[10015];
long long ans;
struct edge{
  int u,v,w;
}g[1000005],e[1024][10015];
bool cmp(edge a,edge b){
  return a.w<b.w;
}
int find(int x){
  return f[x]?f[x]=find(f[x]):x;
}
bool merge(int u,int v){
  return u=find(u),v=find(v),u==v?0:(f[v]=u,1);
}
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0),cin>>n>>m>>k;
  for(int i=1;i<=m;i++)cin>>g[i].u>>g[i].v>>g[i].w;
  sort(g+1,g+m+1,cmp);
  for(int i=1;i<=m;i++)if(merge(g[i].u,g[i].v))e[0][++cnt]=g[i],ans+=g[i].w;
  for(int i=0;i<k;i++)for(int j=0;j<=n;j++)cin>>a[i][j];
  for(int i=1;i<1<<k;i++){
    long long now=0;
    for(int j=0;j<k;j++)if(i>>j&1)now+=a[j][0];
    int u=__builtin_ctz(i);
    cnt=m=0;
    for(int j=1;j<=n+k;j++)f[j]=0;
    for(int j=1;j<n+__builtin_popcount(i)-1;j++)g[++m]=e[i&(i-1)][j];
    for(int j=1;j<=n;j++)g[++m]=(edge){n+u+1,j,a[__builtin_ctz(i)][j]};
    sort(g+1,g+m+1,cmp);
    for(int j=1;j<=m;j++)if(merge(g[j].u,g[j].v))e[i][++cnt]=g[j],now+=g[j].w;
    ans=min(ans,now);
  }
  return cout<<ans<<'\n',0;
}
