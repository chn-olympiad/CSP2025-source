#include<bits/stdc++.h>
using namespace std;
const int N=2e4+7,M=2e6+7,E=15;
int n,m,K,fa[N],cnt,pcnt;
using ll=long long;
struct sline{int u,v;ll w;}l[M],us[N],pl[M];
ll ans,c[E],ct[E][N];
int getfa(int u){return (fa[u]==u)?(u):(fa[u]=getfa(fa[u]));}
void solve(int S){
    pcnt=cnt;
    ll pans=0;
    for(int i=1;i<=cnt;++i)
        pl[i]=us[i];
    for(int i=1;i<=K;++i)if(S&(1<<(i-1))){
        pans+=c[i];
        for(int j=1;j<=n;++j){
            pl[++pcnt]={i+n,j,ct[i][j]};
        }
    }
    sort(pl+1,pl+pcnt+1,[](sline a,sline b){return a.w<b.w;});
    for(int i=1;i<=n+K;++i)
        fa[i]=i;
    for(int i=1;i<=pcnt;++i){
        int u=getfa(pl[i].u),v=getfa(pl[i].v);
        if(u==v)
            continue;
        fa[u]=v;
        pans+=pl[i].w;
    }
    ans=min(ans,pans);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>K;
    for(int i=1;i<=m;++i)
        cin>>l[i].u>>l[i].v>>l[i].w;
    sort(l+1,l+m+1,[](sline a,sline b){return a.w<b.w;});
    for(int i=1;i<=n;++i)
        fa[i]=i;
    for(int i=1;i<=m;++i){
        int u=getfa(l[i].u),v=getfa(l[i].v);
        if(u==v)
            continue;
        us[++cnt]=l[i];
        fa[u]=v;
        ans+=l[i].w;
    }
    for(int i=1;i<=K;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j) cin>>ct[i][j];
    }
    for(int S=1;S<(1<<K);++S) solve(S);
    cout<<ans<<endl;
    return 0;
}