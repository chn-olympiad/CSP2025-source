#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k,G[1009][1009],zzz;
int fa[10008],e;
long long ans;
struct edge{
   int u,v,w;
}a[1000010];
bool cmp(edge x1,edge x2){
   return x1.w<x2.w;
}
int find(int x){
   if(x==fa[x])
     return x;
   return find(fa[x]);
}
int merge(int p,int q){
   int fp=find(p),fq=find(q);
   if(fp==fq)  return 0;
   fa[fp]=fq;
   return 1;
}
int main()
{
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   cin>>n>>m>>k;
   for(int i=1;i<=m;i++)
     cin>>a[i].u>>a[i].v>>a[i].w;
   for(int i=1;i<=k;i++)
      for(int i=1;i<=n;i++)
        cin>>zzz;
   for(int i=1;i<=n;i++)
     fa[i]=i;
   sort(a+1,a+m+1,cmp);
   for(int i=1;i<=m;i++)
     if(merge(a[i].u,a[i].v)==1){
          ans+=a[i].w;
          e++;
          if(e==n-1) break;         
     } 
   cout<<ans;
   return 0;
}
