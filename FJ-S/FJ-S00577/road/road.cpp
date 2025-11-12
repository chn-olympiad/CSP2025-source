#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
const ll N=1e6+10,M=1e4+10;
struct edge{
    int u,v;
    ll w;
    bool operator<(const edge &x)const{
        return w<x.w;
    }
}e[N],a[10*M];
int n,m,k;
int fa[M];
ll c[12],w[12][M];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}
ll solve(int s){
    for(int i=1;i<=n+k;++i)fa[i]=i;
    int tot=__builtin_popcount(s),tmp=0;
    ll ans=0;
    for(int i=0;i<k;++i)if((s>>i)&1){
        ans+=c[i+1];
        for(int j=1;j<=n;++j)
        a[++tmp]={j,n+i+1,w[i+1][j]};
    }
    int cnt=0;
    sort(a+1,a+1+tmp);
    // for(int i=1;i<=tmp;++i)cout<<a[i].w<<" ";
    // cout<<ans<<"\n";
    e[m+1].w=a[tmp+1].w=2e9;
    for(int i=1,j=1;cnt<=tot+n&&(i<=m||j<=tmp);){
        int u,v;
        if(i<=m&&e[i].w<=a[j].w||j>tmp){
            u=find(e[i].u);
            v=find(e[i].v);
            if(u!=v){
                fa[u]=v;
                ++cnt;
                ans+=e[i].w;
            }
            ++i;
        }
        else{
            u=find(a[j].u);
            v=find(a[j].v);
            if(u!=v){
                fa[u]=v;
                ++cnt;
                ans+=a[j].w;
            }
            ++j;
        }
    }
    // cout<<ans<<"\n";
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
    sort(e+1,e+1+m);
    for(int i=1;i<=k;++i){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;++j)scanf("%lld",&w[i][j]);
    }
    ll ans=1e18;
    for(int i=0;i<1<<k;++i)ans=min(ans,solve(i));
    cout<<ans<<"\n";
}