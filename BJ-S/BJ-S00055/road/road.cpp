#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL inf = 1e18;
const int N = 1e4 + 20;
const int M = 1e6 + 5;
LL c[20], a[20][N], ans1, ans2;
bool tag[20];
int n, m, k, fa[N+20], tot;
void init(int n) {
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}
int fd(int x) {
    if (x == fa[x]) return x;
    return fa[x] = fd(fa[x]);
}
struct Edge{
    int u, v, tag;
    LL w;
} edge1[M], edge2[N*15];
bool cmp(Edge A, Edge B) {
    return A.w < B.w;
}
void kruskal1() {
    init(n+15);
    int cnt = 0;
    sort(edge1+1, edge1+1+m, cmp);
    for(int i = 1; i <= m; i++) {
        int u = edge1[i].u, v = edge1[i].v;
        LL w = edge1[i].w;
        int fu = fd(u), fv = fd(v);
        if (fu == fv) continue;
        fa[fu] = fv;
        ans1 += w, cnt++;
        edge1[i].tag = 1;
        if (cnt == n-1) break;
    }
}
void kruskal2(int cntn) {
    init(n+15);
    int cnt = 0;
    for(int i = 1; i <= tot; i++) {
        int u = edge2[i].u, v = edge2[i].v;
        if (u > n && !tag[u-n]) continue;
        if (v > n && !tag[v-n]) continue;
        LL w = edge2[i].w;
        int fu = fd(u), fv = fd(v);
        if (fu == fv) continue;
        fa[fu] = fv;
        ans2 += w, cnt++;
        if (ans2 > ans1) return;
        if (cnt == cntn) break;
    }
}
void solve(int x) {
    ans2 = 0;
    int cntv = 0;
     for(int j = 1; j <= k; j++) {
        if ((x >> (k-j)) & 1) {
            ans2 += c[j];
            if (ans2 > ans1) return;
            cntv++;
            tag[j] = 1;
        } else tag[j] = 0;
    }
    kruskal2(n+cntv);
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++) {
        int u, v;
        LL w;
        scanf("%d%d%lld", &u, &v, &w);
        edge1[i].u = u, edge1[i].v = v, edge1[i].w = w;
    }
    for(int i = 1; i <= k; i++) {
        scanf("%lld", &c[i]);
        for(int j = 1; j <= n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    kruskal1();
    for(int i = 1; i <= m; i++) {
        if (edge1[i].tag == 1) {
            edge2[++tot] = edge1[i];
        }
    }
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            edge2[++tot].u = i+n, edge2[tot].v = j, edge2[tot].w = a[i][j];
        }
    }
    sort(edge2+1, edge2+1+tot, cmp);
    for(int i = 0; i < (1<<k); i++) {
        solve(i);
        ans1 = min(ans1, ans2);
    }
    printf("%lld\n", ans1);
    return 0;
}
