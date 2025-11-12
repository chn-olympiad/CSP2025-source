#include <bits/stdc++.h>
using namespace std;
int n, k, tmp, cnt, ans, a[500005], p[500005];
int max(const int x, const int y) {return x > y ? x : y;}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[i] = p[i - 1] ^ a[i];
	}
	if (!k) {
		int sum = 0;
		for (int i = 1; i <= n; ++i)
			if (!a[i]) ++sum;
		cout << sum;
		return 0;
	}
	if (k == 1) {
		int sum = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i] == 1) ++sum;
		cout << sum;
		return 0;
	}
	for (int l = 1; l <= n; ++l) {
		cnt = 0;
		for (int r = n; r > l; --r) {
			tmp = p[l];
			for (int i = l + 1; i <= r; ++i) tmp ^= p[i];
			if (tmp == k) ++cnt;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
