#include <bits/stdc++.h>
#define PLL pair<long long, long long>
#define x first
#define y second
using namespace std;
const int N = 1000010;
priority_queue<PLL, vector<PLL>, greater<PLL> > q[4];
long long n, t, ans, p[N];
PLL d[N][5];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(nullptr) ->sync_with_stdio(false);
	for (cin >> t; t --; cout << ans << "\n") {
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> d[i][1].x >> d[i][2].x >> d[i][3].x;
			d[i][1].y = 1, d[i][2].y = 2,  d[i][3].y = 3;
			sort(d[i] + 1, d[i] + 4, greater<PLL>());
			q[d[i][1].y].push({d[i][1].x - d[i][2].x, i});
			p[i] = 1;
		}
		bool flag = 1;
		while (flag) {
			flag = 0;
			for (int i = 1; i <= 3; i ++)
				while (q[i].size() > n / 2) {
					long long u = q[i].top().y;
					q[i].pop();
					++ p[u];
					q[d[u][p[u]].y].push({d[u][p[u]].x - d[u][p[u] + 1].x, u});
					flag = 1;
				}
		}
		for (int i = 1; i <= 3; i ++)
			while (!q[i].empty())
				ans += d[q[i].top().y][p[q[i].top().y]].x, q[i].pop();
	}
	return 0;
}

