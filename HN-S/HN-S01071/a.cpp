#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a, b;
int dis[maxn][maxn];
mt19937 rnd(time(0));
signed main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n = 1000;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = rnd() % 1000;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    cout << dis[1][n] << '\n';
    cerr << clock() * 1. / CLOCKS_PER_SEC << '\n';
    return 0;
}