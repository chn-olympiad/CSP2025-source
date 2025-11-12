#include <bits/stdc++.h>
using namespace std;
const long long md = 998244353;
long long n, a[5005], sum, ans, num = 1, dp[5005];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1), dp[0] = 1;
	for(int i = 1; i <= n; i++){
		sum = 0;
		for(int j = 0; j <= a[i]; j++) sum += dp[j], sum %= md;
		ans += num - sum, ans = (ans % md + md) % md, num <<= 1, num %= md;
		for(int j = a[n]; j >= a[i]; j--)
		    dp[j] += dp[j - a[i]], dp[j] %= md;
	}
	cout << ans << "\n"; 
	return 0;
} 
