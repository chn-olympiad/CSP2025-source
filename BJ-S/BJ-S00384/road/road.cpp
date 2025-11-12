#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k, sum = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        sum += c;
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n + 1; j++){
            cin >> m;
        }
    }
    cout << sum;
    return 0;
}
