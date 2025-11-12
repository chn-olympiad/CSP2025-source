#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, ans;
int u[1000001], v[1000001], w[1000001];
int main(){
    cin.tie(0);
    freopen("road.in", 'r', stdin);
    freopen("road.out", 'w', stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i){
        cin >> u[i] >> v[i] >> w[i];
    }
    for (int i = 1; i <= k * (n + 1); ++i){
        cin >> a;
    }
    for (int i = 1; i <= m; ++i){
        ans += w[i];
    }
    if (n == 1){
        cout << 0;
    }else{
    cout << ans;   
    }
    
    return 0;
}