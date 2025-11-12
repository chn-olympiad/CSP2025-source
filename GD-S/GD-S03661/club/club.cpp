#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int T, n, a[N][10], b[10][N], t[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++)
			cin >> a[j][1] >> a[j][2] >> a[j][3];
		int ans = 0;
		int cnta = 0, cntb = 0, cntc = 0;
		for (int j = 1; j <= n; j++) {
			int v = max(max(a[j][1], a[j][2]), a[j][3]);
			if (v == a[j][1]) 
				b[1][++cnta] = j;
			else if (v == a[j][2])
				b[2][++cntb] = j;
			else
				b[3][++cntc] = j;
			ans += v;
		}
		int w = max(max(cnta, cntb), cntc);
		if (w <= n / 2) {
			cout << ans << "\n";
			continue;
		}
		if (w == cnta) {
			for (int j = 1; j <= cnta; j++)
				t[j] = a[b[1][j]][1] - max(a[b[1][j]][2], a[b[1][j]][3]);
			sort(t + 1, t + cnta + 1);
			for (int j = 1; j <= cnta - (n / 2); j++)
				ans -= t[j];
		} else if (w == cntb) {
			for (int j = 1; j <= cntb; j++)
				t[j] = a[b[2][j]][2] - max(a[b[2][j]][1], a[b[2][j]][3]);
			sort(t + 1, t + cntb + 1);
			for (int j = 1; j <= cntb - (n / 2); j++)
				ans -= t[j];
		} else {
			for (int j = 1; j <= cntc; j++)
				t[j] = a[b[3][j]][3] - max(a[b[3][j]][1], a[b[3][j]][2]);
			sort(t + 1, t + cntc + 1);
			for (int j = 1; j <= cntc - (n / 2); j++)
				ans -= t[j];
		}
		cout << ans << "\n";
	}
	return 0; 
} 
