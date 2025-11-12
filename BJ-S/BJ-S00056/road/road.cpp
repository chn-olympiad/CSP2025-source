#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 10015;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k, c[15], dis[N];
bool vis[N];
struct Edge{
    int v, w, idx;
};
struct Node{
    int dis, u;
    bool operator < (const Node &rhs) const {
        return dis > rhs.dis;
    }
};
vector<Edge> to[N];

int solve(const int S){
    int rtn = 0;
    for(int i = 1; i <= n+k; i ++)
        dis[i] = INF, vis[i] = false;
    for(int i = 1; i <= k; i ++)
        if((S & (1 << (i-1))) == 0)
            rtn += c[i];
    dis[1] = 0;
    priority_queue<Node> pq;
    pq.push({0, 1});
    while(! pq.empty()){
        const int u = pq.top().u;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        rtn += dis[u];
        for(auto item: to[u]){
            if(!(S & (1 << (item.idx-1)))){
                const int v = item.v, w = item.w;
                if(dis[v] > w && (!vis[v]))
                    pq.push({dis[v] = w, v});
            }
        }
    }
    return rtn;
}

signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int u, v, w, ans = INF;
    bool flag = true;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++){
        cin >> u >> v >> w;
        to[u].push_back({v, w, 0});
        to[v].push_back({u, w, 0});
    }
    for(int i = 1; i <= k; i ++){
        cin >> c[i];
        if(c[i]) flag = false;
        int cnt = 0;
        for(int j = 1; j <= n; j ++){
            cin >> w;
            if(w) ++cnt;
            to[n+i].push_back({j, w, i});
            to[j].push_back({n+i, w, i});
        }
        if(cnt == n)
            flag = false;
    }
    if(flag)
        ans = solve(0);
    else
        for(int S = 0; S < (1 << k); S ++)
            ans = min(ans, solve(S));
    cout << ans << endl;
    return 0;
}
