#include<bits/stdc++.h>

const int N = 1e5 + 7, inf = 1e9;

int n, a[N][3], d[N], cnt[3], p[N], pcnt;
long long ans;

void solve() {
	scanf("%d", &n);
	cnt[0] = 0, cnt[1] = 0, cnt[2] = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
			d[i] = 0, ++cnt[0], ans += a[i][0];
		else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2])
			d[i] = 1, ++cnt[1], ans += a[i][1];
		else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][0])
			d[i] = 2, ++cnt[2], ans += a[i][2];
	}
	if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2)
		printf("%d\n", ans);
	else {
		int u;
		for (int i = 0; i < 3; ++i)
			if (cnt[i] > n / 2)
				u = i;
		pcnt = 0;
		for (int i = 1; i <= n; ++i)
			if (d[i] == u) {
				p[++pcnt] = inf;
				for (int j = 0; j < 3; ++j)
					if (j != u)
						p[pcnt] = std::min(p[pcnt], a[i][u] - a[i][j]);
			}
		std::sort(p + 1, p + pcnt + 1);
		for (int i = 1; i <= cnt[u] - n / 2; ++i)
			ans -= p[i];
		printf("%d\n", ans);
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("club1.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
