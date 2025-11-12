#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define ROF(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define int long long
using namespace std;
const int N = 1e4+20;
const int M = 1e6+5;
int n,m,k,c[11],a[11][N];
struct edge { int u,v,w; } e[M];
struct node { int v,w; };
struct node2 { 
    int u,d;
    bool operator<(const node2 &y) const {
        return d > y.d;
    }
};
vector<node> g[N];
void add(int u,int v,int w) { g[u].push_back({v,w}); }
int vis[N],dis[N];
int Prim(int k,int lim) {
//	printf("hi\n"); 
    priority_queue<node2> q;
    FOR(i,1,n+11) dis[i] = 1e18, vis[i]=0;
    q.push({1,0}); dis[1] = 0;
    int cnt = 0, res = 0;
    while(cnt < n+k) {
        int u = q.top().u, d = q.top().d; q.pop();
//        printf("u=%lld cnt=%lld res=%lld\n",u,cnt,res);
        if(vis[u]) continue;
        vis[u] = 1;
        cnt++; res += d;
        if(res > lim) return 1e18;
        for(auto to: g[u]) if(!vis[to.v]) {
            int v = to.v, w = to.w;
//            printf("v=%lld\n",v);
            if(dis[v] > w) {
                dis[v] = w;
                q.push({v,dis[v]});
            }
        }
    }
    return res;
}
void solve_A() {
    FOR(j,1,k) FOR(i,1,n) add(j+n,i,a[j][i]), add(i,j+n,a[j][i]);
    int ans = Prim(k,(int)1e18);
    printf("%lld\n",ans);
}
void solve() {
    int ans = 1e18;
    for(int s=0; s<(1ll<<k); s++) {
        int res = 0, cnt = 0;
        FOR(i,0,k-1) if(s&(1ll<<i)) {
            res += c[i+1]; cnt++;
            FOR(j,1,n) add(i+1+n,j,a[i+1][j]), add(j,i+1+n,a[i+1][j]);
        }
        res += Prim(cnt,ans-res);
        ans = min(ans, res);
        FOR(i,1,n) FOR(j,1,cnt) g[i].pop_back();
        FOR(i,0,k-1) if(s&(1ll<<i)) g[i+1+n].clear();
//    	printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
}
signed main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>k;
    FOR(i,1,m) {
        cin>>e[i].u>>e[i].v>>e[i].w; 
        add(e[i].u,e[i].v,e[i].w);
        add(e[i].v,e[i].u,e[i].w);
    }
    bool A = true;
    FOR(j,1,k) {
        cin>>c[j]; if(c[j]) A = false;
        FOR(i,1,n) cin>>a[j][i];
    }
    if(A) { solve_A(); return 0; }
    if(k == 0) { printf("%lld\n",Prim(0,(int)1e18)); return 0; }
    solve();
    return 0;
}
