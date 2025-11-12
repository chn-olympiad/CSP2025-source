#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int MAXN = 1e3 + 11;
int G[MAXN][MAXN];
bool E[MAXN][MAXN];
int dis[10 + 11][MAXN], c[10 + 11];
int main(){
    freopen("road1.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1, u, v, w; i <= m; ++i){
        cin >> u >> v >> w;
        if(E[u][v]){
            G[u][v] = min(w, G[u][v]);
            G[v][u] = min(w, G[v][u]);
        }else{
            G[u][v] = w;
            G[v][u] = w;
        }
        E[u][v] = 1;
        E[v][u] = 1;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            for(int k = 1; k <= n; ++k){
                G[j][k] = min(G[j][k], G[j][i] + G[i][k]);
            }
        }
    }
    for(int i = 1; i <= k; ++i){
        cin >> c[i];
        for(int j = 1; j <= n; ++j){
            cin >> dis[i][j];
        }
    }
    i64 res = LONG_MAX;
    for(int msk = 0; msk < (1 << k); ++msk){
        i64 ans = 0;
        for(int i = 1; i < n; ++i){
            for(int j = i + 1; j <= n; ++j){
                i64 minn = INT_MAX;
                if(E[i][j]){
                    minn = G[i][j];
                }
                i64 sum = 0;
                for(int x = 0; x < k; ++x){
                    if((msk >> x) & 1){
                        sum += c[x + 1];
                    }
                }
                i64 minn2 = INT_MAX;
                for(int x = 0; x < k; ++x){
                    if((msk >> x) & 1){
                        minn2 = min(minn2, 1LL * dis[x + 1][i] + 1LL * dis[x + 1][j]);
                    }
                }
                cout << minn << " " << minn2 << " " << sum << '\n';
                sum += minn2;
                minn = min(minn, sum);
                ans += minn;
            }
        }
        res = min(res, ans);
    }
    cout << res << '\n';
    return 0;
}
