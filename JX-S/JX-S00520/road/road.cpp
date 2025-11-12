#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x) {
    x = 0; char ch = getchar(); bool ff = 0;
    while(ch < '0' || ch > '9') ff |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
    x = ff ? -x : x;
}
template <typename T, typename ...T1> void read(T &x, T1 &...x1) {
    read(x); read(x1...);
}
#define int long long
const int maxn = 2e4 + 5, maxm = 2e6 + 5;
int n, m, k;
int root[maxn];
int fid(int x) { return x == root[x] ? x : root[x] = fid(root[x]); }
void init() { for(int i = 1; i <= n + k; i ++) root[i] = i; }
void Merge(int u, int v) {
    int fu = fid(u), fv = fid(v);
    if(fu == fv) return;
    //cout << u << " " << v << " " << fu << " " << fv << endl;
    root[fu] = fv;
}
struct Edge {
    int u, v, w;
    bool cot;
    Edge(int u = 0, int v = 0, int w = 0, bool cot = 0): u(u), v(v), w(w), cot(cot) {}
    friend bool operator < (Edge e1, Edge e2) {
        return e1.w < e2.w;
    }
} edge[maxm];
bool vis[maxn];
void Solve() {
    read(n, m, k);
    init();
    //cout << n << endl;
    int tot = 0;
    for(int i = 1, u, v, w; i <= m; i ++) {
        read(u, v, w);
        edge[++ tot] = Edge(u, v, w, 0);
    }
    for(int i = 1, c; i <= k; i ++) {
        read(c);
        for(int j = 1, x; j <= n; j ++) {
            read(x);
            edge[++ tot] = Edge(n + i, j, x, 0);
            edge[++ tot] = Edge(n + i, j, x + c, 1);
        }
    }
    sort(edge + 1, edge + tot + 1);
    int ans = 0, sum = n, cnt = 0; //cout << tot << endl;
    for(int i = 1, u, v, w; i <= tot; i ++) {
        if(cnt == sum - 1) break;
        u = edge[i].u; v = edge[i].v; w = edge[i].w;
        if(fid(u) ^ fid(v)) {//cout << 1 << endl;
            //cout << u << " " << v << endl;
            bool op = edge[i].cot;
            int pos = u > n ? u : v;
            if(op == 1) {
                if(vis[pos]) continue;
                vis[pos] = 1;
                ans += w;
                sum ++;
                cnt ++;
            }
            else {
                if(pos <= n) ans += w;
                else {
                    if(!vis[pos]) continue;
                    ans += w;
                }
                cnt ++;
            }
            Merge(u, v);//cout << u << " " << v << " ";
            //cout << i << " " << ans << endl;
        }
    }
    printf("%lld\n", ans);
}
#undef int
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    Solve();
    return 0;
}
