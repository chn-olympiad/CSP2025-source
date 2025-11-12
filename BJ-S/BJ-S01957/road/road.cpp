#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
#define re register
const int maxn = 1e4 + 30;
const int N = 15;
int n, m, k, fa[maxn], sz[maxn], w[N], a[N][maxn], id[N][maxn];
bool vis[1 << N];
ll t, ans;
priority_queue<pli, vector<pli>, greater<pli> > pq;
vector<tuple<int, int, int> > g;
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (sz[x] > sz[y]) swap(x, y);
    fa[x] = y; sz[y] += sz[x];
}
ll calc(vector<tuple<int, int, int> >& g) {
    //sort(g.begin(), g.end()); 
    ll res = 0;
    for (re int i = 1; i <= n + k; i++) fa[i] = i, sz[i] = 1;
    for (auto [w, u, v] : g) if (find(u) != find(v)) res += w, merge(u, v);
    return res;
}
vector<tuple<int, int, int> > merge(const vector<tuple<int, int, int> >& a, const vector<tuple<int, int, int> >& b) {
    int l = 0, r = 0; vector<tuple<int, int, int> > c;   
    while (l < a.size() || r < b.size())
        if (l == a.size() || (r < b.size() && get<0>(b[r]) < get<0>(a[l]))) c.push_back(b[r++]);
        else c.push_back(a[l++]);
    return c;
}
ll f(int u) {
    ll sum = 0; vector<tuple<int, int, int> > E = g;
    for (re int i = 0; i < k; i++) if (u >> i & 1) {
        sum += w[i + 1]; vector<tuple<int, int, int> > cur;
        for (re int j = 1; j <= n; j++)
            cur.emplace_back(a[i + 1][j], i + n + 1, j);
        sort(cur.begin(), cur.end());
        E = merge(E, cur);
    } if (sum >= ans) return sum; return calc(E) + sum;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); srand(time(0));
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (re int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g.emplace_back(w, u, v);
    } sort(g.begin(), g.end()); ans = calc(g);
    for (re int i = 1; i <= k; i++) {
        cin >> w[i];
        for (re int j = 1; j <= n; j++) cin >> a[i][j];
        for (re int j = 1; j <= n; j++) id[i][j] = j;
        sort(id[i] + 1, id[i] + n + 1, [&](int x, int y) {return a[i][x] < a[i][y] ? x : y;});
    } pq.emplace(0, 0);
    while (pq.size()) {
        auto [W, u] = pq.top(); pq.pop(); if (clock() > 0.9 * CLOCKS_PER_SEC) break; 
        for (re int i = 0; i < k; i++) if (!(u >> i & 1) && !vis[u | (1 << i)]) {
            vis[u | (1 << i)] = true;
            if ((t = f(u | (1 << i))) < ans) pq.emplace(t, u | (1 << i)), ans = t;
        }
    } cout << ans << '\n';
    return 0;
}