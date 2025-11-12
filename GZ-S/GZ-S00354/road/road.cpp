//GZ-S00354 程泊郡 安顺市第二高级中学
#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, pair<int, int> > plii;
const int N = 1e4 + 10;
int fa[N];
int n, m, k;
long long v[N][N];
int r[N];
priority_queue<plii, vector<plii>, greater<plii> > q;

int fin(int x) {
	if (x == fa[x]) return x;
	else return fa[x] = fin(fa[x]);
}
long long ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			v[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		long long z;
		cin >> x >> y >> z;
		v[x][y] = min(v[x][y], z);
		q.push({z, {x, y}});
	}
	for (int i = 1; i <= k; i++) {
		int dian;
		cin >> dian;
		for (int j = 1; j <= n; j++) {
			cin >> r[j];
		}
		for (int j = 1; j < n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (v[j][k] > 0LL + dian + r[j] + r[k]) {
					v[j][k] = 0LL + dian + r[j] + r[k];
					q.push({v[j][k], {j, k}});
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	while (q.size()) {
		plii p = q.top();
		q.pop();
		if (fin(p.second.first) != fin(p.second.second)) {
			fa[fin(p.second.first)] = p.second.second;
			ans += p.first;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}