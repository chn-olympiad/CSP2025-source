#include <bits/stdc++.h>

#define fst first
#define snd second

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

const long long MOD1 = 998244353;
const long long MOD2 = 1000000007;
const long long MOD3 = 1000000009;

using ll = long long;
using ld = long double;
using namespace std;
const int N = 10005, M = 1000005, K = 15;
struct Edge { 
    int u, v, w; 
    bool operator < (const Edge& t) const { return w < t.w; }
} E[M], tmp[M + K * N];
int n, m, k;
ll ans = LMX;
int fa[N + K], c[K], a[K][N];
int find_root(int u) {
    if (fa[u] == u) return u;
    return fa[u] = find_root(fa[u]);
}
ll solve(int m, int n, Edge E[]) {
    ll res = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    sort(E + 1, E + 1 + m);
    for (int i = 1, cnt = 0; i <= m; i++) {
        if (cnt == n - 1) break;
        int sx = find_root(E[i].u), sy = find_root(E[i].v);
        if (sx != sy) res += E[i].w, fa[sx] = sy, cnt++;
    }
    return res;
}
void read(int& x) {
    x = 0; char c = getchar();
    for (; !isdigit(c); c = getchar());
    for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
}
void read(ll& x) {
    x = 0; char c = getchar();
    for (; !isdigit(c); c = getchar());
    for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n); read(m); read(k);
    for (int i = 1; i <= m; i++) read(E[i].u), read(E[i].v), read(E[i].w);
    for (int i = 1; i <= k; i++) { read(c[i]); for (int j = 1; j <= n; j++) read(a[i][j]); }
    for (int s = 0; s < (1 << k); s++) {
        ll sum = 0;
        int nm = m, nn = n;
        for (int i = 1; i <= m; i++) tmp[i] = E[i];
        for (int i = 1; i <= k; i++) {
            if ((s >> i - 1) & 1) {
                nn++, sum += c[i];
                for (int j = 1; j <= n; j++) tmp[++nm] = {nn, j, a[i][j]};
            }
        }
        sum += solve(nm, nn, tmp);
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}