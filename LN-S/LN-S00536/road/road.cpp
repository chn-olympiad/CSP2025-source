#include <bits/stdc++.h>

using namespace std;

using ci = const int;
using ll = long long;

ci N = 1e4 + 10 + 5;
ci K = 10 + 5;

template <typename T>
inline void cmax(T& x,const T y) {if(y > x) x = y;}

template <typename T>
inline void cmin(T& x,const T y) {if(y < x) x = y;}

namespace qwq {
    struct node {
        int id;
        ll val;
        inline bool operator < (const node& x) const {
            return id > x.id;
        }
        node() {}
        node(int _id,ll _val) {
            id = _id;
            val = _val;
        }
    };
    vector <node> gr[N];
    priority_queue <node> q;
    ll dis[N];
    bool vis[N];
    int n,m,k;
    ll c[K];
    void dijkstra(int s) {
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        q.emplace(s,0);
        dis[s] = 0;
        node cur;
        while(!q.empty()) {
            cur = q.top();
            q.pop();
            if(vis[cur.id]) continue;
            vis[cur.id] = 1;
            for(auto e : gr[cur.id]) {
                if(cur.val + e.val < dis[e.id]) {
                    dis[e.id] = cur.val + e.val;
                    q.emplace(e.id,dis[e.id]);
                }
            }
        }
    }
    int qwq_main() {
        freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr),cout.tie(nullptr);
        cin >> n >> m >> k;
        ll w;
        for(int i = 1,u,v;i <= m;i++) {
            cin >> u >> v >> w;
            gr[u].emplace_back(v,w);
            gr[v].emplace_back(u,w);
        }/*
        for(int i = 1;i <= k;i++) {
            cin >> c[i];
            for(int j = 1,x;j <= n;j++) {
                cin >> x;
            }
        }*/
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            dijkstra(i);
            for(int j = 1;j <= n;j++) {
                if(i == j) continue;
                cmax(ans,dis[j]);
            }
        }
        cout << ans << endl;
        return 0;
    }
}

int main() {
    return qwq::qwq_main();
}