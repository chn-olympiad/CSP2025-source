#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e4 + 5, M = 1e6 + 5;
struct graph{
    ll t, head[N];
    inline void clear(){
        t = 0;
        memset(head, 0, sizeof(head));
    }
    struct node{
        ll from, to, dis, nxt;
        bool operator < (const node &a) const{
            return dis < a.dis;
        }
    }edge[(M << 1) + (N << 5)];
    inline void add_edge(ll u, ll v, ll w){
        edge[++t] = (node){u, v, w, head[u]};
        head[u] = t;
    }
}g;
struct unionn{
    ll fa[N];
    inline void clear(){
        for(int i = 1; i < N; i++) fa[i] = i;
    }
    inline ll find(ll x){
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    inline void merge(ll x, ll y){
        fa[find(x)] = find(y);
    }
}uni;
ll n, m, k, country_w[15], country_edge_w[15][N], ans, mx;
inline void kruskal(){
    sort(g.edge + 1, g.edge + g.t + 1);
    ll cnt = 0;
    for(int i = 1; i <= g.t; i++){
        ll u = g.edge[i].from, v = g.edge[i].to, w = g.edge[i].dis;
        if(uni.find(u) == uni.find(v)) continue;
        ans += w;
        uni.merge(u, v);
        if(++cnt == n - 1){
            cout << ans;
            return;
        }
    }
}
namespace Chen_Three_1{
    void work(){
        kruskal();
    }
};
namespace Chen_Three_2{
    void work(){
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= n; j++){
                g.add_edge(n + i, j, country_edge_w[i][j]);
                g.add_edge(j, n + i, country_edge_w[i][j]);
            }
        }
        n += k;
        kruskal();
    }
}
namespace Chen_Three_3{
    void work(){
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= n; j++){
                if(country_w[i] > mx || !(rand() % 4)) continue;
                g.add_edge(n + i, j, country_edge_w[i][j]);
                g.add_edge(j, n + i, country_edge_w[i][j]);
                ans += country_w[i];
            }
        }
        n += k;
        kruskal();
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    g.clear(), uni.clear();
    cin >> n >> m >> k;
    ll u, v, w;
    for(int i = 1; i <= m; i++){
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
        g.add_edge(v, u, w);
    }
    if(!k){
        Chen_Three_1::work();
        return 0;
    }
    bool flag = 0;
    for(int i = 1; i <= k; i++){
        cin >> country_w[i];
        if(country_w[i]) flag = 1;
        for(int j = 1; j <= n; j++) cin >> country_edge_w[i][j];
    }
    if(!flag){
        Chen_Three_2::work();
    }else{
        Chen_Three_3::work();
    }
    return 0;
}
