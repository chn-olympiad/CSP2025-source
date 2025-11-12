#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int ans = 1;
    for(int i = 1;i <= n;i++){
        ans = ((ans % MOD) * (i % MOD)) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
