#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct NODE {
    int u, v, w;
    bool is_bld;
}r[1000005];
int r_top = 1;

int c[25][20005];
int vis[20005];
vector <int> a[20005];
ll dp[20005];

void dfs(int p) {
    vis[p] = 1;
    for (int i : a[p]) {
        int v = p ^ r[i].u ^ r[i].v;
        if (vis[v] == 0) dp[p] = min(dp[p], dp[v] + r[i].w);
    }
    for (int i : a[p]) {
        int v = p ^ r[i].u ^ r[i].v;
        if (vis[v] == 0) dfs(v);
    }
    for (int i : a[p]) {
        int v = p ^ r[i].u ^ r[i].v;
        if (vis[v] == 2) dp[p] += dp[v];
    }
    vis[p] = 2;
    //cout << p << ' ' << dp[p] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    for (int i = 1; i <= 10000; i++) {
        dp[i] = 10000000;
    }
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int aaaa, aaab, aaac;
        cin >> aaaa >> aaab >> aaac;
        r[r_top] = {aaaa, aaab, aaac, 0};
        a[aaaa].push_back(r_top); a[aaab].push_back(r_top++);
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    dp[1] = 0;
    dfs(1);
    cout << dp[1] << endl;
    return 0;
}
