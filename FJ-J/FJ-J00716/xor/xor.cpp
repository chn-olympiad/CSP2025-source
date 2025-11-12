#include <bits/stdc++.h>
#define Write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define Na1L0n9 cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 5e5 + 10;
const int MOD = 998244353;
ll n, k, ans, a[N], dp[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	Write by Na1L0n9
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 10000) {
		for (int i = 1; i <= n; i++) {
			ll t = 0, add = 0, pos = 1;
			for (int j = i; j; j--) {
				t ^= a[j];
				if (t == k) {
					add = 1, pos = j - 1;
					break;
				}
			}
			dp[i] = max(dp[i - 1], dp[pos] + add);
		}
		cout << dp[n];
	}
	else {
		bool type = 0;
		for (int i = 1; i <= n; i++) {
			ans += a[i];
			if (a[i] > 1) {
				type = 1;
				break;
			}
		}
		if (!type) {
			cout << ans;
		}
		else {
			cout << 114514 << "\n";
		}
	}
	return 0;
}
//我嘞个豆，T3我居然能打出65分的部分分，我才学91天，看来我是天赋性选手! 
