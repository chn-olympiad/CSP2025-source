#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1.5e4+5,M=1.5e6+5;
int n,m,k,ans;
struct edge{int u,v,w;}E[M];
struct DSU{
    int fa[N];
    inline void init(){
        for(int i=1;i<=n;i++)fa[i]=i;
        return;
    }
    inline int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
}dsu;
inline bool cmp(edge x,edge y){return x.w<y.w;}
inline void kru(){
    sort(E+1,E+m+1,cmp);dsu.init();
    int cnt=0;
    for(int i=1;i<=m;i++){
        int u=dsu.getfa(E[i].u),v=dsu.getfa(E[i].v),w=E[i].w;
        if(u==v)continue;
        dsu.fa[u]=v;ans+=w;cnt++;
        if(cnt==n-1)break;
    }
    return;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        E[i]={u,v,w};
    }
    kru();
    cout<<ans<<'\n';
    return 0;
}