#include <bits/stdc++.h>
#define ll long long

void Freopen() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
}

using namespace std;
const int N = 2e5 + 10, M = 2e6 + 10, mod = 998244353;
const ll inf = 1e15;

int n, m, k, cnt;

struct edge {
    int u, v;
    ll w;
} E[M];

int fa[N];
ll c[12], a[12][N];

ll mp[1010][1010];

int getf( int x) {
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

signed main() {
    Freopen();

    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    for ( int i = 1; i <= m; i ++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        E[++ cnt] = {u, v, w};
    }

    int F = 1;

    for ( int i = 1; i <= k; i ++) {
        cin >> c[i];
        F &= (c[i] == 0);

        int flag = 0;
        for ( int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            if (a[i][j] == 0) flag = 1;
            E[++ cnt] = {n + i, j, a[i][j] + c[i]};
        }

        F &= flag;
    }

    if (F) {
        for ( int i = 1; i <= n + k; i ++) fa[i] = i;

        sort(E + 1, E + cnt + 1, [&]( edge a, edge b) {
            return a.w < b.w;
        });

        int cs = 0;
        long long ans = 0;

        for ( int i = 1; i <= cnt; i ++) {
            int u = E[i].u, v = E[i].v;
            ll w = E[i].w;
            int fu = getf(u), fv = getf(v);

            if (fu == fv) continue ;

            fa[fu] = fv;
            cs ++;
            ans += w;

            if (cs == n + k - 1) break ;
        }

        cout << ans << '\n';
        return 0;
    }

        for ( int i = 1; i <= n; i ++)
            for ( int j = 1; j <= n; j ++)
                mp[i][j] = inf;

        for ( int i = 1; i <= m; i ++) {
            int u = E[i].u, v = E[i].v;
            ll w = E[i].w;
            mp[u][v] = mp[v][u] = min(mp[u][v], w * 1ll);
        }

        for ( int i = 1; i <= k; i ++) {
            for ( int j = 1; j <= n; j ++)
                for ( int jj = j + 1; jj <= n; jj ++) {
                    ll w = a[i][j] + a[i][jj] + c[i];
                    mp[j][jj] = mp[jj][j] = min(mp[jj][j], w);
                }
        }

        cnt = 0;
        for ( int i = 1; i <= n; i ++)
            for ( int j = i + 1; j <= n; j ++)
                if (mp[i][j] != inf) {
                    E[++ cnt] = {i, j, mp[i][j]};
                }

        for ( int i = 1; i <= n; i ++) fa[i] = i;

        sort(E + 1, E + cnt + 1, [&]( edge a, edge b) {
            return a.w < b.w;
        });

        int cs = 0;
        long long ans = 0;

        for ( int i = 1; i <= cnt; i ++) {
            int u = E[i].u, v = E[i].v;
            ll w = E[i].w;
            int fu = getf(u), fv = getf(v);

            if (fu == fv) continue ;

            fa[fu] = fv;
            cs ++;
            ans += w;

            if (cs == n - 1) break ;
        }

        cout << ans << '\n';       
        return 0; 


    return 0;
}

/*
一个最小生成树。

不是 $k$ 就 10 啊，那不是把所有边丢进去跑最小生成树即可吗？

令 $b_{j,i}=a_{j,i}+c_j$ 不就行了吗？

题目读错了。

对于一个乡村，肯定至少在里面选择两条边。
*/