#include<algorithm>
#include<iostream>
using namespace std;
#define int long long
const int MOD = 998244353;
const int N = 550;
int a[550];

signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        if (a[i] != 0) cnt++;
    }
    cout << cnt <<endl;
    int ans = 1;
    for (int i = 1; i <= cnt; i++){
        ans = (ans % MOD) * (i % MOD);
        ans %= MOD;
    }
    cout << ans%MOD <<endl;

    return 0;
}
