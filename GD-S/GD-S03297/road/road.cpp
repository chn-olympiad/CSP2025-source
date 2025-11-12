#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4,M=1e6,K=10;
int n,m,k;
ll ans;
int tot;
struct edge{int u,v,w;}e[M+5],ne[N+N*K+5];
int fa[N+K+5];
int find(int x){return (fa[x]==x?x:(fa[x]=find(fa[x])));}
int c[K+5];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+1+m,[](edge x,edge y){return x.w<y.w;});
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        if(find(e[i].u)==find(e[i].v))continue;
        ans+=e[i].w;
        fa[find(e[i].u)]=find(e[i].v);
        ne[++tot]=e[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1,tmp;j<=n;j++)cin>>tmp,ne[++tot]={n+i,j,tmp};
    }
    sort(ne+1,ne+1+tot,[](edge x,edge y){return x.w<y.w;});
    for(int s=1;s<(1<<k);s++){
        ll res=0;
        for(int i=0;i<k;i++)if(s>>i&1)res+=c[i+1];
        if(res>=ans)continue;
        for(int i=1;i<=n+k;i++)fa[i]=i;
        for(int i=1;i<=tot;i++){
            if(ne[i].u>n&&((s>>(ne[i].u-n-1)&1)^1))continue;
            if(find(ne[i].u)==find(ne[i].v))continue;
            res+=ne[i].w;
            fa[find(ne[i].u)]=find(ne[i].v);
            if(res>=ans)break;
        }
        ans=min(ans,res);
    }
    cout<<ans;
}