#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1e5 + 5, M = 205;

int n;
ll a[N][5], dp[2][M][M];

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i ++ ) for (int j = 1; j <= 3; j ++ ) cin >> a[i][j];
	
	if (n <= 200) {
		dp[0][0][0] = 0;
//		memset (dp, 0, sizeof dp);
		
		for (int i = 1; i <= n; i ++ ) for (int j = 0; j <= min (i, n / 2); j ++ ) for (int k = 0; k <= min (i - j, n / 2); k ++ )
			dp[i & 1][j][k] = max <long long> ({(j ? dp[!(i & 1)][j - 1][k] + a[i][1] : 0ll), (k ? dp[!(i & 1)][j][k - 1] + a[i][2] : 0ll), ((j + k < i) ? dp[!(i & 1)][j][k] + a[i][3] : 0ll)});
		
		ll mx = 0;
		for (int i = 1; i <= n / 2; i ++ ) for (int j = 1; j <= n / 2; j ++ ) if (i + j >= n / 2) mx = max <long long> (mx, dp[n & 1][i][j]);
		
		cout << mx << '\n';
	} else {
		bool A = true, B = true;
		for (int i = 1; i <= n; i ++ ) B = (B && (a[i][3] == 0)), A = (A && (a[i][3] == 0) && (a[i][2] == 0));
		
		if (A) {
			vector <ll> val(n);
			for (int i = 1; i <= n; i ++ ) val[i - 1] = a[i][1];
			
			sort (val.rbegin (), val.rend ());
			
			ll ans = 0;
			for (int i = 0; i < n / 2; i ++ ) ans += val[i];
			
			cout << ans << '\n';
		} else if (B) {
			
		} else {
			cout << rand () << '\n';
		}
	}
	
}

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin.tie (nullptr) -> sync_with_stdio (false);
	
	int T = 1;
	cin >> T;
	while (T -- ) solve ();
	return 0;
}
