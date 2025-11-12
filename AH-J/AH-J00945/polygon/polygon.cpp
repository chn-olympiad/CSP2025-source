#include <bits/stdc++.h>
using namespace std; 
const int N = 5005, MOD = 998244353; 
int n, a[N], dp[500005]; 
long long ans; 
int main() {
    ios :: sync_with_stdio(false); 
    cin.tie(nullptr), cout.tie(nullptr); 
    freopen("polygon.in", "r", stdin); 
    freopen("polygon.out", "w", stdout); 
    cin >> n; 
    for (int i = 1; i <= n; i++)
		cin >> a[i]; 
	sort(a + 1, a + n + 1); 
	for (int i = 0; i < a[1]; i++)
		dp[i]++; 
	for (int i = 0; i < a[2]; i++)
		dp[i]++; 
	for (int i = 0; i < a[1] + a[2]; i++)
		dp[i]++; 
	for (int i = 3; i <= n; i++) {
		ans = (ans + dp[a[i]]) % MOD; 
		for (int j = 500000; j >= 0; j--) {
			if (j < a[i])
				dp[j] = (dp[j] + dp[0] + 1) % MOD; 
			else
				dp[j] = (dp[j] + dp[j - a[i]]) % MOD; 
		}
	}
	cout << ans << endl; 
    return 0; 
}
