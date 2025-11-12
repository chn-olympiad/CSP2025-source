#include<bits/stdc++.h>
using namespace std;
#define N 2005
int n,m,k;
struct edge{
    int u,v,w;
}a[1000005];
int b[N];
int g[N][N];
int fa[N],cnt;
bool cmp(edge x,edge y){
    return x.w<y.w;
}
void init(){
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
bool same(int x,int y){
    return find(x)==find(y);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}
void kruskal(){
    long long ct=0,ans=0;
    init();
    for(int i=1;i<=cnt;i++){
        if(!same(a[i].u,a[i].v)){
            unite(a[i].u,a[i].v);
            ct++;
            ans+=a[i].w;
        }
        if(ct>=n-1) break;
    }
    cout<<ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    memset(g,0x3f,sizeof(g));
    for(int i=1,u,v,w;i<=m;i++){
       scanf("%d%d%d",&u,&v,&w);
        g[u][v]=g[v][u]=w;
    }

    for(int i=1,cost;i<=k;i++){
        scanf("%d",&cost);
        for(int j=1;j<=n;j++){
            scanf("%d",&b[j]);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(cost+b[i]+b[j]<g[i][j]){
                    g[i][j]=cost+b[i]+b[j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            a[++cnt].u=i;
            a[cnt].v=j;
            a[cnt].w=g[i][j];
        }
    }
    sort(a+1,a+cnt+1,cmp);
    kruskal();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
