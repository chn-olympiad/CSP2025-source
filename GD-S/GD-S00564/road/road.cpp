#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define fi first
#define se second
using ll = long long;

map<pii, int> rpt;
int const inf = 0x3f3f3f3f;
int const N = 1e4 + 7;
vector<pii> g[N];
int val[N];
ll dis[N];
bool vit[N];
int n, m, k;
ll diff;
bool check0 = 0;
ll sum;

void Dijkstra(int st, int ed){
    diff = 0;
    for(int i = 1; i <= n; i++) {dis[i] = inf; vit[i] = 0;}
    dis[0] = inf, dis[st] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});

    while(!pq.empty()){
        auto p1 = pq.top();
        int d = p1.fi, u = p1.se;
        pq.pop();

        if(vit[u]) continue;
        vit[u] = 1;

        for(auto p2 : g[u]){
            int v = p2.fi, w = p2.se;
            if(dis[v] > dis[u] + w * 1ll){
                if(rpt[{min(u, v), max(u, v)}] == 1) diff += w;
                rpt[{min(u, v), max(u, v)}] ++;
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if(u == v) continue;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        sum += w;
    }
    for(int i = 1, f = 1; i <= k; i++){
        cin >> val[i]; if(val[i]) check0 = 1;
        for(int i = 1; i <= n; i++){
            int vl; cin >> vl;
            int u = i, v = (f++) + n;
            g[u].push_back({v, vl});
            g[v].push_back({u, vl});
            if(vl) check0 = 1;
        }
    }

    ll ans = 0;

    if(k == 0 || check0 == 0){
        cout << sum << "\n";
        return 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            Dijkstra(i, j);
            ans += dis[j];
        }
    }

    cout << ans - diff << "\n";

    return 0;
}


// Kasty's code
