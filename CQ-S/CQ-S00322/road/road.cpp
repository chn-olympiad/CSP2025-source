#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 5;
int n, m, m0, k;
struct edge {
    int u, v, w;
    bool operator < (const edge& o)const { return w < o.w; }
}e[N], E[N >> 3];
int town[15][N / 100 + 5];
int disc[N], s;
int fa[N / 10], siz[N / 10];
inline void init(int n) { for (int i = 1;i <= n;++i) fa[i] = i, siz[i] = 1; }
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) {
    if (siz[x] > siz[y]) fa[y] = x, siz[x] += siz[y];
    else fa[x] = y, siz[y] += siz[x];
}
inline void kruskal0() {
    init(n);
    sort(e + 1, e + m0 + 1);
    for (int i = 1;i <= m0;++i) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) continue;
        merge(x, y);
        e[++m] = e[i];
        disc[++s] = e[i].w;
    }
}
typedef pair<int, int> pii;
#define mkp make_pair
int head[N >> 2], nxt[N >> 2];
pii lis[N >> 2];
int cnte;
inline void add(int x, pii val) {
    nxt[++cnte] = head[x];
    head[x] = cnte;
    lis[cnte] = val;
}
inline LL kruskal(int msk) {
    cnte = 0;
    for (int i = 1;i <= s;++i) head[i] = 0;
    int nn = n, mm = 0;
    for (int i = 1;i <= m;++i) add(e[i].w, mkp(e[i].u, e[i].v));
    for (int i = 0;i < k;++i)
        if (msk >> i & 1) {
            ++nn;
            for (int j = 1;j <= n;++j) add(town[i][j], mkp(j, nn));
        }
    for (int i = 1;i <= s;++i)
        for (int p = head[i];p;p = nxt[p]) E[++mm] = { lis[p].first, lis[p].second, disc[i] };
    init(nn);
    LL ret = 0;
    for (int i = 1;i <= mm;++i) {
        int x = find(E[i].u), y = find(E[i].v);
        if (x == y) continue;
        merge(x, y);
        ret += E[i].w;
        if (siz[x] == nn || siz[y] == nn) return ret;
    }
    return ret;
}
inline void read(int& x) {
    x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n);read(m);read(k);
    for (int i = 1;i <= m;++i) { read(e[i].u); read(e[i].v); read(e[i].w); }
    m0 = m;m = 0;
    kruskal0();
    for (int i = 0;i < k;++i)
        for (int j = 0;j <= n;++j) {
            read(town[i][j]);
            if (j) disc[++s] = town[i][j];
        }
    sort(disc + 1, disc + s + 1);
    for (int i = 1;i <= m;++i) e[i].w = lower_bound(disc + 1, disc + s + 1, e[i].w) - disc;
    for (int i = 0;i < k;++i)
        for (int j = 1;j <= n;++j) town[i][j] = lower_bound(disc + 1, disc + s + 1, town[i][j]) - disc;
    LL ans = 1e18;
    for (int msk = 0;msk < 1 << k;++msk) {
        LL sum = 0;
        for (int j = 0;j < k;++j)
            if (msk >> j & 1) sum += town[j][0];
        sum += kruskal(msk);
        ans = min(ans, sum);
    }
    printf("%lld", ans);
    return 0;
}