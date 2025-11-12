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
constexpr int N=1e4+100;
struct edge{
  int u,v,w;
  edge(int iu=0,int iv=0,int iw=0):u(iu),v(iv),w(iw){}
};
ll ans=1e18;
int n,m,k,cost[15],vis[3000];
vector<edge>tr[3000],add[15],e[15],tmp;
vector<edge> merge(vector<edge>& a,vector<edge>& b){
  int pa=0,pb=0,la=a.size(),lb=b.size(),lr=0;
  vector<edge>ret(la+lb);
  while(pa<la&&pb<lb){
    if(a[pa].w<b[pb].w)ret[lr++]=a[pa++];
    else ret[lr++]=b[pb++];
  }
  while(pa<la)ret[lr++]=a[pa++];
  while(pb<lb)ret[lr++]=b[pb++];
  return ret;
}
int pre[N];
int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}
ll pre_kru(vector<edge>&e,int tot,int op){
  ll ret=0,cnt=0;
  ffor(i,1,n+k)pre[i]=i;
  for(auto cur:e){
    int u=cur.u,v=cur.v,w=cur.w;
    int fu=find(u),fv=find(v);
    if(fu==fv)continue;
    pre[fu]=fv,ret+=w;
    if(op==0)add[0].eb(cur);
    else if(u==op+n)add[op].eb(cur);
    if(++cnt==tot-1)return ret;
  }
  assert(cnt==tot-1);
  return ret;
}
ll kru(vector<edge>&e,int tot,vector<edge>&chg){
  ll ret=0,cnt=0,lc=0;
  chg.clear(),chg.resize(tot-1);
  ffor(i,1,n+k)pre[i]=i;
  for(auto cur:e){
    int u=cur.u,v=cur.v,w=cur.w;
    int fu=find(u),fv=find(v);
    if(fu==fv)continue;
    pre[fu]=fv,ret+=w,chg[lc++]=cur;
    if(++cnt==tot-1)return ret;
  }
  assert(cnt==tot-1);
  return ret;
}
void dfs(int u,int lst){
  if(vis[u])return;
  vis[u]=1;
  int sz=__builtin_popcount(u);
  ll st=0;
  ffor(i,1,k)if(u&(1<<i))st+=cost[i];
  tr[u]=merge(add[__lg(lst^u)],tr[lst]);
  ans=min(ans,kru(tr[u],n+sz,tmp)+st),tr[u]=tmp;
  ffor(i,1,k)if(!(u&1<<i))dfs(u|1<<i,u);
}
int main(){
  cin.tie(0)->ios::sync_with_stdio(0);
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  cin>>n>>m>>k;
  ffor(i,1,m){
    int u,v,w;
    cin>>u>>v>>w;
    e[0].eb(u,v,w);
  }
  ffor(i,1,k){
    cin>>cost[i];
    ffor(j,1,n){
      int w;
      cin>>w;
      e[i].eb(i+n,j,w);
    }
  }
  ffor(i,0,k)sort(all(e[i]),[](edge x,edge y){return x.w<y.w;});
  ans=min(pre_kru(e[0],n,0),ans),tr[0]=add[0];
  ffor(i,1,k){
    vector<edge>to=merge(add[0],e[i]);
    ans=min(pre_kru(to,n+1,i)+cost[i],ans);
  }
  ffor(i,1,k)dfs(1<<i,0);
  cout<<ans;
  return 0;
}
//g++ -O2 code.cpp -o code -std=c++14 -Wall -Wextra -fsanitize=address,leak,undefined && time ./code 