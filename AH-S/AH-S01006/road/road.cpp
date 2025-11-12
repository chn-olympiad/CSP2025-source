#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll Read() {
    int sig = 1; ll x = 0; char c = getchar();
    while(!isdigit(c)) { if(c == '-') sig = -1; c = getchar(); }
    while(isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    return x * sig;
}
void Write(ll x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) Write(x / 10);
    putchar((x % 10) ^ 48);
}
const int N = 10105, M = 1000005;
struct Edge {
    int u, v; ll w;
    friend bool operator <(Edge x, Edge y) { return x.w < y.w; }
}e[M], e_[M];
struct DSU {
    int cnt, fa[N];
    void Init(int n) { cnt = n; for(int i = 1; i <= n; i++) fa[i] = i; }
    int Find_Root(int x) { return fa[x] == x ? x : fa[x] = Find_Root(fa[x]); }
    bool Check(int x, int y) { return Find_Root(x) == Find_Root(y); }
    void Join(int x, int y) { x = Find_Root(x), y = Find_Root(y); if(x != y) fa[x] = y, cnt--; } 
}dsu;
int n, m, k, cntedge, vis[15]; ll c[15];
int main() {
    freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
    int i, j; ll ans = 0; n = Read(), m = Read(), k = Read();
    for(i = 1; i <= m; i++) e[i].u = Read(), e[i].v = Read(), e[i].w = Read();
    sort(e + 1, e + m + 1), dsu.Init(n);
    for(i = 1; i <= m; i++) {
        if(dsu.cnt == 1) break;
        if(!dsu.Check(e[i].u, e[i].v)) dsu.Join(e[i].u, e[i].v), ans += e[i].w, e_[++cntedge] = e[i];
    }
    for(i = 1; i <= k; i++) {
        c[i] = Read();
        for(j = 1; j <= n; j++) e_[++cntedge] = {n + i, j, Read()};
    }
    sort(e_ + 1, e_ + cntedge + 1);
    for(i = 1; i < (1 << k); i++) {
        int popc = 0; ll res = 0; dsu.Init(n + k);
        for(j = 1; j <= k; j++) {
            vis[j] = (i >> (j - 1)) & 1;
            if(vis[j]) popc++, res += c[j];
        }
        popc = k - popc + 1;
        for(j = 1; j <= cntedge; j++) {
            if(dsu.cnt == popc) break;
            if((e_[j].u <= n || vis[e_[j].u - n]) && !dsu.Check(e_[j].u, e_[j].v)) {
                dsu.Join(e_[j].u, e_[j].v), res += e_[j].w;
            }
        }
        ans = min(ans, res);
    }
    Write(ans);
}