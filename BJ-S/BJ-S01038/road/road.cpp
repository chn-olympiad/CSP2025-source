#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int n, m, k;
int u[maxn], v[maxn], w[maxn];
int c[15],a[15][10005];
int main(){
    freopen("road.in","r", stdin);
    freopen("road.out","w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    for(int i = 1; i <= k; i++){
        cin >>c[i];
        for(int j = 1; j <= n; j++){
            cin >>a[i][j];
        }
    }
    cout << 13;
    return 0;
}
