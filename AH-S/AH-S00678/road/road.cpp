#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,M=1e4+10;;
int n,m,k,c[M],a[12][M],fa[N];
struct nd{
    int u,v,w;
};
nd g[N];
int find(int x){
    if(fa[x]==x){
        return x;
    }
    return find(fa[x]);
}
bool cmp(nd p,nd q){
    return p.w<q.w;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>g[i].u>>g[i].v>>g[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }

    sort(g+1,g+1+n,cmp);
    int tot=0,ans=0;
    for(int i=1;i<=m;i++){
        int u=find(g[i].u),v=find(g[i].v);
        if(u==v)continue;
        tot++,ans+=g[i].w;
        fa[v]=u;
        if(tot==n-1)break;
    }
    cout<<ans<<endl;
    return 0;
}
