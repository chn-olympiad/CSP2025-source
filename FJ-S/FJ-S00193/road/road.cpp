#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e4 + 5;
const int M = 2e6 + 5;
inline int read() {
    int w = 1, q = 0; char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') q = q * 10 + ch - '0', ch = getchar();
    return w * q; 
}
struct node { int u, v, w, id; } tmp[M], e[M];
int n, ecnt, k, a[N], fa[N], ans;
inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
} 
bool cmp(node x, node y) { return x.w < y.w;  }
inline void kruskal(int msk) {
    int s = 0, cnt = 0;
    for (int i = 1; i <= n + k; i++) fa[i] = i; 
    for (int i = 0; i < k; i++) {
        if (msk >> i & 1) s+= a[i + 1]; 
        else cnt++;
    } 
    for (int i = 1; i <= ecnt && s <= ans; i++) {
        if (~e[i].id && (msk >> e[i].id & 1 ^ 1)) continue;
        int u = find(e[i].u), v = find(e[i].v);
        if (u ^ v) fa[u] = v, s += e[i].w, cnt++;
        if (cnt == n + k - 1) break;  
    } 
    ans = min(ans, s);
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int m; n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++)
        tmp[i].u = read(), tmp[i].v = read(), tmp[i].w = read();
    sort(tmp + 1, tmp + 1 + m, cmp);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int u = find(tmp[i].u), v = find(tmp[i].v), w = tmp[i].w;
        if (u ^ v) ans += w, fa[u] = v, e[++ecnt] = {tmp[i].u, tmp[i].v, w, -1};
    }
    for (int i = 1; i <= k; i++) {
        a[i] = read();
        for (int j = 1, w; j <= n; j++) 
            w = read(), e[++ecnt] = {i + n, j, w, i - 1};
    }
    sort(e + 1, e + ecnt + 1, cmp);
    for (int i = 0; i < (1 << k); i++) kruskal(i); 
    cout << ans << '\n';
    return 0; 
}