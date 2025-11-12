#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int T, n, k, a[N][4], ans;
void dfs(int i, int s1, int s2, int s3, int sum) {
	if (i == n + 1) {
		ans = max(ans, sum);
		return;
	}
	if (s1 + 1 <= k)
		dfs(i + 1, s1 + 1, s2, s3, sum + a[i][1]);
	if (s2 + 1 <= k)
		dfs(i + 1, s1, s2 + 1, s3, sum + a[i][2]);
	if (s3 + 1 <= k)
		dfs(i + 1, s1, s2, s3 + 1, sum + a[i][3]);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		k = n / 2;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				scanf("%d", &a[i][j]);
		ans = 0;
		dfs(1, 0, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}    
/*#include <bits/stdc++.h>
using namespace std;

struct info {
	int v, x, y;
	bool operator < (const info &A) const {
		return v < A.v;
	}
};
const int N = 100010;
int T, n, a[N][4], d[N][4], r[4][N];
pair<int, int> c[4][N];
priority_queue<info> q;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int k = n / 2;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++) {
				scanf("%d", &a[i][j]);
				c[j][i] = {a[i][j], i};
			}
		while (!q.empty()) q.pop();
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= 3; i++) {
			sort(c[i] + 1, c[i] + n + 1, greater<pair<int, int>>());
			for (int j = 1; j <= n; j++) {
				r[i][c[i][j].second] = j;
			}
			for (int j = 1; j <= k; j++)
				d[c[i][j].second][i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= 3; j++)
				sum += d[i][j];
			if (sum > 1) {
				for (int j = 1; j <= 3; j++)
					if (d[i][j])
						q.push({-a[i][j], i, j});
			}
		}
		while (!q.empty()) {
			int x = q.top().x, y = q.top().y;
			q.pop();
			int sum = 0;
			for (int i = 1; i <= 3; i++)
				sum += d[x][i];
			if (sum == 1) continue;
			d[x][y] = 0;
			if (r[y][x] < n) {
				for (int i = 1; i <= 3; i++)
					if (d[pos][i])
						q.push({-a[pos][i], pos, i});
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int sum = 0, ma = 0, tot = 0;
			for (int j = 1; j <= 3; j++) {
				sum += d[i][j];
				ma = max(ma, a[i][j]);
				tot += d[i][j] * a[i][j];
			}
			if (sum == 0)
				ans += ma;
			else
				ans += tot;
		}
		printf("%d\n", ans);
	}
	return 0;
}*/ 
