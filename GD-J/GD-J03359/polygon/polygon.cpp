#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e3 + 75 1 2 3 4 5;
int a[N], sum[N * N];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, m = 0, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	sum[0] = 1;
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = m; j >= 0; --j) {
			if (j > a[i]) cnt = (cnt + sum[j]) % mod;
			sum[j + a[i]] += sum[j];
		}
		m += a[i];
		if (i >= 3) ans = (ans + cnt) % mod;
	}
	cout << ans;
	return 0;
}

