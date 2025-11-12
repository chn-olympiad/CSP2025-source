#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cassert>
#include<algorithm>
using std::cin;
using std::cout;
#define db(x...) fprintf(stderr,x)
struct Code {
    Code() {
        freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);
        std::ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    }
    ~Code() {
        cout.flush();
        fclose(stdin);
        fclose(stdout);
    }
} code;
using ll=long long;
const int N=1e4+30,M=1e6+11,K=15;
const ll INF=1e18;
struct Edge {
    int u,v,w; 
    bool operator<(const Edge &a) const {
        return w<a.w;
    }
} ed[M],ms[M],tms[M]; 
int n,m,k;
int c[K],a[K][N];
int b[K][N];
std::vector<int> Q;
struct UFS {
    int fa[N];
    void init(int n) { for(int i=1;i<=n;i++) fa[i]=i; }
    int find(int u) { return fa[u]==u?u:fa[u]=find(fa[u]); }
    bool merge(int u,int v) {
        u=find(u),v=find(v);
        if(u==v) return 0;
        fa[v]=u;
        return 1;
    }
} ufs;
void Kruskal() {
    ufs.init(n);
    std::sort(ed+1,ed+m+1);
    int t=0;
    for(int i=1;i<=m;i++) {
        int u=ed[i].u,v=ed[i].v,w=ed[i].w;
        if(ufs.merge(u,v)) 
            tms[++t]={u,v,w};
    }
}
ll calc() {
    int ped=n-1,pnd=n;
    for(int i=1;i<=ped;i++)
        ms[i]=tms[i];
    for(auto i:Q) {
        pnd++;
        for(int j=1;j<=n;j++)
            ms[++ped]={pnd,j,a[i][j]};
    }
    ufs.init(pnd);
    std::sort(ms+1,ms+ped+1);
    ll rs=0;
    for(int i=1;i<=ped;i++) {
        int u=ms[i].u,v=ms[i].v,w=ms[i].w;
        if(ufs.merge(u,v)) 
            rs+=w;
    }
    return rs;
}
void Dfs(int i,ll cs,ll &rs) {
    if(i==k+1) {
        // if(b[k][1]!=INF)
        rs=std::min(rs,cs+calc());
        return;
    }
    // for(int j=1;j<=n;j++)
    //     b[i][j]=std::min(b[i-1][j],a[i][j]);
    Q.push_back(i);
    Dfs(i+1,cs+c[i],rs);
    Q.pop_back();
    // for(int j=1;j<=n;j++)
    //     b[i][j]=b[i-1][j];
    Dfs(i+1,cs,rs);
}
int main() {
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) {
        int u,v,w; cin>>u>>v>>w;
        ed[i]={u,v,w};
    }
    for(int i=1;i<=k;i++) {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    Kruskal();
    ll rs=INF;
    for(int i=1;i<=n;i++) b[0][i]=INF;
    // rs=calc();
    Dfs(1,0,rs);
    cout<<rs<<'\n';
    return 0;
}