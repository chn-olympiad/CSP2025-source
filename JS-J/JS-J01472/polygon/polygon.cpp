#include<bits/stdc++.h>
using namespace std;

int k = 998244353 , a[5005] , f[5005][5005] , ans = 0;

int main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    f[0][0] = 1;
    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);

    for(int i = 1 ; i <= n ; i ++){
        for(int j = 0 ; j <= 5000 ; j ++){
            f[i][j] = f[i - 1][j];
            f[i][j] += f[i - 1][max(0 , j - a[i])];
            f[i][j] %= k;
        }
    }

    for(int i = 3 ; i <= n ; i ++){
        ans += f[i - 1][a[i] + 1];
        ans %= k;
    }
    cout << ans;
    return 0;
}
