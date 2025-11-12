#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=1;i<=(n);++i)
#define FILE(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define reb(i,n) for(int i=0;i<(n);++i)
#define ppct __builtin_popcount
#define pb push_back
using namespace std;
const int N=1e4+20,M=1e6+7,INF=1e18;
double Time(){
    return 1.*clock()/CLOCKS_PER_SEC;
}
void cmin(int&a,int b){
    if(a>b)a=b;
}
struct edge{
    int u,v,w;
}e[M],nw[N*12];
int c[15],tot,n,m,k,fa[N];
int man[15][N];
int find(int a){
    if(a==fa[a])return a;
    return fa[a]=find(fa[a]);
}
void Union(int x,int y){
    x=find(x);y=find(y);
    if(x!=y)fa[x]=y;
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int calc(int state){
    int now=0;
    reb(i,k)if((state>>i)&1)now+=c[i];
    rep(i,n+k)fa[i]=i;
    rep(i,tot){
        int u=nw[i].u,v=nw[i].v;
        if(u>n){
            if(!((state>>(u-n-1))&1))continue;
        }
        if(find(u)==find(v))continue;
        Union(u,v);now+=nw[i].w;
    }
    return now;
}
int solve(){
    cin>>n>>m>>k;
    rep(i,m)cin>>e[i].u>>e[i].v>>e[i].w;
    reb(i,k){
        cin>>c[i];
        rep(j,n)cin>>man[i][j];
    }
    sort(e+1,e+1+m,cmp);
    rep(i,n)fa[i]=i;
    int ans=0;
    rep(i,m){
        int u=e[i].u,v=e[i].v;
        if(find(u)==find(v))continue;
        Union(u,v);nw[++tot]=e[i];ans+=e[i].w;
        // cout<<"Use "<<u<<' '<<v<<'\n';
    }
    reb(i,k)rep(j,n)nw[++tot]=(edge){i+n+1,j,man[i][j]};
    sort(nw+1,nw+1+tot,cmp);
    reb(i,(1<<k)){
        if(i==0)continue;
        cmin(ans,calc(i));
    }
    cout<<ans<<'\n';
    return 0;
}
main(){
    FILE("road");
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    // cout<<Time()<<"\n";
    return 0;
}