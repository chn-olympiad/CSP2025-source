#include <bits/stdc++.h>	//68

typedef long long ll;

using namespace std;

const ll N = 5e3 + 10;

ll a[N];

ll dp[2][N][N];	//dp[op][i][j]: max 为 i, sum 为 j, 的方案数的个数

ll sum = 0;

ll mx = 0;

int main() {

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

	ll n;
	cin >> n;
	
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i];

		sum += a[i];
		mx = max(mx, a[i]);
	}

	dp[0][0][0] = 1;

	for (ll i = 1; i <= n; i ++) {		//O(2 * n * mx * sum)
	
		for (ll j = 0; j <= mx; j ++) {
			
			for (ll k = 0; k <= sum; k ++) {
				//选
				dp[1][max(j, a[i])][k + a[i]] += dp[0][j][k];

				//不选
				dp[1][j][k] += dp[0][j][k];
			}
		}

		for (ll j = 0; j <= mx; j ++) {
			for (ll k = 0; k <= sum; k ++) {
				dp[0][j][k] = dp[1][j][k];
				dp[1][j][k] = 0;
			}
		}
	}

	ll ans = 0;

	for (ll i = 0; i <= mx; i ++) {
		for (ll j = 2 * i + 1; j <= sum; j ++) {
			ans += dp[0][i][j];
		}
	}

//	for (ll i = 0; i <= mx; i ++) {
//		for (ll j = 0; j <= sum; j ++) {
//			if (2 * i < j) {
//				cout << dp[0][i][j] << " ";
//			} else {
//				cout << "  ";
//			}
//		}
//		cout << "\n";
//	}

	cout << ans << "\n";

	return 0;
}

