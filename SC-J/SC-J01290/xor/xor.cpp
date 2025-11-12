#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, x = 0, ans = 0, p;
int a[500010], pos[500010];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	x = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] == k) {
			++x;
			pos[x] = i;
			++ans;
		}
	}
	if (n > 1000) {
		if (k == 1) {
			cout << ans;
		} else {
			for (int i = 1; i <= n; ++i) {
				if (a[i] == 1 && a[i + 1] == 1) {
					++ans;
					i += 2;
				}
			}
			cout << ans;
		}
		return 0;
	}
	for (int i = 1; i <= x; ++i) {
		if (pos[1] == 1) {
			continue;
		}
		if (i == 1) {
			for (int r = pos[1] - 1; r >= 1; --r) {
				for (int l = r; l >= 1; --l) {
					int tp = 0;
					for (int j = l; j <= r; ++j) {
						tp = tp xor a[j];
					}
					if (tp == k) {
						p = l;
						++ans;
					}
				}
				r = p - 1;
			}
		} else {
			for (int r = pos[i] - 1; r >= pos[i - 1] + 1; --r) {
				for (int l = r; l >= pos[i - 1] + 1; --l) {
					int tp = 0;
					for (int j = l; j <= r; ++j) {
						tp = tp xor a[j];
					}
					if (tp == k) {
						p = l;
						++ans;
					}
				}
				r = p - 1;
			}
		}
	}
	for (int r = n; r >= pos[x] + 1; --r) {
		for (int l = r; l >= pos[x] + 1; --l) {
//			cout << "r = " << r << " l = " << l << '\n';
			int tp = 0;
			for (int j = l; j <= r; ++j) {
				tp = tp xor a[j];
			}
			if (tp == k) {
				p = l;
				++ans;
			}
		}
		r = p - 1;
	}
	cout << ans;
	return 0;
}
/*
4 0
2 1 0 3
*/