#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = (int)1e5 + 5;

int T, n, tot, cnt[3];
ll ans, a[N][3], c[N], h[N];

void work(int cid) {
	cin >> n;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		int p = 0;
		for (int j = 1; j <= 2; j++) {
			if (a[i][j] > a[i][p]) {
				p = j;
			}
		}
		ans += a[i][p];
		c[i] = p;
	}
	cnt[0] = cnt[1] = cnt[2] = 0;
	for (int i = 1; i <= n; i++) {
		cnt[c[i]]++;
	}
	int p = -1;
	for (int j = 0; j <= 2; j++) {
		if (cnt[j] > n / 2) {
			p = j;
			break;
		}
	}
	if (p == -1) {
		cout << ans << '\n';
		return;
	}
	tot = 0;
	for (int i = 1; i <= n; i++) {
		if (c[i] == p) {
			ll v = 0;
			for (int j = 0; j <= 2; j++) {
				if (j == p) {
					continue;
				}
				v = max(v, a[i][j]);
			}
			h[++tot] = a[i][p] - v; 
		}
	}
	sort(h + 1, h + tot + 1);
	for (int i = 1; i <= tot - n / 2; i++) {
		ans -= h[i];
	}
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	for (int cid = 1; cid <= T; cid++) {
		work(cid);
	}

	return 0;
}