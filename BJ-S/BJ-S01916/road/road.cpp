#include <bits/stdc++.h>
using namespace std;
const int N=10000+10;
const int M=2000000+10;
struct edge{
     int u,v;long long w;
     friend bool operator < (edge s1,edge s2){
         return s1.w<s2.w;
     }
}e[M];
struct county{
    int c;
    long long a[N];
}rd[20];
int n,m,k,pointru,pointrv;
int fa[N],sz[N];
long long ans=0;
priority_queue<edge> q;
void init(){
    for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
}
int find(int x){
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(sz[x]>sz[y]) swap(x,y);
    fa[x]=y;sz[y]+=sz[x];
}
bool cmp(edge s1,edge s2){return s1.w<s2.w;}
void kruskal(){
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(find(e[i].u)!=find(e[i].v)){
            ans+=e[i].w;
            merge(e[i].u,e[i].v);
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
    }
    int tot=m;
    for(int i=1;i<=k;i++){
        scanf("%d",&rd[i].c);
        for(int j=1;j<=n;j++){
            scanf("%lld",&rd[i].a[j]);
        }
    }
    for(int i=1;i<=k;i++){
        for(int u=1;u<=n;u++){
            for(int v=u+1;v<=n;v++){
                edge tmp;
                tmp.u=u,tmp.v=v,tmp.w=rd[i].c+rd[i].a[u]+rd[i].a[v];
                q.push(tmp);
                if(q.size()>m) q.pop();
            }
        }
    }
    while(!q.empty()){
        e[++m]=q.top();
        q.pop();
    }
    init();
    kruskal();
    printf("%lld\n",ans);
    return 0;
}
