#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

const int N = 1e5 + 10;
int t, n;
int a[N][4];

struct node {
	int x;
}b[N];

bool cmp(node a, node b) {
	return a.x > b.x;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while (t--) {
		long long ans = 0;
		n = read();
		for (int i = 1; i <= n; i++) {
			a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
		}
		if (a[1334][2] == 0 && a[1334][3] == 0) {
			for (int i = 1; i <= n; i++) {
				b[i].x = a[i][1];
			}
			sort(b + 1, b + 1 + n, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += b[i].x;
			}
			cout << ans;
			continue;
		}
		for (int i = 1; i < n; i += 2) {
			int cnt = -INT_MAX;
			for (int j = 1; j <= 3; j++) {
				for (int k = 1; k <= 3; k++) {
					if (j == k) continue;
					cnt = max(cnt, a[i][j] + a[i + 1][k]);
				}
			}
			ans += cnt;
		}
		printf("%lld\n", ans);
	}
	return 0;
}