#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
int n, k, dp[maxn], tmp[maxn], a[maxn];

signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    memset(tmp, -63, sizeof(tmp));
    tmp[0] = 0;
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = tmp[a[i] ^ k] + 1;
        dp[i] = max(dp[i], dp[i - 1]);
        tmp[a[i]] = max(tmp[a[i]], dp[i]);
    }
    cout << dp[n];

    return 0;
}