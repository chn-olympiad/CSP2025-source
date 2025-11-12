#include<bits/stdc++.h>
using namespace std;
int n,m,K;
struct edge{
   int u,v,w;
   bool friend operator < (const edge &a,const edge &b){
      return a.w<b.w; 
   }
}E[1000005];
int father[100005];
int find(int x){
   return father[x]==x?x:father[x]=find(father[x]);
}
void unionn(int x,int y){
   return father[find(x)]=find(y),void();
}
vector<edge> D;
vector<edge> need[10];
int cost[10];
vector<edge> qeta[1<<10];
int lowbit(int x){return x&-x;}
int main(){
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   scanf("%d%d%d",&n,&m,&K);
   for(int i=1;i<=m;i++){
      scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
   }
   sort(E+1,E+1+m);
   for(int i=1;i<=n;i++){
      father[i]=i;
   }
   for(int i=1;i<=m;i++){
      if(find(E[i].u)!=find(E[i].v)){
         // printf("%d %d %d\n",E[i].u,E[i].v,E[i].w);
         unionn(E[i].u,E[i].v);
         D.push_back(E[i]);
      }
   }
   for(int i=0;i<K;i++){
      scanf("%d",&cost[i]);
      for(int j=1;j<=n;j++){
         int w;
         scanf("%d",&w);
         need[i].push_back(edge{n+i+1,j,w});
      }
      sort(need[i].begin(),need[i].end());
   }
   qeta[0]=D;
   long long ans=1e18;
   for(int S=0;S<(1<<K);S++){
      vector<edge> neta=qeta[S-lowbit(S)];
      vector<edge> meta;
      long long sum=0;
      for(int i=0;i<K;i++){
         if((S>>i)&1)sum+=cost[i];
         if((1<<i)==lowbit(S)){
            meta=need[i];
         }
      }
      vector<edge> lst;
      int L=0,R=0;
      while(L<neta.size()&&R<meta.size()){
         if(neta[L]<meta[R]){
            lst.push_back(neta[L++]);
         }
         else{
            lst.push_back(meta[R++]);
         }
      }
      while(L<neta.size())lst.push_back(neta[L++]);
      while(R<meta.size())lst.push_back(meta[R++]);
      neta=lst;
      for(int i=1;i<=n+K;i++)father[i]=i;
      for(int i=0;i<neta.size();i++){
         // printf("(%d,%d,%d)\n",neta[i].u,neta[i].v,neta[i].w);
         if(find(neta[i].u)!=find(neta[i].v)){
            qeta[S].push_back(neta[i]);
            unionn(neta[i].u,neta[i].v);
            sum+=neta[i].w;
         }
      }
      // printf("%lld\n",sum);
      ans=min(ans,sum);
   }
   printf("%lld\n",ans);
   return 0;
}