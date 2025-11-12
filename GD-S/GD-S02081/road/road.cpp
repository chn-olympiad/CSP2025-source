#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4 + 50, maxm = 1e6 + 50, K = 15;

int n, m, k, c[K], a[K][maxn], f[maxn];
ll ans, res;

struct node{
    int u, v, w;
    bool operator < (const node &nd) const{ return w < nd.w; }
} r[maxm], e[maxn], E[maxn * 11];

int getf(int a){ return f[a] == a ? a : f[a] = getf(f[a]); }

int popcount(int x){
    int res = 0;
    while(x) res += x & 1, x >>= 1;
    return res;
}

int main(){
    // freopen("D:/down/road/road1.in", "r", stdin);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) f[i] = i;
    for(int i = 1; i <= m; i++){
        cin >> r[i].u >> r[i].v >> r[i].w;
    }
    sort(r + 1, r + m + 1);
    for(int i = 1, cnt = 0; i <= m; i++){
        int fu = getf(r[i].u), fv = getf(r[i].v);
        if(fu == fv) continue;
        f[fu] = fv, e[++cnt] = {r[i].u, r[i].v, r[i].w}, ans += r[i].w;
        if(cnt == n - 1) break; 
    }
    // for(int i = 1; i < n; i++){
    //     cerr << e[i].u << ' ' << e[i].v << ' ' << e[i].w << endl;
    // }
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    int state = 1 << k;
    for(int i = 1; i < state; i++){
        int now = 0, bit = popcount(i);
        res = 0;
        for(int j = 1; j <= n + k; j++) f[j] = j;
        for(int j = 1; j < n; j++) E[++now] = e[j];
        for(int j = 0; j < k; j++){
            if(!((i >> j) & 1)) continue;
            res += c[j + 1];
            for(int p = 1; p <= n; p++) E[++now] = {n + j + 1, p, a[j + 1][p]};
        }
        sort(E + 1, E + now + 1);
        for(int j = 1, cnt = 0; j <= now; j++){
            int fu = getf(E[j].u), fv = getf(E[j].v);
            if(fu == fv) continue;
            f[fu] = fv, res += E[j].w;
            // cerr << E[j].u << ' ' << E[j].v << ' ' << E[j].w << endl;
            if(cnt == n + bit - 1) break; 
        }
        // cerr << i << ' ' << res << endl << endl;;
        ans = min(ans, res);
    }
    cout << ans;
    return 0;
}