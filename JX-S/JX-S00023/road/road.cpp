#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i, x, y) for (int i = (x); i <= (y); i ++)
const int N = 1e7 + 2e6, M = 2e4 + 6;
int n, m, k, c[M], a[13][M], cnt, f[M], ans;
struct Edge{ int u, v, w; }e[N];
void rd(int& res){
    char c; int f = 0; res = 0;
    do c = getchar(), f |= c == '-'; while (c < '0' || c > '9');
    do res = (res << 3) + (res << 1) + c - 48, c = getchar();
        while (c >= '0' && c <= '9');
    res *= f ? -1 : 1;
}
bool cmp(Edge x, Edge y){ return x.w < y.w; }
int find(int x){
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ioss::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    rd(m), rd(n), rd(k), cnt = n;
    fr(i, 1, n) rd(e[i].u), rd(e[i].v), rd(e[i].w);
    fr(i, 1, m) f[i] = i;
    fr(i, 1, k){
        rd(c[i]);
        fr(j, 1, m) rd(a[i][j]);
        fr(j, 1, m) fr(k, j + 1, m) e[++ cnt].u = j, e[cnt].v = k,
            e[cnt].w = a[i][j] + a[i][k];
    }
    sort(e + 1, e + cnt + 1, cmp);
    for (int k = n - 1, i = 1; i <= cnt && k; i ++){
        if (find(e[i].u) != find(e[i].v))
            f[e[i].u] = e[i].v, k --, ans += e[i].w;
    }
    cout << ans;
    return 0;
}