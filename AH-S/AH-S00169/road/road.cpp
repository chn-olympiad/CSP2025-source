#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e4 + 25;
const int INF = 0x3f3f3f3f3f3f3f3f;
struct edge{
    int v;
    ll w;
};
struct node{
    int u;
    ll d;
    friend bool operator > (node a, node b){
        return a.d > b.d;
    }
};
struct node2{
    int u, lst;
    ll d;
    friend bool operator > (node2 a, node2 b){
        return a.d > b.d;
    }
};
int n, m, k;
ll ans, res, c[15], a[15][N], dis[N], outd[N];
bool vis[N];
vector <edge> G[N];

void prim(){
    priority_queue <node, vector <node>, greater <node> > Q;
    while(!Q.empty()) Q.pop();
    Q.push((node){1, 0});
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    while(!Q.empty()){
        int u = Q.top().u;
        ll d = Q.top().d;
        Q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        res += d;
        for(edge e : G[u]){
            int v = e.v;
            ll w = e.w;
            if(vis[v]) continue;
            if(dis[v] > w){
                dis[v] = w;
                Q.push((node){v, dis[v]});
            }
        }
    }
}
ll prim2(int s){
    //int tot = 0;
    priority_queue <node2, vector <node2>, greater <node2> > Q;
    ll res = 0;
    if(s > n) res = c[s - n];
    while(!Q.empty()) Q.pop();
    Q.push((node2){s, 0, 0});
    memset(outd, 0, sizeof(outd));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    while(!Q.empty()){
        int u = Q.top().u, fa = Q.top().lst;
        ll d = Q.top().d;
        Q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        //if(u <= n) tot++;
        if(fa > n) outd[fa - n]++;
        res += d;
        for(edge e : G[u]){
            int v = e.v;
            ll w = e.w;
            if(vis[v]) continue;
            if(v > n){
                if(dis[v] > w + c[v - n]){
                    dis[v] = w + c[v - n];
                    Q.push((node2){v, u, dis[v]});
                }
            }
            else{
                if(dis[v] > w){
                    dis[v] = w;
                    Q.push((node2){v, u, dis[v]});
                }
            }
        }
    }
    //for(int i = 1; i <= k; i++) cout << outd[i] << ' ';
    //cout << '\n';
    for(int i = 1; i <= k; i++)
        if(!outd[i]) res -= dis[i + n];
    return res;
}

int main(){

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        G[u].emplace_back((edge){v, w});
        G[v].emplace_back((edge){u, w});
    }
    bool f = 1;
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        if(c[i]) f = 0;
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            G[n + i].emplace_back((edge){j, a[i][j]});
            G[j].emplace_back((edge){n + i, a[i][j]});
        }
    }
    if(f){
        prim();
        cout << res << '\n';
        return 0;
    }
    else if(k <= 5 && n <= 1000){
        int U = (1 << k) - 1;
        ans = INF;
        for(int S = 0; S <= U; S++){
            res = 0;
            for(int i = 1; i <= n; i++){
                while(!G[i].empty() && G[i].back().v > n)
                    G[i].pop_back();
            }
            for(int i = 1; i <= k; i++){
                G[n + i].clear();
                if((S >> (i - 1)) & 1){
                    res += c[i];
                    for(int j = 1; j <= n; j++)
                        G[j].emplace_back((edge){n + i, a[i][j]}),
                        G[n + i].emplace_back((edge){j, a[i][j]});
                }
            }
            prim();
            ans = min(ans, res);
            //cout << S << ' ' << res << '\n';
        }
        cout << ans << '\n';
        return 0;
    }
    else{
        ans = prim2(1);
        for(int i = 1; i <= k; i++)
            ans = min(ans, prim2(i + n));
        cout << ans << '\n';
    }

    return 0;
}

