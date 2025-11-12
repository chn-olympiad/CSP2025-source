#include<bits/stdc++.h>

#define int long long
#define pb push_back
#define mkp std::make_pair
using Edge=std::pair<int,std::pair<int,int> >;

const int N=10005;
struct Town{
    int c;
    int w[N];
    int rk[N];
};
Town to[10];

int n,m,k;
int x,y; int w;

std::vector<Edge> ori,ava;

struct DSU{
    int fa[N+10];
    void init(){
        for(int i=1;i<=n+k;i++) fa[i]=i;
        return;
    }
    int find(int x){
        if(x==fa[x]) return x;
        else return fa[x]=find(fa[x]);
    }
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return;
        fa[x]=y;
        return;
    }
}dsu;

int read(){
    int res=0; char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){
        res=(res<<3)+(res<<1)+(c^48);
        c=getchar();
    }
    return res;
}

int ans=1e18;
void dfs(int lvl,std::vector<Edge> vec,int bas){
    if(lvl>=k) return;
    dfs(lvl+1,vec,bas);
    bas+=to[lvl].c;
    int cnt=bas;
    std::vector<Edge> nv,nxt;
    int p=0;
    for(int i=1;i<=n;i++){
        int u=to[lvl].rk[i];
        int w=to[lvl].w[u];
        while(p<vec.size()){
            if(vec[p].first>w) break;
            nv.pb(vec[p]);
            ++p;
        }
        nv.pb(mkp(w,mkp(u,n+lvl+1)));
    }
    dsu.init();
    for(Edge x:nv){
        int u=x.second.first,v=x.second.second;
        if(dsu.find(u)==dsu.find(v)) continue;
        dsu.merge(u,v);
        cnt+=x.first;
        nxt.pb(x);
    }
    ans=std::min(ans,cnt);
    dfs(lvl+1,nxt,bas);

    return;
}

int tid;
bool cmp(int u,int v){
    return to[tid].w[u]<to[tid].w[v];
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    n=read(),m=read(),k=read();
    for(int i=0;i<m;i++){
        x=read(),y=read(),w=read();
        ori.pb(mkp(w,mkp(x,y)));
    }
    std::sort(ori.begin(),ori.end());
    for(int i=0;i<k;i++){
        to[i].c=read(); for(int j=1;j<=n;j++) to[i].w[j]=read(),to[i].rk[j]=j;
        tid=i;
        std::sort(to[i].rk+1,to[i].rk+n+1,cmp);
    }
    dsu.init();
    int cnt=0;
    for(Edge x:ori){
        int u=x.second.first,v=x.second.second;
        if(dsu.find(u)==dsu.find(v)) continue;
        cnt+=x.first;
        dsu.merge(u,v);
        ava.pb(x);
    }
    ans=cnt;
    dfs(0,ava,0);
    std::cout<<ans<<'\n';

    return 0;
}
