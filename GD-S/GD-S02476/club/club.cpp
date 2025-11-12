#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
using lnt = long long;
using std::cin;
using std::cout;

void stream_init() {
	cin.tie(nullptr)->sync_with_stdio(false);
}

#define data std::array<int, 3>

struct node {
	data v;
	int id;
	int get_v() const {
		if (id == 0) return v[0] - std::max(v[1], v[2]);
		else if (id == 1) return v[1] - std::max(v[0], v[2]);
		else return v[2] - std::max(v[0], v[1]);			
	}
	int get_mx() const {
		if (id == 0) return (v[1] > v[2] ? 1 : 2);
		else if (id == 1) return (v[0] > v[2] ? 0 : 2); 
		else return (v[0] > v[1] ? 0 : 1); 
	}
	bool operator <(const node &a) const {
		return a.get_v() < get_v();
	}
	int real() const { return v[id]; }
};

void solve() {
	std::priority_queue<node> q[3];
	int n, lim; cin >> n, lim = n >> 1;
	
	for (int i = 0; i < n; ++i) {
		data v; cin >> v[0] >> v[1] >> v[2];
		
		data res;
		data rk = {0, 1, 2};
		for (int e = 0; e < 3; ++e) {
			if (q[e].size() < lim) {
				res[e] = v[e];
			} else {
				node u = q[e].top();
				res[e] = ((node){v, e}).get_v() - u.get_v();
			}
		}
		
		std::sort(rk.begin(), rk.end(), [&res](int x, int y) -> bool {
			return res[x] > res[y];
		});
		
		int c = rk[0];
		if (q[c].size() == lim) {
			node u = q[c].top();
			q[c].pop();
			int p = u.get_mx();
			q[p].push({u.v, p});
		}
		q[c].push({v, c});
		
	}
	
	int ans = 0;
	
	for (int i = 0; i < 3; ++i) {
		while (!q[i].empty()) {
			ans += q[i].top().real();
			q[i].pop();
		}
	}
	
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	stream_init();

	int T; cin >> T;
	while (T--) {
		solve();
	}
	
	return 0;
}
