#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int T, n, a[MAXN][3], cnt[3], ans, b[3][MAXN];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				scanf("%d", &a[i][j]);
		ans = cnt[0] = cnt[1] = cnt[2] = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
				ans += a[i][0], b[0][++cnt[0]] = min(a[i][0] - a[i][1], a[i][0] - a[i][2]);
			else if (a[i][1] >= a[i][2])
				ans += a[i][1], b[1][++cnt[1]] = min(a[i][1] - a[i][0], a[i][1] - a[i][2]);
			else
				ans += a[i][2], b[2][++cnt[2]] = min(a[i][2] - a[i][0], a[i][2] - a[i][1]);
		}
		for (int j = 0; j < 3; j++) {
			if (cnt[j] <= n / 2) continue;
			sort(b[j] + 1, b[j] + 1 + cnt[j]);
			for (int i = 1; i <= cnt[j] - n / 2; i++)
				ans -= b[j][i];
		}
		printf("%d\n", ans);
	}
	return 0;
}

