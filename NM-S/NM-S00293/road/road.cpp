// shinzanmonoWYB@hs2z
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
namespace IO{
  const int MAXSIZE=1<<21;
  char pbuf[MAXSIZE],*pb,*pe;
  #define gc() (pb==pe&&(pe=(pb=pbuf)+fread(pbuf,1,MAXSIZE,stdin),pb==pe)?EOF:*pb++)
  inline int read(){
    int x=0,f=1;
    char ch=gc();
    while(!isdigit(ch)){
      if(ch=='-')f=-1;
      ch=gc();
    }
    while(isdigit(ch))x=(x<<3)+(x<<1)+ch-'0',ch=gc();
    return x;
  }
}
using ll=long long;
const int sz=1e4+15;
struct edge{
  int u,v,w;
  edge(){}
  edge(int u,int v,ll w):u(u),v(v),w(w){}
  bool operator<(const edge &a)const{return w<a.w;}
};
std::vector<edge>graph,G;
struct UFS{
  int fa[sz],ssz[sz];
  void clear(int n){
    std::iota(fa+1,fa+n+1,1);
    std::fill(ssz+1,ssz+n+1,1);
  }
  int find(int u){
    if(fa[u]==u)return u;
    return fa[u]=find(fa[u]);
  }
  void merge(int u,int v){
    int fu=find(u),fv=find(v);
    if(fu==fv)return;
    if(ssz[fu]>ssz[fv])std::swap(fu,fv);
    fa[fu]=fv,ssz[fv]+=ssz[fu];
  }
}ufs;
int a[15],W[15][sz];
void file(std::string s){
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
using IO::read;
int main(){
  file("road");
  int n=read(),m=read(),k=read();
  for(int i=1,u,v,w;i<=m;i++)
    u=read(),v=read(),w=read(),graph.emplace_back(u,v,w);
  std::sort(graph.begin(),graph.end());
  ufs.clear(n);
  ll ans=0;
  int cnt=0;
  for(auto [u,v,w]:graph){
    if(ufs.find(u)==ufs.find(v))continue;
    G.emplace_back(u,v,w),ufs.merge(u,v),ans+=w,cnt++;
    if(cnt==n-1)break;
  }
  for(int i=1;i<=k;i++){
    a[i]=read();
    for(int j=1;j<=n;j++)W[i][j]=read();
  }
  for(int S=1;S<1<<k;S++){
    int N=n;
    graph=G;
    ll res=0;
    for(int k=S;k!=0;k-=k&-k){
      int j=std::__lg(k&-k)+1;
      ++N,res+=a[j];
      if(res>ans)continue;
      for(int i=1;i<=n;i++)graph.emplace_back(N,i,W[j][i]);
    }
    ufs.clear(N);
    int cnt=0;
    std::sort(graph.begin(),graph.end());
    for(auto [u,v,w]:graph){
      if(ufs.find(u)==ufs.find(v))continue;
      ufs.merge(u,v),cnt++,res+=w;
      if(cnt==N-1)break;
    }
    ans=std::min(ans,res);
  }
  printf("%lld\n",ans);
  return 0;
}