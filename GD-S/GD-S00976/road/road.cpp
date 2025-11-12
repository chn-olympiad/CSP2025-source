#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 2e4 + 5, M = 2e6 + 5;
int n, m, k;
struct edge { int u, v, w; } ed[M], ed_[M];
int c[15], a[15][N];
bool exi[15];
int fa[N], siz[N];
void init() {  for (int i = 1; i < n + k; i++) fa[i] = i; }
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
ll kruskal(int m) {
    init();
    sort(ed + 1, ed + m + 1, [](const edge &a, const edge &b) { return a.w < b.w; });
    ll res = 0;
    for (int i = 1; i <= m; i++) {
        int u = ed[i].u, v = ed[i].v, w = ed[i].w;
        u = find(u), v = find(v);
        if (u == v) continue;
        fa[v] = u;
        res += w;
    }
    // for (int i = 2; i <= n; i++) if (find(i) != find(i - 1))return 1e18;
    return res;
}
double st=clock();
void read(int &x) {
    x = 0; int c;
    do c = getchar(); while (c < '0' || c > '9');
    while ('0' <= c && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
}
void write(const ll &x) {
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n), read(m), read(k);
    for (int i = 1; i <= m; i++) {
        int u, v, w; read(u), read(v), read(w);
        ed_[i] = {u, v, w};
    }
    for (int i = 1; i <= m; i++) ed[i] = ed_[i];
    if (k == 0) {
        write(kruskal(m));
        return 0;
    }
    int maxc = -1;
    for (int i = 1; i <= k; i++) {
        read(c[i]), maxc = max(maxc, c[i]);
        for (int j = 1; j <= n; j++) read(a[i][j]), exi[i] |= (a[i][j] == 0);
    }
    bool taskA = (maxc == 0);
    for (int i = 1; i <= k; i++) taskA &= exi[i];
    if (taskA) {
        // cerr << "taskA" << '\n';
        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= n; j++)
                ed[++m] = {i + n, j, a[i][j]};
        write(kruskal(m));
        return 0;
    }
    ll ans = 1e18;
    for (int cur = 0; cur < (1 << k); cur++) {
        memcpy(ed, ed_, sizeof(edge[m + 1]));
        ll cand = 0;
        for (int i = 1; i <= k; i++) if (cur >> (i - 1) & 1) cand += c[i];
        int mm = m;
        for (int i = 1; i <= k; i++) if (cur >> (i - 1) & 1) {
            for (int j = 1; j <= n; j++)
                ed[++mm] = {i + n, j, a[i][j]};
        }
        cand += kruskal(mm);
        ans = min(ans, cand);
    }
    write(ans);
    // cerr << clock() - st << "ms" << endl;
    return 0;
}
// 48~72pts