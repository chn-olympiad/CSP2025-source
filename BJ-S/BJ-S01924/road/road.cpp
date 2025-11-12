#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr ll MAXN = 1e4 + 25;
struct Edge {
    ll u, v, w;
};
ll n, m, k;
ll c[MAXN], w[20][MAXN], fa[MAXN];
ll cnt[20];
vector <ll> del;
vector <Edge> edge, e;
bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}
ll find(ll u) {
    if(fa[u] == u)
        return u;
    return fa[u] = find(fa[u]);
}
void merge(ll u, ll v) {
    fa[find(u)] = find(v);
    return ;
}
ll kruskal(ll state, bool BYX) {
    ll ans = 0, knt = 0;
    e = edge;
    for(int i = 1; i <= k; ++i) {
        if((state >> (i - 1)) & 1) {
            ans += c[i];
            knt++;
            for(int j = 1; j <= n; ++j)
                e.push_back({n + i, j, w[i][j]});
        }
    }
    for(int i = 1; i <= n + k; i++)
        fa[i] = i;
    sort(e.begin(), e.end(), cmp);
    ll snt = 0;
    for(Edge it:e) {
        ll u = it.u, v = it.v, w = it.w;
        if(find(u) != find(v)) {
            merge(u, v);
            if(u > n)
                cnt[u-n]++;
            if(v > n)
                cnt[v-n]++;
            ans += w;
            snt++;
        }
        if(snt == n + knt - 1) {
            break;
        }
    }
    if(BYX)
        for(int i = 1; i <= k; ++i)
            if(cnt[i] == 1)
                del.push_back(i);
    return ans;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    for(int i = 1; i <= k; ++i) {
        cin >> c[i];
        for(int j = 1; j <= n; ++j)
            cin >> w[i][j];
    }
    if(k == 0) {
        cout << kruskal(0, 0);
        return 0;
    }
    ll ans = 1e18;
    for(int state = (1 << k) - 1; state >= 0; --state) {
        bool flag = 1;
        for(ll it:del)
            if((state >> (it - 1)) & 1) {
                flag = 0;
                break;
            }
        if(flag)
        ans = min(ans, kruskal(state, state == (1 << k) - 1));
    }
    cout << ans;
    return 0;
}