#include<bits/stdc++.h>
using namespace std;
using i64=long long;
int n,m,K,a[10][10010];
namespace dsu{
int fa[10020];
int fr(int u){return fa[u]?fa[u]=fr(fa[u]):u;}
inline bool merge(int x,int y){
   if((x=fr(x))!=(y=fr(y)))return fa[x]=y,true;
   return false;
}
void init(){
   for(int i=1;i<=n+10;i++)fa[i]=0;
}
}
struct E_{int u,v,w;bool operator<(const E_&o)const{return w<o.w;}};
E_ b[10][10010],t[1<<10][10020],c[20020];
int main(){
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   scanf("%d%d%d",&n,&m,&K);
   vector<E_>edge0,Te0;
   for(int u,v,w;m--;){
      scanf("%d%d%d",&u,&v,&w);
      edge0.push_back({u,v,w});
   }
   for(int i=0;i<K;i++){
      for(int j=0;j<=n;j++)scanf("%d",&a[i][j]),b[i][j]={n+i+1,j,a[i][j]};
      sort(b[i]+1,b[i]+n+1);
   }
   sort(begin(edge0),end(edge0));
   i64 ans=0;
   for(E_ e:edge0)if(dsu::merge(e.u,e.v)){
      Te0.push_back(e),ans+=e.w;
   }
   for(int i=0;i<Te0.size();i++)t[0][i+1]=Te0[i];
   for(int s=1;s<(1<<K);s++){
      int N=__builtin_popcount(s),u=__builtin_ctz(s),os=s^(1<<u);
      merge(t[os]+1,t[os]+n+N-1,b[u]+1,b[u]+n+1,c+1);
      dsu::init();
      i64 w=0;
      for(int i=0;i<K;i++)if(s>>i&1)w+=a[i][0];
      for(int i=1,p=0;i<=n+N-2+n;i++)if(dsu::merge(c[i].u,c[i].v)){
         w+=c[i].w;
         t[s][++p]=c[i];
      }ans=min(ans,w);
   }printf("%lld\n",ans);
   return 0;
}