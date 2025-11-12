#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128
#define pii pair < int , int >
#define mp(i, j) make_pair(i, j)

/*
具体思路：首先容易发现只有原图上是最小生成树上的边才有可能是之后的边。
因此我们可以先把边数缩减到 O(n) 级别。然后注意到 k 很小，所以
不妨 2^k 枚举，然后进行一次 MST 。
令 t = 1e5，则
时间复杂度 O(2^k * tlogt + mlogm)
*/

const int N = 1e6 + 5;
int n, m, k, tot, fa[N], c[N];
ll ans = 1e18;
struct node {
    int u, v, w;
} e[N], ee[N];
bool cmp(node a, node b) { return a.w < b.w; }
vector < node > G[15];

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void kruscal() {
    for(int i = 1; i <= n; i++) fa[i] = i;
    sort(e + 1, e + 1 + m, cmp);
    for(int i = 1; i <= m; i++) {
        int u = find(e[i].u), v = find(e[i].v);
        if(u == v) continue;
        fa[u] = v; e[++ tot] = e[i];
    }
}

void Kruscal(ll res) {
    for(int i = 1; i <= n + k; i++) fa[i] = i;
    for(int i = 1; i <= tot; i++) ee[i] = e[i];
    sort(ee + 1, ee + 1 + tot, cmp);
    for(int i = 1; i <= tot; i++) {
        int u = find(ee[i].u), v = find(ee[i].v);
        if(u == v) continue;
        fa[u] = v, res += ee[i].w;
    }
    ans = min(ans, res);
}

int read() {
    int x = 0;
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for(int i = 1; i <= m; i++)
        e[i].u = read(), e[i].v = read(), e[i].w = read();
    for(int i = 1; i <= k; i++) {
        c[i] = read();
        for(int j = 1; j <= n; j++) {
            int w = read();
            G[i].push_back((node) { i + n, j, w });
        }
    }
    kruscal();
    for(int s = 0; s < (1 << k); s++) {
        tot = n - 1;
        ll res = 0;
        for(int i = 1; i <= k; i++)
            if((s >> i - 1) & 1){
                res += c[i];
                for(node v : G[i]) e[++ tot] = v;
            }
        Kruscal(res);
    }
    printf("%lld\n", ans);
    return 0;
}
