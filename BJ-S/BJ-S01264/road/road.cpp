#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=1e4+20,M=2e6,K=12;
struct node{int u,v,w;};
inline bool operator < (node x,node y){
    return x.w<y.w;
}
multiset <node> edge0,edge;
vector <node> add[K];
int f[N],sz[N],n,m,k,c[K];
ll ans=1e18,fund;
inline int find(int x){
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
inline void merge(int x,int y){
    if(sz[x]<sz[y]) swap(x,y);
    f[y]=x;
    sz[x]+=sz[y];
}
inline void init(){
    for(int i=1;i<=n;++i) f[i]=i,sz[i]=1;
    int cnt=n;
    ll tot=0;
    for(node e:edge0){
        int u=e.u,v=e.v,w=e.w,fu=find(u),fv=find(v);
        if(fu==fv) continue;
        --cnt,tot+=w,merge(fu,fv),edge.insert(e);
        if(cnt==1) break;
    }
    ans=tot;
    // cout<<"fund:"<<fund<<" tot="<<tot<<endl;
}
inline void Kruscal(int x){
    for(int i=1;i<=n+x;++i) f[i]=i,sz[i]=1;
    int cnt=n+x;
    ll tot=fund;
    // cout<<"tot="<<tot<<endl;
    for(node e:edge){
        int u=e.u,v=e.v,w=e.w,fu=find(u),fv=find(v);
        if(fu==fv) continue;
        --cnt,tot+=w,merge(fu,fv);
        if(cnt==1) break;
    }
    ans=min(ans,tot);
    // cout<<"fund:"<<fund<<" tot="<<tot<<endl;
}
inline void solve(int s){
    int x=(s^(s-1));
    int cnt=__builtin_popcount(s);
    for(int i=0;i<k;++i){
        if(!((x>>i)&1)) continue;
        if((s>>i)&1){
            fund+=c[i+1];
            for(node e:add[i+1]) edge.insert(e);
        }
        else{
            fund-=c[i+1];
            for(node e:add[i+1]) edge.erase(edge.find(e));
        }
    }
    Kruscal(cnt);
}
int main(){
    #ifndef wzh
        freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);
    #endif
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i){
        node tmp;
        scanf("%d%d%d",&tmp.u,&tmp.v,&tmp.w);
        edge0.insert(tmp);
    }
    for(int i=1;i<=k;++i){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;++j){
            int w;
            scanf("%d",&w);
            node tmp={i+n,j,w};
            add[i].push_back(tmp);
        }
    }
    init();
    for(int s=1;s<(1<<k);++s) solve(s);
    printf("%lld\n",ans);
    return 0;
}