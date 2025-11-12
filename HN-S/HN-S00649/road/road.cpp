#include<bits/stdc++.h>
using namespace std;
const int N=1e4,M=1e6,K=10;//remember to check!
int f[N+K+5],siz[N+K+5],c[K+5],tot,cnt,op[M*2+5],ck[K+5];//check size!
#define ll long long
ll ans,rans=1e18;
struct eg{
  int x,y,w,id;
  friend bool operator<(eg a,eg b){return a.w<b.w;}
}t[M*2+5];
int n,m,k;
int inline find(int x){if(f[x]==x)return x;return f[x]=find(f[x]);}
bool inline merge(int x,int y){
  x=find(x),y=find(y);
  if(x==y)return 0;
  if(siz[x]<=siz[y])f[x]=y,siz[y]+=siz[x];
  else f[y]=x,siz[x]+=siz[y];
  return 1;
}
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)f[i]=i;
  for(int i=1;i<=m;i++){
  cin>>t[i].x>>t[i].y>>t[i].w;t[i].id=0;tot++;
  }
  for(int i=1;i<=k;i++){
  cin>>c[i];
  for(int j=1;j<=n;j++){
  t[m+(i-1)*n+j].x=n+i;
  cin>>t[m+(i-1)*n+j].w;
  t[m+(i-1)*n+j].y=j;
  t[m+(i-1)*n+j].id=i;tot++;
  }}
  sort(t+1,t+tot+1);
  for(int i=1;i<=tot;i++){
  if(t[i].id!=0)op[i]=1;
  else{
  int x=find(t[i].x),y=find(t[i].y);
  if(x!=y)f[x]=y,op[i]=1;
  else op[i]=0;
  }
  }
  cnt=0;
  for(int i=1;i<=tot;i++){
  if(op[i]){cnt++;t[cnt].x=t[i].x,t[cnt].y=t[i].y,t[cnt].w=t[i].w,t[cnt].id=t[i].id;}
  }
  
  for(int i=0;i<(1<<k);i++){
  ck[0]=1;ans=0;
  for(int j=1;j<=n+k;j++)f[j]=j,siz[j]=1;
  for(int j=0;j<k;j++)if(i&(1<<j))ck[j+1]=1,ans+=c[j+1];else ck[j+1]=0;
  for(int j=1;j<=cnt;j++)
  if(ck[t[j].id]&&merge(t[j].x,t[j].y)){ans+=t[j].w;}
  rans=min(rans,ans);
  }
  cout<<rans<<"\n";
}
