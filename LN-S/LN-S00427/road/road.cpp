#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;

#define vi vector<int>
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define bit(k) (1 << (k))
#define bin(s, k) (((s) >> (k)) & 1)
#define req(i, l, r) for (int i = l, i##End = r; i < i##End; i = -~i)
#define rep(i, l, r) for (int i = l, i##End = r; i <= i##End; i = -~i)

bool Mbe;

template<typename T, typename U> void chkmx(T &a, U b) { if (a < b) a = b; }
template<typename T, typename U> void chkmn(T &a, U b) { if (a > b) a = b; }

#define N 20005
#define M 1000005
#define mod 998244353
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

int n, m, k;
int fa[N];
int a[11][N];
struct edge { int u, v, w; } e[M], E[M];

int FA(int i) { return i == fa[i] ? i : fa[i] = FA(fa[i]); }

void mslv() {
    scanf("%d%d%d", &n, &m, &k);
    rep(i, 1, m) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        E[i] = {u, v, w};
    }
    auto cmp = [](edge u, edge v) { return u.w < v.w; };
    sort(E + 1, E + m + 1, cmp);
    rep(i, 1, n) fa[i] = i; int t = 0; i64 ans = 0;
    rep(i, 1, m) {
        int U = FA(E[i].u), V = FA(E[i].v);
        if (U == V) continue; fa[U] = V;
        e[++t] = E[i], ans += E[i].w;
    }
    rep(i, 1, k) rep(u, 0, n) scanf("%d", a[i] + u);
    req(s, 1, bit(k)) {
        i64 res = 0; t = 0;
        rep(i, 1, k) if (bin(s, i - 1)) {
            res += a[i][0];
            rep(u, 1, n) E[++t] = {u, n + i, a[i][u]};
        }
        sort(E + 1, E + t + 1, cmp);
        rep(i, 1, n + k) fa[i] = i;
        int I = 1, J = 1;
        while (I <= t && J < n) {
            int u, v, w;    
            if (E[I].w < e[J].w) u = E[I].u, v = E[I].v, w = E[I].w, I++;
            else u = e[J].u, v = e[J].v, w = e[J].w, J++;
            if (FA(u) != FA(v)) res += w, fa[FA(u)] = FA(v);
        }
        while (I <= t) {
            int u = E[I].u, v = E[I].v, w = E[I].w; I++;
            if (FA(u) != FA(v)) res += w, fa[FA(u)] = FA(v);
        }
        while (J < n) {
            int u = e[J].u, v = e[J].v, w = e[J].w; J++;
            if (FA(u) != FA(v)) res += w, fa[FA(u)] = FA(v);
        } chkmn(ans, res);
        // fprintf(stderr, "s = %d | res = %lld\n", s, res);
    } printf("%lld\n", ans);
}

void mprw() {}

bool Med;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    mprw(), mslv();
    #ifdef JYR
    fprintf(stderr, "%.2lfMB ", abs(&Mbe - &Med) / 1048576.);
    fprintf(stderr, "%.0lfms\n", clock() * 1000. / CLOCKS_PER_SEC);
    #endif
    return 0;
}