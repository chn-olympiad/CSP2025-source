#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k; scanf("%lld %lld", &n, &k);
    vector<int> v(n + 1), xsum(n + 1), lst(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &v[i]);
        xsum[i] = xsum[i - 1] ^ v[i];
        //cout << xsum[i] << ' ';
    }
    //cout << endl;
    unordered_map<int, int> ump;
    ump[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (ump.count(k ^ xsum[i])) lst[i] = ump[k ^ xsum[i]];
        else lst[i] = -1;
        ump[xsum[i]] = i;
        //cout << lst[i] << ' ';
    }
    //cout << endl;
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (lst[i] != -1) dp[i] = max(dp[i], dp[lst[i]] + 1);
        //cout << dp[i] << ' ';
    }
    //cout << endl;
    printf("%lld", dp[n]);
    //cout << dp[n];
    return 0;
}
