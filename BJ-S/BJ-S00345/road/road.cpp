#include <bits/stdc++.h>
using namespace std;
int c[15];
int tu[10010][10010];
int xz[15][10010];
int main (){
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        tu[u][v] = w;
    }
    for (int i = 1; i <= k; i++){
        cin >> c[i];
        for (int j = 1; i <= n; j++){
            cin >> xz[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int s = 1; s <= k; s++){
                if (tu[i][j] > c[s] + xz[s][i] + xz[s][j]){
                    tu[i][j] = c[s] + xz[s][i] + xz[s][j];
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            ans += tu[i][j];
        }
    }
    cout << ans;
    return 0;
}

