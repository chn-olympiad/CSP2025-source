#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n;
int a[maxn][3], mx[maxn], cnt[3], b[maxn];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		cnt[0] = cnt[1] = cnt[2] = 0;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
			if (a[i][0] > a[i][1])
				mx[i] = a[i][0] > a[i][2] ? 0 : 2;
			else mx[i] = a[i][1] > a[i][2] ? 1 : 2;
			++cnt[mx[i]], ans += a[i][mx[i]];
		}
		int p = 0;
		if (cnt[0] > cnt[1])
			p = cnt[0] > cnt[2] ? 0 : 2;
		else p = cnt[1] > cnt[2] ? 1 : 2;
		if (cnt[p] <= n / 2) {
			printf("%d\n", ans);
			continue;
		}
		int tot = 0;
		for (int i = 1; i <= n; ++i)
			if (mx[i] == p)
				b[++tot] = a[i][0] + a[i][1] + a[i][2] - a[i][p] * 2 - min(a[i][0], min(a[i][1], a[i][2]));
		sort(b + 1, b + tot + 1);
		while (tot > n / 2)
			ans += b[tot--];
		printf("%d\n", ans);
	}
	return 0;
}
