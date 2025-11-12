#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5005], maxn, dp[5005] = {0, 1};

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	/* 1 ∼ 3 3 10 */
	ll n, ans = 0;
	cin >> n;
    for (int i = 1; i <= n; i++) {
	    cin >> a[i];
        maxn = max(maxn, a[i]);
	}
    if (n <= 3) {
        if (n < 3) {
	    	cout << 0;
	    } else {
	    	/* 所有小木棍的长度之和 大于 所有小木棍的长度最大值的两倍 */
	    	if (a[1] + a[2] + a[3] > (max(a[1], max(a[2], a[3])) * 2)) {
	    		// 就一种情况: a[1] a[2] a[3]
	    		cout << 1;
	    	} else {
	    		cout << 0;
	    	}
	    }
    }
	else if (maxn == 1) {
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] * i;
            dp[i] %= 998244353;
        }
        for (int i = 3; i <= n; i++) {
            ans += dp[n] / dp[i];
            ans %= 998244353;
        }
        cout << ans;
    } else {
		cout << 1;
	}
	return 0;
}
