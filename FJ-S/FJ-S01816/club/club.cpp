#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

/*
首先直接贪。那么最多只有一个部门的人数超了。
考虑调整。发现人数一定超不了。 
时间复杂度 O(nlogn) 或 O(n)。
*/

int T, n, a[3][MAXN], p[MAXN], c[3]; ll ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &n), ans = 0;
		for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[0][i], &a[1][i], &a[2][i]);
		for (int i = 0; i < 3; i++) c[i] = 0;
		for (int i = 1; i <= n; i++) {
			p[i] = 0;
			for (int j = 0; j < 3; j++) if (a[p[i]][i] < a[j][i]) p[i] = j;
			ans += a[p[i]][i], c[p[i]]++;
		}
		int k = 0;
		for (int i = 0; i < 3; i++) if (c[k] < c[i]) k = i;
		if (c[k] <= n / 2) { printf("%lld\n", ans); continue; }
		vector<pair<int, int>> tmp;
		for (int i = 1; i <= n; i++) {
			if (p[i] != k) continue; int y = 0;
			for (int j = 0; j < 3; j++) if (j != p[i]) y = max(y, a[j][i]);
			tmp.emplace_back(make_pair(a[p[i]][i] - y, i));
		}
		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < c[k] - n / 2; i++) ans -= tmp[i].first;
		printf("%lld\n", ans);
	}
}
