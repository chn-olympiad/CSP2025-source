//Polygon?
#include <bits/stdc++.h>
using namespace std;
const long long N = 5e3 + 10, MOD = 998244353;
long long n, a[N], ans;
void dfs(long long i, long long sum, long long m, long long edge){
    if (i > n){
        if (edge < 3) return;
        if (sum > m * 2){
            ans ++;
        }
        return;
    }

    dfs(i + 1, sum + a[i], max(m, a[i]), edge + 1);
    dfs(i + 1, sum, m, edge);
    return;
}
long long func(long long a, long long b, long long mod){
    long long res = 1;
    while (b --){
        res *= a;
        res %= mod;
    }
    return res;
}
int main(){
    //freopen("polygon.in", "r", stdin);
    //freopen("polygon.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    bool flg = true;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (a[i] != 1) flg = false;
    }
    if (flg){
        cout << (func(2, n, MOD) - n - n * (n - 1) / 2 - 1 + MOD) % MOD;
        return 0;
    }
    dfs(1, 0, 0, 0);
    cout << ans;
    return 0;
}
