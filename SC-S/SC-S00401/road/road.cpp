#include <bits/stdc++.h>
#define int long long
const int MAXN = 1e4 + 20; //1e4
const int MAXM = 1e6 + 20; //1e6

int read() {
    int x = 0, w = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

int n, m, k;
struct EDGE { int u, v, w; 
    friend bool operator < (const EDGE& lhs, const EDGE& rhs) { return lhs.w < rhs.w; }
} p[MAXM], lt[MAXN], ct[10][MAXN];
int elt = 0;

int buildct[10], a[10][MAXN];
struct POINTER { int typ, pos; 
    int getval() {
        if (typ == k) return lt[pos].w;
        else return ct[typ][pos].w;
    }
    EDGE getinf() {
        if (typ == k) return lt[pos];
        else return ct[typ][pos];
    }
    friend bool operator < (POINTER lhs, POINTER rhs) {
        return lhs.getval() > rhs.getval();
    }
};

namespace DSU {
    int fa[MAXN];
    void init() { for (int i = 0; i <= n + 11; i++) fa[i] = i; }
    int find(int x) { return fa[x] = (x == fa[x]) ? x : find(fa[x]); }
    void merge(int u, int v) {
        int fau = find(u), fav = find(v);
        if (u == v) return;
        fa[fav] = fau;
    }
} using namespace DSU;

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld %lld %lld", &n, &m, &k);
    for (int i = 1, u, v, w; i <= m; i++) {
        u = read(), v = read(), w = read();
        p[i] = {u, v, w};
    }
    for (int i = 0; i < k; i++) {
        scanf("%lld", &buildct[i]);
        for (int j = 1; j <= n; j++) scanf("%lld", &a[i][j]);
    }
    
    init();
    std::sort(p + 1, p + m + 1);
    for (int i = 1; i <= m; i++) {
        if (elt == n - 1) break;
        int u = p[i].u, v = p[i].v, w = p[i].w;
        if (find(u) != find(v)) {
            merge(u, v); lt[++elt] = {u, v, w};
        }
    }
    
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) ct[i][j] = {n + 1 + i, j, a[i][j]};
        std::sort(ct[i] + 1, ct[i] + n + 1);
    }
    
    /*我选择相信*/
    int ans = 1e18;
    for (int S = 0; S < (1 << k); S++) {
        std::priority_queue<POINTER> pq;
        while (!pq.empty()) pq.pop();
        pq.push({k, 1});
        int res = 0;
        for (int i = 0; i < k; i++) { if ((S >> i) & 1) pq.push({i, 1}), res += buildct[i]; }
        init();
        
        while (!pq.empty()) {
            POINTER nowpt = pq.top(); pq.pop();
            EDGE now = nowpt.getinf();
            
            int u = now.u, v = now.v, w = now.w;
            if (find(u) != find(v)) {
                merge(u, v); res += w;
                if (res > ans) break;
            }
            
            if (nowpt.typ == k) {
                if (nowpt.pos < n - 1) pq.push({nowpt.typ, nowpt.pos + 1});
            } else {
                if (nowpt.pos < n) pq.push({nowpt.typ, nowpt.pos + 1});
            }
        }
        ans = std::min(ans, res);
    }
    
    printf("%lld", ans);
    
    
    return 0;
}