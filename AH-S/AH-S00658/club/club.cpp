#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL N = 1e5 + 10;

LL T, n, a[N][7];

LL ans = 0, cnt[7];
void dfs(LL cur, LL sum) {
	if (cur > n) {
		ans = max(ans, sum);
		return;
	}
	for (LL i = 1; i <= 3; i++) {
		if (cnt[i] == n / 2) continue;
		cnt[i]++;
		dfs(cur + 1, sum + a[cur][i]);
		cnt[i]--;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		ans = 0;
		bool A = true, B = true;
		memset(a, 0, sizeof a);
		memset(cnt, 0, sizeof cnt);
		scanf("%lld", &n);
		for (LL i = 1; i <= n; i++) {
			LL tmp = 0;
			for (LL j = 1; j <= 3; j++) {
				scanf("%lld", &a[i][j]);
				if (a[i][2] || a[i][3]) A = false;
				if (a[i][3]) B = false;
				if (a[i][j] > a[i][tmp]) tmp = j;
			}
			a[i][0] = tmp;
		}
		// if (n == 2) { // 4'
		// 	if (a[1][0] != a[2][0]) {
		// 		printf("%lld\n", a[1][a[1][0]] + a[2][a[2][0]]);
		// 		continue;
		// 	} else {
		// 		sort(a[1] + 1, a[1] + 4);
		// 		sort(a[2] + 1, a[2] + 4);
		// 		printf("%lld\n", max(a[1][3] + a[2][2], a[1][2] + a[2][3]));
		// 		continue;
		// 	}
		// }
		if (n <= 10) { // 20'
			dfs(1, 0);
			printf("%lld\n", ans);
			continue;
		}
		if (A) {
			LL x[N] = {0};
			for (LL i = 1; i <= n; i++) x[i] = a[i][1];
			sort(x + 1, x + n + 1);
			for (LL i = n / 2 + 1; i <= n; i++) {
				ans += x[i];
			}
			printf("%lld\n", ans);
		}
		LL sum = 0;
		for (LL i = 1; i <= n; i++) {
			cnt[a[i][0]]++;
			sum += a[i][a[i][0]];
		}
		if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
			printf("%lld\n", sum);
			continue;
		}
		if (B) {
			priority_queue<LL, vector<LL>, greater<LL> > pq;
			LL tmp = 0;
			if (cnt[1] >= n / 2) {
				tmp = cnt[1] - n / 2;
				for (LL i = 1; i <= n; i++) {
					if (a[i][0] == 1) pq.push(a[i][1] - a[i][2]);
				}
			} else {
				tmp = cnt[2] - n / 2;
				for (LL i = 1; i <= n; i++) {
					if (a[i][0] == 2) pq.push(a[i][2] - a[i][1]);
				}
			}
			for (LL i = 1; i <= tmp; i++) {
				sum -= pq.top(); pq.pop();
			}
			printf("%lld\n", sum);
			continue;
		}
		struct Node {
			LL x, cmd, id;
			bool operator > (const Node& rhs) const {
				return x > rhs.x;
			}
		};
		priority_queue<Node, vector<Node>, greater<Node> > q;
		if (cnt[3] > n / 2) {
			for (LL i = 1; i <= n; i++) {
				if (a[i][0] == 3) {
					LL m = a[i][3] - a[i][1];
					LL n = a[i][3] - a[i][2];
					if (m < n) {
						q.push({m, 1, i});
					} else {
						q.push({n, 2, i});
					}
				}
			}
			for (LL i = 1; i <= cnt[3] - n / 2; i++) {
				sum -= q.top().x;
				a[q.top().id][0] = q.top().cmd;
				q.pop();
			}
		}
		for (LL i = 1; i <= n; i++) {
			LL tmp = 0;
			for (LL j = 1; j <= 2; j++) {
				if (a[i][j] > a[i][tmp]) tmp = j;
			}
			a[i][0] = tmp;
		}
		priority_queue<LL, vector<LL>, greater<LL> > pq;
		LL tmp = 0;
		if (cnt[1] >= n / 2) {
			tmp = cnt[1] - n / 2;
			for (LL i = 1; i <= n; i++) {
				if (a[i][0] == 1) pq.push(a[i][1] - a[i][2]);
			}
		} else {
			tmp = cnt[2] - n / 2;
			for (LL i = 1; i <= n; i++) {
				if (a[i][0] == 2) pq.push(a[i][2] - a[i][1]);
			}
		}
		for (LL i = 1; i <= tmp; i++) {
			sum -= pq.top(); pq.pop();
		}
		printf("%lld\n", sum);
	}
	return 0;
}