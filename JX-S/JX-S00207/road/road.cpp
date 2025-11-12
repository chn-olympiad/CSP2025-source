#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    int b[n][m];
    int a[n][m];
    for(int i = 1;i <= n;i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    for(int i = 1;i <= k;i++){
        for(int j = 1;j <= n+1;j++){
            cin >> b[i][j];
        }
    }
    int w;
    cout << w;

    return 0;
}
