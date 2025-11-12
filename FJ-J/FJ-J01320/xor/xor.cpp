#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, k, a[N], dp[N], sum[N], ans;

signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		a[i] = (a[i] ^ a[i - 1]);
	}
	for(int i = 0 ; i < N ; i ++){
		sum[i] = -1;
	}
	sum[k] = 0;
	for(int i = 1 ; i <= n ; i ++){
		dp[i] = max(dp[i - 1], sum[a[i]] + 1);
		ans = max(ans, dp[i]);
		sum[a[i] ^ k] = max(sum[a[i] ^ k], dp[i]);
	}
	cout << ans << '\n';
	return 0;
}
// 一等到手喽 \o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/ 
// Luogu uid: 749755
