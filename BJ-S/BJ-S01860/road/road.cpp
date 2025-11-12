

#include <cstdio>
#include <algorithm>
#define ll long long

using namespace std;

int N, M, K;
struct Edge {
    int u, v, w;
    const bool operator < (const Edge &b) const {return w < b.w;}
} ig[1000009], G[1024][10019], tg[20029], ot[10][10009];
ll C[1024];
int len[1024];
int Read () {
    int x = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return x;
}
int fa[10019];
int GetFa (int x) {
    if (x == fa[x]) return x;
    return fa[x] = GetFa(fa[x]);
}
int L2[1029];
ll res;
int main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    N = Read(), M = Read(), K = Read();
    for (int i = 0; i < K; i++) L2[1 << i] = i;
    for (int i = 1; i <= M; i++) ig[i].u = Read(), ig[i].v = Read(), ig[i].w = Read();
    for (int i = 0; i < K; i++) {
        C[1 << i] = Read();
        for (int j = 1; j <= N; j++) ot[i][j] = {i + N + 1, j, Read()};
        sort(ot[i] + 1, ot[i] + N + 1);
    }
    for (int i = 1; i <= N; i++) fa[i] = i;
    sort(ig + 1, ig + M + 1);
    int a, b, n = 0;
    for (int i = 1; i <= M; i++) {
        a = GetFa(ig[i].u), b = GetFa(ig[i].v);
        if (a != b) fa[a] = b, res += ig[i].w, G[0][++n] = ig[i];
    }
    len[0] = n;
    int p, tn; ll ans;
    for (int i = 1; i < (1 << K); i++) {
        p = L2[i & -i];
        merge(G[i ^ (1 << p)] + 1, G[i ^ (1 << p)] + len[i ^ (1 << p)] + 1, ot[p] + 1, ot[p] + N + 1, tg + 1);
        for (int j = 1; j <= N + K; j++) fa[j] = j;
        tn = len[i ^ (1 << p)] + N, n = 0;
        C[i] = C[i ^ (1 << p)] + C[1 << p], ans = C[i];
        for (int j = 1; j <= tn; j++) {
            a = GetFa(tg[j].u), b = GetFa(tg[j].v);
            if (a != b) fa[a] = b, ans += tg[j].w, G[i][++n] = tg[j];
        }
        len[i] = n;
        res = min(res, ans);
    }
    printf("%lld\n", res);
    return 0;
}