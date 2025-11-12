#include <bits/stdc++.h>
using namespace std;
const int N = 1E4;
long long g[N + 5][N + 5];
int c[15];
int a[15][N + 5];
int n, m, k;
bool book[N + 5];
long long minn = 1E18;
int cnt = 0;
bool check() {
    for(int i = 1; i <= n; i++) {
        if(book[i] == true) {
            return false;
        }
    }
    return true;
}
void dfs(int cur) {
    if(check()) {
        if(cnt < minn) {
            minn = cnt;
        }
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(i != cur && book[i] == true) {
            cnt += g[cur][i];
            book[i] = false;
            dfs(i);
            cnt -= g[cur][i];
            book[i] = true;
        }
    }
    return;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            g[i][j] = 1E9;
        }
    }
    int u, v, w;
    long long s = 0;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
        s += w;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int l = 1; l <= n; l++) {
                if(l == i || l == j) continue;
                if(g[i][l] + g[l][j] < g[i][j]) {
                    g[i][j] = g[j][i] = g[i][l] + g[l][j];
                }
            }
        }
    }
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int l = 1; l <= k; l++) {
        if(c[l] > s) continue;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(i == j) continue;
                if(c[l] + a[l][i] + a[l][j] < g[i][j]) {
                    g[i][j] = g[j][i] = c[l] + a[l][i] + a[l][j];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        book[i] = true;
    }
    book[1] = false;
    dfs(1);
    cout << minn;
    return 0;
}
