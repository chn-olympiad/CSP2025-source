//GZ-S00042 贵阳市第一中学 刘信果
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+5;
int T, n, a[4], cnt[4], d[4][N], sum;
struct People {
	struct Node {
		int id, val;
	}fi, se;
	void add() {
		for (int i = 1; i <= 3; ++i) {
			if (a[i] >= fi.val)
				fi = {i, a[i]};
		}
		for (int i = 1; i <= 3; ++i) {
			if (i == fi.id) continue;
			if (a[i] >= se.val)
				se = {i, a[i]};
		}
	}
}p[N];

void init() {
	for (int i = 1; i <= n; ++i)
		p[i].fi.id = p[i].fi.val = p[i].se.id = p[i].se.val = 0;
	memset(cnt, 0, sizeof cnt);
	memset(d, 0, sizeof d);
	sum = 0;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n, init();
		for (int i = 1; i <= n; ++i) {
			cin >> a[1] >> a[2] >> a[3];
			p[i].add();
		}
		for (int i = 1; i <= n; ++i) {
			d[p[i].fi.id][++cnt[p[i].fi.id]] = p[i].fi.val-p[i].se.val;
			sum += p[i].fi.val;
		}
		int unlim = 0;
		for (int i = 1; i <= 3; ++i)
			if (cnt[i] > n/2) unlim = i;
		if (unlim) {
			sort(d[unlim]+1, d[unlim]+cnt[unlim]+1);
			for (int i = 1; i <= cnt[unlim]-n/2; ++i)
				sum -= d[unlim][i];
		}
		cout << sum << endl;
	}
	return 0; 
}
