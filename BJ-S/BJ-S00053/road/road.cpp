#include <bits/stdc++.h>
using namespace std;


int n, m, k;
int ma[1017][1017], c[17];
bool dis[1017][1017];
bool disn[1017];
unsigned long long sum = 1 << 32 -1;

void dfs(int u, int v, unsigned long long num) {

    dis[u][v] = true;
    dfs(u, 2);
    dis[u][v] = false;
}



int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m >> k;
    int u, v, w, a;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        ma[u][v] = ma[v][u] = w;
    }

    for (int j = 1; j <= k; j++) {
        cin >> c[j];
        for (int i = 1; i <= n; i++) {
            cin >> a;
            ma[n+j][i] = ma[i][n+j] = a;
        }
    }

    dfs(1, 1, 0);

    cout << sum << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
