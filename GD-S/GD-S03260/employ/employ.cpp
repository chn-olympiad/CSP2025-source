#include <bits/stdc++.h>
using namespace std;
long long c[1000001];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n, m;
	long long sum = 0, cnt = 0;
	cin >> n >> m;
	string s;
	cin >> s;
	for (long long i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 0) {
			cnt++;
		}
	}
//	cout << cnt << endl;
	for (long long i = m; i <= n - cnt; i++) {
		long long ans = 1;
		for (long long j = 0; j < i; j++) {
			int val = ans;
			for (int k = 1; k < n - cnt - j; k++) {
				ans = (ans + val) % 998244353;
			}
//		cout << ans << endl;
		}
		sum = (sum + ans) % 998244353;
	}
	int val = sum;
	if (cnt) {
		for (int i = 1; i <= cnt; i++) {
			sum = (sum + val) % 998244353;
		}
	}
	cout << sum % 998244353;
	return 0;
}
