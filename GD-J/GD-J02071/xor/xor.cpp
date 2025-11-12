#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 9;
ll n, a[N], k, dp[N];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		if (a[i] == k) dp[i] = dp[i - 1] + 1;
		else {
			dp[i] = dp[i - 1];
			int t = a[i];
			for (int j = i - 1; j >= 1; j--){
				if (dp[j] != dp[j - 1]) break;
				t ^= a[j];
				if (t == k){
					dp[i]++;
					break;
				}
			}
		}
	}
	cout << dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
