#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e4 + 5, M = 6e6;

int n, m, k_;
int u[M], v[M], g[M], f[N], l, p;
long long w[M], c[13], wl[13][N], ans;
int merge_(int i){
    if(i == f[i])
        return i;
    return f[i] = merge_(f[i]);
}
bool cmp(int a, int b){
    return w[a] < w[b];
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k_;
    for (int i = 1; i <= m; i++){
        cin >> u[i] >> v[i] >> w[i];
        g[i] = i;
    }
    for (int k = 1; k <= k_; k++){
        cin >> c[k];
        for (int i = 1; i <= n; i++){
            cin >> wl[k][i];
            if(c[k] == 0 && wl[k][i] ==0)
                p++;
        }
    }
    if (p == k_){
        for (int k = 1; k <= k_; k++)
            for (int i = 1; i <= n; i++)
                if(wl[k][i] == 0){
                    for (int j = 1; j <= n; j++)
                        if(j != i){
                            u[++m] = i;
                            v[m] = j, w[m] = c[k] + wl[k][i] + wl[k][j], g[m] = m;
                        }
                    break;
                }
    }else {
        for (int k = 1; k <= k_ ; k++){
            for (int i = 1; i <= n; i++){
                for (int j = i - 1; j; j--){
                    u[++m] = i;
                    v[m] = j, w[m] = c[k] + wl[k][i] + wl[k][j], g[m] = m;
                }
            }
        }
    }
    sort(g + 1, g + m + 1,cmp);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    n--;
    for (int i = 1; i <= m; i++){
        if(merge_(u[g[i]]) != merge_(v[g[i]])){
            ans += w[g[i]];
            f[merge_(u[g[i]])] = merge_(v[g[i]]);
            n--;
            if (!n)
                break;
        }
    }
    cout << ans;
    return 0;
}
