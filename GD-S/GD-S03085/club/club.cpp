#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
void work() {
	int n, x, ans = 0;
	scanf("%d", &n);
	int cnt[4] = {};
	vector <int> v[4];
	for (int i = 1; i <= n; i++) {
		pair <int, int> p[4];
		for (int j = 1; j <= 3; j++)
			scanf("%d", &x),
			p[j] = {x, j};
		sort(p + 1, p + 4);
		cnt[p[3].second]++;
		ans += p[3].first;
		v[p[3].second].push_back(p[3].first - p[2].first);
	}
	for (int i = 1; i <= 3; i++)
		if (cnt[i] > n / 2) {
			sort(v[i].begin(), v[i].end());
			for (int j = 0; j < cnt[i] - n / 2; j++)
				ans -= v[i][j];
			printf("%d\n", ans);
			return;
		}
	printf("%d\n", ans);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}
