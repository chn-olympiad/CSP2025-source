#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+15;
vector<pair<int, int>> G[N];
int Gtop;
int n, m, k;
pair<pair<int, int>, int> min_e;
const int INF = INT_MAX;
void inline add_edge(int u, int v, int w){
    G[u].push_back({v,w});
    G[v].push_back({u,w});
    if (w < min_e.second) min_e = {{u, v}, w};
}
void readG(){
    int u, v, w;
    min_e = {{0,0}, INF};
    for (int i = 0; i < m; i++){
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    Gtop = n;
}
bool vis[N];
int mintree(){
    memset(vis, 0, sizeof(vis));
    vis[min_e.first.first] = true;
    vis[min_e.first.second] = true;
    priority_queue<pair<int, int>> q;
    for (pair<int, int> e: G[min_e.first.first])
        q.push({-e.second, e.first});
    for (pair<int, int> e: G[min_e.first.second])
        q.push({-e.second, e.first});
    int ans = min_e.second;
    while (!q.empty()){
        while ((!q.empty()) && vis[q.top().second]) q.pop();
        if (q.empty()) break;
        ans += -q.top().first;
        int u = q.top().second;
        q.pop();
        vis[u] = true;
        for (pair<int, int> e: G[u])
            if (!vis[e.first]) q.push({-e.second, e.first});

    }
    return ans;
}
void readT(){
    for (int i = 0; i < k; i++){
        int c, a;
        cin >> c;
        int no = ++Gtop;
        // G[no].clear();
        for (int i = 1; i <= n; i++){
            cin >> a;
            if (!c){
                add_edge(i, no, a);
            }
        }
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> k;
    readG();
    readT();
    cout << mintree() << '\n';
    return 0;
}