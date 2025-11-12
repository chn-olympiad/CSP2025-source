#include<bits/stdc++.h>
using namespace std;
#define Open(x) FILE *filein=freopen(#x".in","r",stdin),*fileout=freopen(#x".out","w",stdout);
#define int long long
const signed N=3000005;
int ver[N],nxt[N],hd[N],da[N],tot;
void ad(int x,int y,int z){return ver[++tot]=y,nxt[tot]=hd[x],hd[x]=tot,da[tot]=z,void();}
void add(int x,int y,int z){return ad(x,y,z),ad(y,x,z);}
int n,m,k,ans;
int d[N],pre[N];
bool v[N];
priority_queue<pair<int,pair<int,int> > > q;
void dij(){
  memset(d,0x3f,sizeof(d));
  q.push(make_pair(0,make_pair(0,1))),d[1]=0;
  while(!q.empty()){
    int x=q.top().second.second,nw1=q.top().second.first,nw2=q.top().first;q.pop();
    // cout<<x<<'\n';
    if(v[x])continue;
    // if(x==3)cout<<"???:"<<nw1<<' '<<-nw2<<'\n';
    v[x]=1;
    pre[x]=nw1,d[x]=-nw2;
    for(int i=hd[x];i;i=nxt[i])if(!v[ver[i]]){
	// if(ver[i]==3)cout<<"dij:"<<x<<' '<<da[i]<<'\n';
	q.push(make_pair(-da[i],make_pair(x,ver[i])));
      }
  }
  return;
}
void dfs(int u){
  if(u==1||v[u])return;
  v[u]=1;
  ans+=d[u];
  return dfs(pre[u]);
}
signed main(){
  Open(road);
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m>>k;
  for(int i=1,x,y,z;i<=m;i++)cin>>x>>y>>z,add(x,y,z);
  for(int i=1;i<=k;i++){
    int val;
    cin>>val;
    ad(n+i,n+k+i,val);
    for(int j=1;j<=n;j++)cin>>val,ad(j,n+i,val),ad(n+k+i,j,val);
  }
  dij();
  memset(v,0,sizeof(v));
  for(int i=1;i<=n;i++)dfs(i);
  // for(int i=1;i<=n+k*2;i++)cout<<d[i]<<' '<<pre[i]<<'\n';
  cout<<ans<<'\n';
  return 0;
}
