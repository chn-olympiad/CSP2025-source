#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
const int P=1e4+5;
int n,m,cnt,k,c[N];
int fa[N];
int diss[12][P];
int decos;
struct edge{
    int u,v,w;
}e[N<<1],g[N<<1];

void link(int id){
    for(int i=1;i<=n;++i){
        g[++cnt]={id+m,i,diss[id][i]};
    }
}
void getstat(int id){
    for(int i=1;i<=m;++i){
        g[i]=e[i];
    }cnt=m;decos=0;
    for(int i=1;i<=k;++i){
        if((1<<(i-1))&id){
            link(i);
            decos+=c[i];
        }
    }
}
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int find(int x){
    return x==fa[x]?x:find(fa[x]);
}
void merge(int x,int y){
    int p=find(x),q=find(y);
    if(p==q)return ;
    fa[p]=q;
}
long long kruscal(){
    sort(g+1,g+cnt+1,cmp);
    long long res=0;
    for(int i=1;i<=cnt;++i)fa[i]=i;
    for(int i=1;i<=cnt;++i){
        int u=g[i].u,v=g[i].v;
        int p=find(u),q=find(v);
        if(p==q)continue;
        merge(p,q); res=res+g[i].w;
    }
    return res+decos;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k; cnt=m;
    for(int i=1;i<=m;++i){
        int u,v;long long w;
        cin>>u>>v>>w;
        e[i]={u,v,w};
    }
    for(int i=1;i<=k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j){
            cin>>diss[i][j];
        }
    }
    long long ans=1e16;
    for(int i=0;i<(1ll<<k);++i){
        decos=0;
        getstat(i);
        ans=min(ans,kruscal());
    }
    cout<<ans<<'\n';
    return 0;
}