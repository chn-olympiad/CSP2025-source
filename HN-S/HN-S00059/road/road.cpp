#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace fisher{
const int N=1e4+15,M=1e6+5;
struct edge{
    int u,v,w;
    friend bool operator <(const edge &x,const edge &y){
        return x.w<y.w;
    }
}e[M],chos[N],ed[M];
int cnt;
int n,m,k,ans,c[N],a[15][N];
int tot,fa[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void kruskal1(){
    sort(e+1,e+m+1);
    iota(fa+1,fa+n+1,1);
    for(int i=1,u,v;i<=m;i++){
        u=find(e[i].u);v=find(e[i].v);
        if(u==v) continue;
        fa[u]=v;ans+=e[i].w;
        chos[++tot]=e[i];
    }
}
int kruskal2(int st){
    int res=0;
    for(int i=1;i<=tot;i++) ed[i]=chos[i];
    cnt=tot;
    for(int i=1;i<=k;i++) if((1<<(i-1))&st){
        // if(st==1) cout<<i<<' ';
        for(int j=1;j<=n;j++)
            ed[++cnt]=(edge){i+n,j,a[i][j]};
        res+=c[i];
    }
    // if(st==1) cout<<res<<'\n';
    sort(ed+1,ed+cnt+1);
    iota(fa+1,fa+n+k+1,1);
    for(int i=1,u,v;i<=cnt;i++){
        u=find(ed[i].u);v=find(ed[i].v);
        if(u==v) continue;
        fa[u]=v;res+=ed[i].w;
    }
    // cout<<st<<' '<<res<<'\n';
    return res;
}
signed ckt(){
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        e[i]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    // for(int i=1;i<=k;i++) cout<<c[i]<<" \n"[i==k];
    kruskal1();
    // cout<<ans<<'\n';
    for(int i=1;i<(1<<k);i++)
        ans=min(ans,kruskal2(i));
    cout<<ans<<'\n';
    return 0;
}}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    return fisher::ckt();
}