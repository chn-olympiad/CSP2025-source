#include<bits/stdc++.h>
using namespace std;
long long n, k, t, dp[500005], flag = 1;
struct e {
	long long a, b;
}f[500005];
int main () {
//	freopen ("xor6.in", "r", stdin);
//	freopen ("xor6.out", "w", stdout);
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> f[i].a;
		if (f[i].a != 1) flag = 0;
		t = 0;
		for (int j = 0; j < i; j++) {
			t = t^f[i - j].a;
			if (t == k) {
				f[i].b = j + 1;
				break;
			}
		}
	}
	if (k == 0 && flag) {
		cout << n / 2;
		return 0;
	} 
	for (int i = 1; i <= n; i++) if (f[i].b) {dp[i] = 1; break;}
	for (int i = 1; i <= n; i++) {
		if (f[i].b) dp[i] = max (dp[i], max(dp[i - 1], dp[i - f[i].b] + 1));
		else dp[i] = max (dp[i], dp[i - 1]);
	}
//	for (int i = 1; i <= n; i++) cout << f[i].a << " " << f[i].b << " " << dp[i] << endl;
	cout << dp[n];
	return 0;
}

