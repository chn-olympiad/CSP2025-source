#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    mutable int u, v, w;
} e[2000001];

int n, m, k, c[11], a[11][10001], f[20001];
long long ans = 9e18;
bool vis[11];

int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

bool cmp(node x, node y) {
    if (x.u == 0) return 0;
    if (y.u == 0) return 1;
    return x.w < y.w;
}

void dfs(int x, int delta, int sumc) {
    if (x > k) {
        /*
        cout << "#";
        for (int i = 1; i <= k; i++) {
            cout << vis[i] << " ";
        }
        cout << endl;
        */
        int M = m;
        for (int i = 1; i <= k; i++) {
            if (!vis[i]) {
                continue;
            }
            for (int j = 1; j <= n; j++) {
                M++;
                e[M].u = j;
                e[M].v = n + i;
                e[M].w = a[i][j];
            }
        }
        /*
        for (int i = 1; i <= M; i++) {
            cout << e[i].u << " " << e[i].v << endl;
        }
        */
        sort(e + 1, e + M + 1, cmp);
        long long cnt = sumc;
        int edge = 0;
        for (int i = 1; i <= n + delta; i++) {
            f[i] = i;
        }
        for (int i = 1; i <= M; i++) {
            if (find(e[i].u) != find(e[i].v)) {
                f[find(e[i].u)] = find(e[i].v);
                edge++;
                cnt += e[i].w;
                //cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
                if (edge >= n + delta - 1) {
                    break;
                }
            }
        }
        //cout << cnt << endl;
        ans = min(ans, cnt);
        for (int i = 1; i <= M; i++) {
            if (e[i].u <= n && e[i].v <= n) {
                continue;
            }
            //cout << e[i].u << " " << e[i].v << endl;
            e[i].u = e[i].v = e[i].w = 0;
        }
        sort(e + 1, e + M + 1, cmp);
        return ;
    }
    dfs(x + 1, delta, sumc);
    vis[x] = 1;
    dfs(x + 1, delta + 1, sumc + c[x]);
    vis[x] = 0;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
