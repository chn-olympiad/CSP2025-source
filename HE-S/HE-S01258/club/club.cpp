#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
struct Node {
	int id, diff, max2;
	bool operator> (const Node &rhs) const {
		return diff > rhs.diff;
	}
};
int a[MAXN][5];
int n;
priority_queue<Node, vector<Node>, greater<Node>> pq[5];

inline int getmax(int p) {
	if (a[p][1] == max({a[p][1], a[p][2], a[p][3]})) return 1;
	else if (a[p][2] == max(a[p][2], a[p][3])) return 2;
	else return 3;
}
inline int getmax2(int p) {
	int x = getmax(p);
	if (x == 1) return a[p][2] > a[p][3] ? 2 : 3;
	else if (x == 2) return a[p][1] > a[p][3] ? 1 : 3;
	else return a[p][1] > a[p][2] ? 1 : 2;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = getmax(i), y = getmax2(i);
		// cerr << i << ": " << x << " " << y << endl;
		assert(a[i][x] >= a[i][y]);
		if (pq[x].size() + 1 <= n / 2) pq[x].push({i, a[i][x] - a[i][y], y}), ans += a[i][x];
		else {
			if (pq[x].top().diff < a[i][x] - a[i][y]) {
				int id = pq[x].top().id, max2 = pq[x].top().max2; 
				// cerr << "B " << id << endl;
				ans -= pq[x].top().diff;
				pq[x].pop();
				assert(max2 >= 1);
				pq[max2].push({id, -1, -1}); pq[x].push({i, a[i][x] - a[i][y], y});
				ans += a[i][x];
			}
			else {
				// cerr << "C" << endl;
				pq[y].push({i, -1, -1});
				ans += a[i][y];
			}
		}
		// cerr << ans << endl;
	}

	cout << ans << endl;
}
void init() {
	for (int i = 1; i <= 3; i++) {
		while (!pq[i].empty()) pq[i].pop();
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
		init();
	}

	return 0;
}