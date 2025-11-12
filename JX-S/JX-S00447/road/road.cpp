#include <bits/stdc++.h>
using namespace std;

#define L(i, j, k) for(int i = (j), _e = (k); i <= _e; ++i)
#define R(i, j, k) for(int i = (j), _e = (k); i >= _e; --i)
#define db(...) fprintf(stderr, __VA_ARGS__)
typedef long long ll;

#define gc getchar
void read(int& a) { char c; while (!isdigit(c = gc())); a = c - '0'; while (isdigit(c = gc())) a = a * 10 + c - '0'; }

constexpr int N = 1e4 + 20, M = 1e6 + 5, K = 15;
int n, m, k, tot;
struct edge { int u, v, w; bool operator<(const edge& b) const { return w < b.w; } } e[M + N * K];
int c[K];

struct uf {
    int f[N + K];
    void init(int n) { L(i, 0, n) f[i] = -1; }
    int find(int u) { return f[u] < 0 ? u : f[u] = find(f[u]); }
    void merge(int u, int v) { if (-f[u] < -f[v]) swap(u, v); f[u] += f[v], f[v] = u; }
} bf;

bool gk[K];
ll ans = 1e18;
edge t[M + N * K];
void getans() {
    int tot2 = 0;
    L(i, 1, tot) {
        int u = e[i].u;
        if (u <= n || gk[u - n]) t[++tot2] = e[i];
    }

    ll s = 0;
    L(i, 1, k) if (gk[i]) { s += c[i]; }

    bf.init(n + k);
    L(i, 1, tot2) {
        int u = bf.find(t[i].u), v = bf.find(t[i].v);
        if (u != v) bf.merge(u, v), s += t[i].w;
    }
    ans = min(ans, s);
}

void getk(int p) {
    if (p > k) { getans(); return; }
    gk[p] = false;
    getk(p + 1);
    gk[p] = true;
    getk(p + 1);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n); read(m); read(k);
    L(i, 1, m) { read(e[i].u); read(e[i].v); read(e[i].w); }
    tot = m;
    L(i, 1, k) {
        read(c[i]);
        L(j, 1, n) { int x; read(x); e[++tot] = (edge{i + n, j, x}); }
    } sort(e + 1, e + tot + 1);
    getk(1); printf("%lld\n", ans);
}

