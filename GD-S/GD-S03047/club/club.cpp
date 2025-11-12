#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5 + 5, ot[4][2] = {{0, 0}, {2, 3}, {1, 3}, {2, 3}};
int T, n, s[N][5], ans, a[5][N], dp[205][105][105];
bool f[N];
bool A() {
	for (int i = 1; i <= n; i++) if (s[i][2] || s[i][3]) return false;
	return true;
}
int aa[N];
struct node {
	int cst, id;
	bool operator< (const node &u) const {return cst > u.cst;}
};
priority_queue<node> q;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d%d%d", s[i] + 1, s[i] + 2, s[i] + 3);
		ans = 0;
		if (n <= 200) {
			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= n; i++)
				for (int j = 0; j <= i && j <= (n >> 1); j++)
					for (int k = i - j - (n >> 1); k + j <= i && k <= (n >> 1); k++) {
						if (j) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + s[i][1]);
						if (k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + s[i][2]);
						if (i - j - k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + s[i][3]);
					}
			for (int j = 0; j <= n && j <= (n >> 1); j++)
				for (int k = n - j - (n >> 1); k + j <= n && k <= (n >> 1); k++)
					ans = max(ans, dp[n][j][k]);
		}
		else if (A()) {
			for (int i = 1; i <= n; i++) aa[i] = s[i][1];
			sort(aa + 1, aa + n + 1);
			for (int i = n; i > (n >> 1); i--) ans += aa[i];
		}
		else {
			memset(a, 0, sizeof(a));
			memset(f, 0, sizeof(f));
			for (int i = 1; i <= n; i++) {
				if (s[i][1] >= s[i][2] && s[i][1] >= s[i][3]) a[1][++a[1][0]] = i, ans += s[i][1];
				else if (s[i][2] >= s[i][1] && s[i][2] >= s[i][3]) a[2][++a[2][0]] = i, ans += s[i][2];
				else a[3][++a[3][0]] = i, ans += s[i][3];
			}
			while (!q.empty()) q.pop();
			int x = 0;
			if (a[1][0] > (n >> 1)) x = 1;
			else if (a[2][0] > (n >> 1)) x = 2;
			else if (a[3][0] > (n >> 1)) x = 3;
			if (x) {
				for (int i = 1; i <= a[x][0]; i++)
					q.push({s[a[x][i]][x] - s[a[x][i]][ot[x][0]], a[x][i]}), q.push({s[a[x][i]][x] - s[a[x][i]][ot[x][1]], a[x][i]});
				int tot = a[x][0];
				while (tot > (n >> 1) && !q.empty())  {
					int cst = q.top().cst, id = q.top().id; q.pop();
					if (f[id]) continue;
					f[id] = true;
					ans -= cst, tot--;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
