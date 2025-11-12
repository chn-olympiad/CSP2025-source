#include<bits/stdc++.h>
#define FILE "road"
using namespace std;
using i64 = long long;

namespace FakeWilson {
const int N = 1e4 + 15;
const int M = 1e6 + 5;
const int K = 15;
int fa[N], a[K][N], mn[N], c[N];

void rd(int& x) {
    char ch = getchar(); x = 0;
    while(ch < '0' || ch > '9') ch = getchar();
    while('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}

struct Edge {
    int u, v, w;
} e1[M], e2[M << 1];

bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}

int find(int u) {
    if(fa[u] == u) return u;
    return fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    int x = find(u), y = find(v);
    if(x != y) fa[x] = y;
}

i64 kruskal(int n, int m) {
    sort(e1 + 1, e1 + 1 + m, cmp);
    for(int i = 1; i <= n; i++) fa[i] = i;
    int cnt = 0; i64 ans = 0;
    for(int i = 1; i <= m; i++) {
        int u = e1[i].u, v = e1[i].v;
        if(find(u) == find(v)) continue;
        merge(u, v), ans += e1[i].w, e2[++cnt] = e1[i];
    }
    return ans;
}

signed main() {
    int n, m, k;
    rd(n), rd(m), rd(k);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        rd(u), rd(v), rd(w);
        e1[i].u = u, e1[i].v = v, e1[i].w = w;
    }
    i64 ans = kruskal(n, m);
    for(int i = 1; i <= n - 1; i++) e1[i] = e2[i];
    for(int i = 1; i <= k; i++) {
        rd(c[i]);
        for(int j = 1; j <= n; j++) {
            rd(a[i][j]);
        }
    }
    for(int S = 1; S <= (1 << k) - 1; S++) {
        int cnt = n - 1; i64 cur_ans = 0;
        for(int i = 1; i <= k; i++) {
            if(!(S & (1 << (i - 1)))) continue;
            cur_ans += c[i];
            for(int j = 1; j <= n; j++) {
                if(!mn[j] || a[i][j] < a[mn[j]][j]) mn[j] = i;
            }
        }
        if(cur_ans >= ans) break;
        for(int i = 1; i <= cnt; i++) e2[i] = e1[i];
        for(int i = 1; i <= n; i++) {
            e2[++cnt].u = i, e2[cnt].v = mn[i] + n, e2[cnt].w = a[mn[i]][i];
            mn[i] = 0;
        }
        for(int i = 1; i <= n + k; i++) fa[i] = i;
        sort(e2 + 1, e2 + 1 + cnt, cmp);
        for(int i = 1; i <= cnt; i++) {
            int u = e2[i].u, v = e2[i].v;
            if(find(u) == find(v)) continue;
            if(cur_ans >= ans) break;
            merge(u, v), cur_ans += e2[i].w;
        }
        // if(cur_ans == 5095741225) cout << "QWQ" << S << endl;
        ans = min(ans, cur_ans);
    }
    printf("%lld", ans);
    return 0;
}

}

signed main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    return FakeWilson::main();
}

