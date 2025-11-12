#include <bits/stdc++.h>
using namespace std;
long long a[5003], ans = 0;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    /*pian fen 30 score*/
    int n;
    cin >> n;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(long long i = 1; i < (1 << n); i++){
        long long sum = 0, mx = -1;
        for(int j = 1; j <= n; j++){
            if((i >> (j-1)) & 1){
                sum += a[j];
                mx = max(mx, a[j]);
            }
        }
        if(sum > 2*mx){
            ans++;
            ans %= 998244353;
        }
    }
    cout << ans << endl;
}
