# include<bits/stdc++.h>
# define N 100005
using namespace std;
int T, n, ans, b[N][5];
struct note {
	int opt, val;
	bool operator < (const note & x) const {
		return val > x.val;
	}
} a[N][5];
int cnt[5];
priority_queue<pair<int, int>> q[5];
void csh() {
	ans = 0;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= 3; i ++)
		while(q[i].size())
			q[i].pop();
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> T;
	while(T --) {
		cin >> n;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= 3; j ++)
				cin >> a[i][j].val, a[i][j].opt = j, b[i][j] = a[i][j].val;
		for(int i = 1; i <= n; i ++)
			sort(a[i] + 1, a[i] + 4);
		csh();
		for(int i = 1; i <= n; i ++) {
			if(cnt[a[i][1].opt] == n / 2) {
				if(q[a[i][1].opt].top().first > - (a[i][1].val - a[i][2].val)) {
					int u = i, v = q[a[u][1].opt].top().second;
					q[a[u][1].opt].pop();
					q[a[u][1].opt].push({- (a[u][1].val - a[u][2].val), u});
					q[a[v][2].opt].push({0, v});
				} else
					q[a[i][2].opt].push({0, i});
			} else
				q[a[i][1].opt].push({- (a[i][1].val - a[i][2].val), i}), cnt[a[i][1].opt] ++;
		}
		for(int i = 1; i <= 3; i ++)
			while(q[i].size())
				ans += b[q[i].top().second][i], q[i].pop();
		cout << ans << endl;
	}
	return 0;
}