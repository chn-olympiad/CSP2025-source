#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
int n, m, k;
ll ans;
int u[N], v[N];
ll c[N];
ll w[N];
ll aa[N][N];
bool a[N];
ll g[N][N];
void Prim(int step){
    if(step >= n){
        return ;
    }
    ll minn = 1e9 + 7;
    int k = 0;
    for(int i = 1; i <= n; i ++){
        if(a[i]){
            for(int j = 1; j <= n; j ++){
                if(!a[j]){
                    if(g[i][j] < minn){
                        minn = g[i][j];
                        k = j;
                    }
                }
            }
        }
    }
    ans += minn;
    a[k] = true;
    Prim(step + 1);
    return ;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    if(k == 0){
        a[1] = true;
        for(int i = 2; i <= n; i ++){
            a[i] = false;
        }
        for(int i = 1; i <= m; i ++){
            cin >> u[i] >> v[i] >> w[i];
            g[u[i]][v[i]] = w[i];
            g[v[i]][u[i]] = w[i];
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(g[i][j] == 0){
                    g[i][j] = 1e9 + 7;
                }
            }
        }
        ans = 0;
        Prim(1);
        for(int i = 1; i <= k; i ++){
            cin >> c[i];
            for(int j = 1; j <= n; j ++){
                cin >> aa[i][j];
            }
        }
        cout << ans;
    }
    else{
        for(int i = 1; i <= m; i ++){
            cin >> u[i] >> v[i] >> w[i];
            g[u[i]][v[i]] = w[i];
            g[v[i]][u[i]] = w[i];
        }
        for(int i = 1; i <= k; i ++){
            cin >> c[i];
            for(int j = 1; j <= n; j ++){
                cin >> aa[i][j];
            }
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                for(int q = 1; q <= k; q ++){
                    if(g[i][j] == 0){
                        g[i][j] = 1e9 + 7;
                    }
                    ll t = aa[q][i] + aa[q][j] + c[q];
                    if(t < g[i][j]){
                        g[i][j] = t;
                    }
                }
            }
        }
        a[1] = true;
        for(int i = 2; i <= n; i ++){
            a[i] = false;
        }
        ans = 0;
        Prim(1);
        cout << ans;
    }
    return 0;
}
