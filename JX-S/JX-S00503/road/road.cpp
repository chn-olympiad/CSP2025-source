#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXK = 15;
const int MAXN = 1e4 + 5;
int n, m, k, c[MAXK];

typedef long long ll;
ll ans = 0x3f3f3f3f3f3f3f3f;

struct edge { int u, v, w; };
vector<edge> extra[MAXK], mst;
vector<int> choice;

struct pqnd { int first, second; };
inline bool operator < (pqnd a, pqnd b) {
    return extra[a.first][a.second].w > extra[b.first][b.second].w;
} priority_queue<pqnd> pQ;

struct DisjointSet {

    int f[MAXN + MAXK];

    inline void reset() { for (int i = 1; i <= n + k; i ++) f[i] = i; }
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    inline bool conn(int x, int y) { return find(x) == find(y); }
    inline void merge(int x, int y) { f[find(x)] = find(y); }

} jdg;

inline void Fitness() {
    // only MST of ori-graph can be used
    jdg.reset(); for (edge e : extra[0])
        if (!jdg.conn(e.u, e.v)) jdg.merge(e.u, e.v), mst.push_back(e);
    swap(mst, extra[0]);
}

inline ll MST(ll res = 0) {
    jdg.reset(); while (!pQ.empty()) pQ.pop();
    int kw = choice.size() - 1;
    for (int i = 0; i <= kw; i ++) pQ.push({choice[i], 0});
    for (int cnt = 2; cnt <= n + kw; ) {
        pqnd pii = pQ.top(); pQ.pop();
        int exid = pii.first, qidx = pii.second;
        edge e = extra[exid][qidx]; if (!jdg.conn(e.u, e.v))
            cnt ++, res += e.w, jdg.merge(e.u, e.v);
        if (qidx + 1 < extra[exid].size()) pQ.push({exid, qidx + 1});
    } return res;
}

void dfs(int idx, ll sum = 0) {
    if (idx > k) return ans = min(ans, MST(sum)), void();
    dfs(idx + 1, sum);
    choice.push_back(idx);
    dfs(idx + 1, sum + c[idx]);
    choice.pop_back();
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        extra[0].push_back({u, v, w});
    } for (int i = 1; i <= k; i ++) {
        cin >> c[i];
        for (int j = 1; j <= n; j ++) {
            int v; cin >> v;
            extra[i].push_back({n + i, j, v});
        }
    } for (int i = 0; i <= k; i ++)
        sort(extra[i].begin(), extra[i].end(), [] (edge a, edge b) { return a.w < b.w; });
    Fitness(); choice.push_back(0); dfs(1); cout << ans; return 0;
}
