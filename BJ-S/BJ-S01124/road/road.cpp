#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
long long a[N][N];
long long b[N];
long long dp[N][N];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            a[i][j] = 1e18;
        }
    }
    for(int  i = 1;i <= m;i++){
        long long u, v, w;
        cin >> u >> v >> w;
        if(u > v)swap(u , v);
        a[u][v] = w;
    }
    while(k--){
        long long x;
        cin >> x;
        for(int i = 1;i <= n;i++){
            cin >> b[i];
        }
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                a[i][j] = min(a[i][j], b[i] + b[j] + x);
                //cout << a[i][j] << " ";
            }
            //cout << "\n";
        }
    }
    long long ans = 0;
    for(int i = 1;i < n;i++){
        long long minn = 1e18;
        for(int j = i + 1;j <= n;j++){
            minn = min(minn, a[i][j]);
        }
        ans += minn;
    }
    //for(int j = n;j <= n;j++){
        //ans = min(ans, dp[n][j]);
    //}
    cout << ans << "\n";
    return 0;
}
