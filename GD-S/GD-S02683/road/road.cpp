#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define repm(i, begin, end) for (int i = begin; i < end; i += 1)
#define rep(i, n) repm(i, 0, n)

using namespace std;
using llu = long long unsigned;

const bool debugm = true;

template<typename... Args>
void debug(const Args... arg) {
	if (debugm) {
		(int[]) {
			(void(cerr << arg << " "), 0)
			... 
		};
		
		cerr << endl;
	}
}

void set_io() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

struct UnionFind {
	vector<int> father;
	
	UnionFind(size_t n) : father(n, -1) {}
	
	int id_of(int x) {
		if (father[x] == -1) return x;
		father[x] = id_of(father[x]);
		return father[x];
	}
	
	bool be_connected(int a, int b) {
		return id_of(a) == id_of(b); 
	}
	
	void connect(int a, int b) {
		father[id_of(a)] = id_of(b);
	}
};

struct edge {
	int u, v, w;
	
	friend bool operator>(const edge& a, const edge& b) {
		return a.w > b.w;
	}
};

struct Data {
	int n, m, k;
	vector<int>& c;
	vector<vector<int>>& a;
	priority_queue<edge, vector<edge>, greater<edge>>& q;
};

void dfs(int now, vector<bool>& use, const Data& dt, llu& ans) {
	int n = dt.n,
		m = dt.m,
		k = dt.k;
	
	
	if (now < k) {
		use[now] = true;
		dfs(now + 1, use, dt, ans);
		
		use[now] = false;
		dfs(now + 1, use, dt, ans);
		
		return;
	}
	
	llu res = 0;
	priority_queue<edge, vector<edge>, greater<edge>> q(dt.q);
	
	rep(t, k) {
		if (!use[t]) continue;
		res += dt.c[t];
		
		rep(i, n) {
			rep(j, i) {
				q.push({i, j, dt.a[t][i]+dt.a[t][j]});
			}
		}
	}
	
	UnionFind uf(n);
	int u, v, w, cnt = 0;;
	
	while(!q.empty()) {
		edge e = q.top();
		q.pop();
		
		u = e.u, v = e.v, w = e.w;
		if (uf.be_connected(u, v)) continue;
		
		//debug(u, v, w);
		uf.connect(u, v);
		
		res += w;
		cnt += 1;
	}
	
	if (cnt == n-1) {
		ans = min(ans, res);
	}
}

int main() {
	set_io();
	
	int n, m, k;
	cin >> n >> m >> k;
	
	priority_queue<edge, vector<edge>, greater<edge>> q;
	int u, v, w;
	
	rep(i, m) {
		cin >> u >> v >> w;
		u -= 1; v -= 1;
		q.push({u, v, w});
	}
	
	vector<int> c(k);
	vector<vector<int>> a(k, vector<int>(n));
	
	rep(i, k) {
		cin >> c[i];
		
		rep(j, n) {
			cin >> a[i][j];
		}
		
		if (c[i] == 0) {
			rep(h, n) {
				rep(g, h) {
					q.push({h, g, a[i][h]+a[i][g]});
				}
			}
			i -= 1;
			k -= 1;
		}
	}
	
	c.resize(k);
	a.resize(k);
	
	vector<bool> use(k);
	llu ans = numeric_limits<llu>::max();
	
	dfs(0, use, {n, m, k, c, a, q}, ans);
	
	cout << ans << endl;
	return 0;
}
