#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 998244353;

int n, m, s[505], pre[505], c[505], r, ans = 1;

int a[505];

int A(int x, int y) {
	int ans = 1;
	for (int i = y, j = 1; j <= x; i--, j++) {
		ans = 1LL * (1LL * ans * i) % maxn;
	}
	return ans;
}

int main() {
	freopen("replace", "r", stdin);
	freopen("replace", "w", stdout);
	cin >> n >> m;
	if (m == n) {
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
			if (s[i]) pre[i] = pre[i - 1];
			else pre[i] = pre[i - 1] + 1;
			a[pre[i]]++;
		}
		r = n;
		sort(c + 1, c + n + 1);
		for (int i = 1; i <= n; i++) {
			int l = lower_bound(c + 1, c + r + 1, i) - c;
			if (r - l + 1 < a[i]) {
				cout << "0";
				return 0;
			}
			ans = 1LL * (0LL + ans + A(a[i], r - l + 1)) % maxn;
		}
		cout << ans;
	} else {
		cout << 0;
	}
	return 0;
}
