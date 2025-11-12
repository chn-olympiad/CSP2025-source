#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1 << 30;

const int N = 200 + 3;

int f[N][N];
bool vis[N * 3000];
int cnt[3];

void solve () {
	int n;
	scanf ("%d", &n);
	if (n <= 200) {
		memset(f, 128, sizeof(f));
		f[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			int x, y, z;
			scanf ("%d%d%d", &x, &y, &z);
			for (int j = n / 2; j >= 0; j--)
				for (int k = n / 2; k >= 0; k--) if (f[j][k] >= 0) {
					if (j < n / 2) f[j + 1][k] = max(f[j + 1][k], f[j][k] + x);
					if (k < n / 2) f[j][k + 1] = max(f[j][k + 1], f[j][k] + y);
					if (i - j - k <= n / 2) f[j][k] += z;
				}
		}
		int ans = 0;
		for (int i = 0; i <= n / 2; i++) for (int j = 0; j <= n / 2; j++) ans = max(ans, f[i][j]);
		printf("%d\n", ans);	
	}
	else {
		memset(cnt, 0, sizeof(cnt));
		memset(vis, 0, sizeof(vis));
		priority_queue<pair<int, pair<int, int>>> q;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int x, y, z;
			scanf ("%d%d%d", &x, &y, &z);
			ans += x;
			q.push({y - x, {1, i}});
			q.push({z - x, {2, i}});
		}
		int lv = 0;
		while (!q.empty()) {
			pair<int, pair<int, int>> x = q.top();
			q.pop();
			if (vis[x.second.second]) continue;
			if (cnt[x.second.first] == n / 2) continue;
			if (lv >= n / 2 && x.first < 0) break;
			vis[x.second.second] = 1;
			cnt[x.second.first]++;
			ans += x.first;
			++lv;
		}
		printf("%d\n", ans);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int tc;
	scanf ("%d", &tc);
	for (; tc--; )
		solve();
}
