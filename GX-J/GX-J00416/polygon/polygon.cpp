#include<bits/stdc++.h>
using namespace std;
long long n, a[5005], p = 998244353, ma, s;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ma = max(a[i], ma);
        s += a[i];
    }
    if (n == 3){
        if (s > ma * 2){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    else if (ma = 1){
        long long ans = 0, sn = n, sj = 1;
        for (int i = 3; i <= n; i++){
            sn = n, sj = 1;
            for (int j = 1; j < i; j++){
                sj = (sj * j) % p;
                sn = sn * (n - j) % p;
            }
            ans += (sn / sj) % p;
        }
        cout << ans;
    }
    cout << 0;
    return 0;
}
