#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int t, n;

struct club {
	int a[3];
} c[N];

int cmp (club c1, club c2) {
	if (c1.a[0] == c2.a[0]) {
		if (c1.a[1] == c2.a[1]) {
			return c1.a[2] > c2.a[2];
		} else {
			return c1.a[1] > c2.a[1];
		}
	} else {
		return c1.a[0] > c2.a[0];
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> c[i].a[0] >> c[i].a[1] >> c[i].a[2];
		}
		if (n == 2) {
			int ans = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					ans = max(ans, c[i].a[i] + c[i].a[j]);
				}
			}
			cout << ans << "\n";
			continue;
		}
		if (n == 4) {
			int ans = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 3; k++) {
						for (int l = 0; l < 3; l++) {
							ans = max(ans, c[i].a[i] + c[i].a[j] + c[i].a[k] + c[i].a[l]);
						}
					}
				}
			}
			cout << ans << "\n";
			continue;
		}
		sort(c + 1, c + n + 1, cmp);
		int cnt = 0, sum = 0;
		for (int i = 1; i <= n / 2; i++) {
			if (cnt + 1 <= n / 2) {
				sum += c[i].a[0];
				cnt++;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
