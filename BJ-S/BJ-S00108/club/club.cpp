#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int T, n, ans;
array<int, 2> a[3];
vector<int> cost[3];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		for (int i = 0; i < 3; i ++) cost[i].clear();
		ans = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d%d", &a[0][0], &a[1][0], &a[2][0]);
			for (int j = 0; j < 3; j ++) a[j][1] = j;
			sort(a, a + 3, greater<array<int, 2> >());
			ans += a[0][0];
			cost[a[0][1]].push_back(a[1][0] - a[0][0]);
		}
		for (int i = 0; i < 3; i ++) {
			if ((int) cost[i].size() > n / 2) {
				sort(cost[i].begin(), cost[i].end());
				while ((int) cost[i].size() > n / 2) {
					ans += cost[i].back();
					cost[i].pop_back();
				}
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
