#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
long long n, m, a[N], cnt[N];
string s;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	int t = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			swap(a[i], a[n]);
			n--;
		}
	}
	int num = 0;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] > i) {
			cnt[++num] = min (n, a[i] - i + 1);
		}
	}
	long long ans = 1;
	for (int i = 1; i <= num; i++) {
		cnt[i] -= (i - 1);
		ans *= cnt[i];
		ans %= mod;
	}
	cout << ans << '\n';
	return 0;
}