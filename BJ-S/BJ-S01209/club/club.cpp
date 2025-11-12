#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5 + 5;
ll t, a[MAXN][4], dp[MAXN][3];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		for(ll i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dp[1][1] = a[1][1];
		dp[1][2] = a[1][2];
		dp[1][3] = a[1][3];
		for(ll i = 2; i <= n; i++) {
			for(ll j = 1; j <= 3; j++) {
				if(j == 1) {
					dp[i][j] = max(max(dp[i - 1][j + 1], dp[i - 1][j + 2]), max(a[i][2], a[i][3])) + a[i][j];
				} else if(j == 2) {
					dp[i][j] = max(max(dp[i - 1][j - 1], dp[i - 1][j + 1]), max(a[i][1], a[i][3])) + a[i][j];
				} else {
					dp[i][j] = max(max(dp[i - 1][j - 2], dp[i - 1][j - 1]), max(a[i][1], a[i][2])) + a[i][j];
				}
			}
		}
		ll ans = INT_MIN;
		for(ll i = 1; i <= n; i++) {
			for(ll j = 1; j <= 3; j++) {
                ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
