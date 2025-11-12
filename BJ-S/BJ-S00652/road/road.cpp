#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;
typedef long long ll;
const int N = 1e4+15;
struct edge{ int v; ll w; };
int n, m, k;
vector<edge> tr[N];
ll c[15];
bool bc[15];
ll dis[N];
bool vis[N];
ll ans, cc;

void check()
{
    mem(dis, 0x3f);
    mem(vis, 0);
    struct qnode{
        int u,d;
        bool operator<(const qnode &oth) const{
            return d>oth.d;
        }
    };
    priority_queue<qnode> q;
    q.push({1, dis[1]=0});
    ll cnt=cc;
    while (q.size()){
        qnode cur=q.top();
        q.pop();
        int u=cur.u;
        if (vis[u]) continue;
        vis[u] = true;
        cnt+=dis[u];
        for (int i=0; i<tr[u].size(); i++){
            int v=tr[u][i].v;
            if (v>n&&!bc[v-n]) continue;
            ll w=tr[u][i].w;
            if (w<dis[v]){
                q.push({v, dis[v]=w});
            }
        }
    }
    ans = min(ans, cnt);
}

void enu(int u){
    if (u>k){
        check();
        return;
    }
    bc[u] = 1;
    cc += c[u];
    enu(u+1);
    bc[u] = 0;
    cc -= c[u];
    enu(u+1);
}

void solve()
{
    ans = INF;
    enu(1);
    printf("%lld", ans);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1; i<= m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        tr[u].push_back({v, (ll)w});
        tr[v].push_back({u, (ll)w});
    }
    for (int i = 1, ci; i <= k; i++){
        scanf("%d", &ci);
        c[i] = (ll)ci;
        for (int j=1, x; j<=n; j++){
            scanf("%d", &x);
            tr[n+i].push_back({j, (ll)x});
            tr[j].push_back({n+i, (ll)x});
        }
    }
    solve();
    return 0;
}
