#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, k, ans = 1e18, cnt;
struct node {
    int u, v, w;
} a1[N], a2[N];
int tmp[15][N], c[15], f[N];
bool cmp(node x, node y) {
    return x.w < y.w;
}
int find(int u) {
    return (f[u] == u ? u : f[u] = find(f[u]));
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int tot = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) cin >> a1[i].u >> a1[i].v >> a1[i].w;
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        tot += c[i];
        for(int j = 1; j <= n; j++) cin >> tmp[i][j];
    }
    if(tot == 0) {
        for(int j = 0; j < k; j++) {
            for(int l = 1; l <= n; l++) a2[++cnt] = {l, n + j + 1, tmp[j + 1][l]};
        }
        for(int i = 1; i <= m; i++) a2[++cnt] = a1[i];
        ans = 0;
        for(int i = 1; i <= n + k; i++) f[i] = i;
        sort(a2 + 1, a2 + cnt + 1, cmp);
        for(int j = 1; j <= cnt; j++) {
            int u = find(a2[j].u), v = find(a2[j].v);
            if(u == v) continue;
            ans += a2[j].w;
            f[u] = v;
        }
        cout << ans;
        return 0;
    }
    sort(a1 + 1, a1 + m + 1, cmp);
    for(int i = 0; i < (1 << k); i++) {
        cnt = 0;
        int tp = 0;
        for(int j = 1; j <= n + k; j++) f[j] = j;
        for(int j = 0; j < k; j++) {
            if((i >> j) & 1) {
                for(int l = 1; l <= n; l++) a2[++cnt] = {l, n + j + 1, tmp[j + 1][l]};
                tp += c[j + 1];
            }
        }
        sort(a2 + 1, a2 + cnt + 1, cmp);
        a2[cnt + 1].w = a1[m + 1].w = 1e18;
        int ti = 1, tj = 1;
        for(int j = 1; j <= m + cnt; j++) {
            if(ti <= m && a1[ti].w < a2[tj].w) {
                int u = find(a1[ti].u), v = find(a1[ti].v);
                if(u == v) {
                    ti++;
                    continue;
                }
                tp += a1[ti].w;
                f[u] = v;
                ti++;
            } else if(tj <= cnt && a1[ti].w >= a2[tj].w) {
                int u = find(a2[tj].u), v = find(a2[tj].v);
                if(u == v) {
                    tj++;
                    continue;
                }
                tp += a2[tj].w;
                f[u] = v;
                tj++;
            }
        }
        //cout << i << " " << tp <<"\n";
        ans = min(ans, tp);
    }
    cout << ans;
    return 0;
}

