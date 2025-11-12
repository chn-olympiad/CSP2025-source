#include<bits/stdc++.h>
#define ll long long  
using namespace std;

const int maxn=1e4+10;
const int maxm=1e6+10;
int n,m,k,cnt,ct;
ll ans,cost;
int fa[maxn],pos[maxn],g[12];
int w[12][maxn];
struct node{
    int u,v,w;
    bool operator<(const node &nx)const{return w<nx.w;}
}c[maxm],a[maxn],e[maxn*10];
inline void ipt(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&c[i].u,&c[i].v,&c[i].w);   
    for(int i=1;i<=k;i++){
        scanf("%d",&g[i]);
        for(int j=1;j<=n;j++)scanf("%d",&w[i][j]);
    }
}
inline int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
inline bool merge(int u,int v){
    u=find(u),v=find(v);
    if(u==v)return false;
    fa[u]=v;
    return true;
}
inline void Kruskal(){
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(c+1,c+m+1);
    int n1=1;
    for(int i=1;i<=m;i++){
        if(merge(c[i].u,c[i].v)){
            ans+=(ll)(c[i].w);
            a[n1].u=c[i].u,a[n1].v=c[i].v,a[n1].w=c[i].w;
            ++n1;
            if(n1==n)break;
        }
    }
}
inline void make_graph(int S){
    cnt=n-1,cost=0,ct=0;
    for(int i=1;i<n;i++)e[i]=a[i];
    for(int i=1;i<=k;i++){
        if(S&(1<<(i-1))){
            pos[++ct]=i;
            cost+=(ll)(g[i]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=ct;j++){
            ++cnt;
            e[cnt].u=i;
            e[cnt].v=pos[j]+n;
            e[cnt].w=w[pos[j]][i];
        }
    }
}
inline void Kruskal2(){
    for(int i=1;i<=n+k;i++)fa[i]=i;
    sort(e+1,e+cnt+1);
    int n1=m+ct;
    for(int i=1;i<=cnt;i++){
        if(merge(e[i].u,e[i].v)){
            cost+=(ll)(e[i].w);
            --n1;
            if(n1==1)break;
        }
    }
    ans=min(ans,cost);
}
inline void solve(){
    for(int i=1;i<(1<<k);i++){
        make_graph(i);
        Kruskal2();
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ipt();
    Kruskal();
    solve();
    return 0;
}