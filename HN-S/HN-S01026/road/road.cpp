#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;

const int N = 1e4 + 5;
int n, m, k;
ll b[15][N], c[15], d[N], ans, cnt = 1e18;
bool f;
vector<pii> e[N];

void bfs() {
	queue<pii> q;
	q.push({0, 1});
	d[1] = 0;
	while (q.size()) {
		int x = q.front().second;
		q.pop();
		for (auto p : e[x]) {
			int y = p.second;
			ll cc = p.first;
			if (d[x] + cc < d[y]) {
				d[y] = d[x] + cc;
				q.push({d[y], y});
			}
		}
		for (int y = 1; y <= n; y++) {
			if (y == x) continue;
			ll sum = 1e18;
			for (int i = 1; i <= k; i++) if (c[i] < sum) sum = min(sum, b[i][x] + b[i][y] + c[i]);
			if (d[x] + sum < d[y]) {
				d[y] = d[x] + sum;
				q.push({d[y], y});
			}
		}
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	fill(d, d + N, 1e18);
	while (m--) {
		int x, y;
		ll z;
		cin >> x >> y >> z;
		e[x].push_back({z, y});
		e[y].push_back({z, x});
	}
	for (int j = 1; j <= k; j++) {
		cin >> c[j];
		for (int i = 1; i <= n; i++) {
			cin >> b[j][i];
			if (b[j][i]) f = 1;
		}
		if (c[j]) f = 1;
	}
	if (!f) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) sort(e[i].begin(), e[i].end());
	bfs();
	for (int i = 2; i <= n; i++) ans = max(d[i], ans), cnt = min(cnt, d[i]);
	cout << ans + cnt - 1;
	return 0;
}
