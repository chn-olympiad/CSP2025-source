#include <bits/stdc++.h>
using namespace std;

void fileIO(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

using edge = array<int, 3>;

using i64 = long long;
const int N = 1e4 + 20, K = 12;

int n, k;

int kw[K][N];

int dsu[N];

int find(int x) {
	return dsu[x] > 0 ? dsu[x] = find(dsu[x]) : x;
}

bool merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return false;
	if(dsu[x] < dsu[y]) swap(x, y);
	dsu[y] += dsu[x];
	dsu[x] = y;
	return true;
}

i64 ans;
vector<edge> te, ke[K];

void solve(int msk) {
	i64 tans = 0;
	priority_queue<edge, vector<edge>, greater<edge> > kq;
	int nodes = n;
	for(int i = 0; i < k; i ++) {
		if((msk >> i) & 1) {
			tans += kw[i + 1][0];
			if(tans >= ans) return;
			kq.push(edge{ke[i + 1][0][0], i + 1, 0});
			nodes ++;
		}
	}
	
	fill(dsu + 1, dsu + n + k + 1, -1);
	for(int i = 0; nodes > 1; ) {
		if(i < te.size() && (kq.empty() || kq.top()[0] > te[i][0])) {
			if(merge(te[i][1], te[i][2])) {
				tans += te[i][0];
				nodes --;
				if(tans >= ans) return;
			}
			i ++;
		}else{
			int j = kq.top()[2];
			int x = kq.top()[1], y = ke[x][j][2];
			if(merge(x + n, y)) {
				tans += kq.top()[0];
				nodes --;
				if(tans >= ans) return;
			}
			kq.pop();
			if(j + 1 < ke[x].size()) kq.push({ke[x][j + 1][0], x, j + 1});
		}
	}
	ans = min(ans, tans);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	fileIO("road");
	
	int m;
	cin >> n >> m >> k;
	
	vector<edge> e(m);
	for(int i = 0; i < m; i ++)
		cin >> e[i][1] >> e[i][2] >> e[i][0];
	
	sort(e.begin(), e.end());
	fill(dsu + 1, dsu + n + 1, -1);
	for(int i = 0; i < m; i ++) {
		if(merge(e[i][1], e[i][2])) {
			te.push_back(e[i]);
			ans += e[i][0];
		}
	}
	
	for(int i = 1; i <= k; i ++) {
		for(int j = 0; j <= n; j ++) {
			cin >> kw[i][j];
			if(j) ke[i].push_back(edge{kw[i][j], n + i, j});
		}
		sort(ke[i].begin(), ke[i].end());
	}
	
	for(int i = 1; i < (1 << k); i ++)
		solve(i);
	cout << ans << "\n";
}
