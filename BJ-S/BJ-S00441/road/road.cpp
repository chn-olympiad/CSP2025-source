#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e4 + 10;
struct node {
    int u, v, w;
    bool operator < (const node &r) const {
        return w > r.w;
    }
};
int n, m, k, sz[maxn], fa[maxn], sum[maxn];
vector<pair<int, int>> v;
priority_queue<node, vector<node>> pq;
int find(int x) { return fa[x] == x ? x : find(fa[x]); }
void merge(int x, int y, int w) {
    fa[y] = x; sz[x] += sz[y]; sum[x] += (sum[y] + w);
    if (sz[x] == n) {
        cout << sum[x] << "\n";
        exit(0);
    }
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        pq.push({u, v, w});
    }
    for (int i = 1; i <= n; i++) sz[i] = 1, fa[i] = i;
    while (pq.size()) {
        int u = pq.top().u, v = pq.top().v, w = pq.top().w; pq.pop();
        int ru = find(u), rv = find(v);
        if (ru == rv) continue;
        merge(ru, rv, w);
    }
    return 0;
}

// 16 pts