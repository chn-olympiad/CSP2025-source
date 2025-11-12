// GZ-S00280 贵阳市第一实验中学 林钰涵
#include <bits/stdc++.h>
using namespace std;

int n, ans, cnt[5], a[100005][5], v[5][100005];

inline int fi(int i) {
	if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) return a[i][1];
	if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) return a[i][2];
	return a[i][3];
}

inline int th(int i) {
	if (a[i][1] <= a[i][2] && a[i][1] <= a[i][3]) return a[i][1];
	if (a[i][2] <= a[i][1] && a[i][2] <= a[i][3]) return a[i][2];
	return a[i][3];
}

inline int se(int i) {
	if (a[i][1] == a[i][2]) return a[i][1];
	if (a[i][1] == a[i][3]) return a[i][1];
	if (a[i][2] == a[i][3]) return a[i][2];
	int mx = fi(i), mn = th(i);
	if (a[i][1] != mx && a[i][1] != mn) return a[i][1];
	if (a[i][2] != mx && a[i][2] != mn) return a[i][2];
	return a[i][3];
}

bool cmp(int x, int y) {
	return fi(x) - se(x) > fi(y) - se(y);
}

inline void solve() {
	scanf("%d", &n);
	ans = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &a[i][j]);
		}
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) ans += a[i][1], v[1][++cnt[1]] = i;
		else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) ans += a[i][2], v[2][++cnt[2]] = i;
		else ans += a[i][3], v[3][++cnt[3]] = i;
	}
	for (int i = 1; i <= 3; i++) {
		if (cnt[i] * 2 > n) {
			sort(v[i] + 1, v[i] + cnt[i] + 1, cmp);
			while (cnt[i] * 2 > n) {
				ans -= fi(v[i][cnt[i]]) - se(v[i][cnt[i]]);
				--cnt[i];
			}
		}
	}
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _;
	for (scanf("%d", &_); _; --_) {
		solve();
	}
	return 0;
}
