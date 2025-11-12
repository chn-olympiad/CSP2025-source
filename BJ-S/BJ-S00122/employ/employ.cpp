#include<bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, c[N], can[N], a[N], ans;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        char x;
        cin >> x;
        can[i] = (x == '1');
    }
    for(int i = 1;i <= n;i++)cin >> c[i];
    for(int i = 1;i <= n;i++)a[i] = i;
    do{
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(can[i] && c[a[i]] > i - cnt - 1)cnt++;
        }
        if(cnt >= m)ans++;
    }while(next_permutation(a + 1, a + n + 1));
    cout << ans;
    // cout << dp[n][m] * fac(n - m) % mod;
    return 0;
}