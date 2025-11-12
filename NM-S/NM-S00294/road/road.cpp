#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 10;
int n, m, k;
bool a[N + 10][N + 10];
bool vis[N + 10];

void dfs(int v) {
    vis[v] = true;
    for (int i = 1;i <= n; i++) {
        if (a[v][i] && !vis[i]) {
            dfs(i);
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("road.in", "r", stdin);
    freoepn("road.out", "w", stdout);
    memset(vis, false, sizeof(vis));

    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        a[x][y] = true;
        a[y][x] = true;
    }
    dfs(1);
    return 0;
}
