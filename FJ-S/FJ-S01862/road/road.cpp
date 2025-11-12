#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::clog;

constexpr size_t N = 1e4 + 5, E = 1e6 + 5, K = 10 + 5;

inline int read() {

	int res = 0;
	char ch = getchar();

	while(ch < '0' || ch > '9') {

		ch = getchar();
	}

	for( ; ch >= '0' && ch <= '9'; ch = getchar()) {

		res = (res << 1) + (res << 3) + (ch ^ '0');
	}

	return res;
}

struct edge_table {

	struct e {

		int to, nxt, val;

		inline e(int to = -1, int nxt = -1, int val = -1)

		: to(to), nxt(nxt), val(val) {

		}
	};

	e edge[E * 2];
	int head[N], idx = 0;

	inline void add(int u, int v, int w) {

		edge[++idx] = e(v, head[u], w);
		head[u] = idx;
	}
};

edge_table g;

int n;
int cost[K];
int w[K][N];

struct node {

	int val, u;

	inline node(int val, int u)

	: val(val), u(u) {
		
	}

	bool operator > (node y) const {
	
		return val > y.val;
	}	
};

std::priority_queue<node, std::vector<node>, std::greater<node> > q;
std::bitset<N + K> vis;

inline void clear() {
	
	std::priority_queue<node, std::vector<node>, std::greater<node> > tmp;
	q.swap(tmp);
	
	vis.reset();
}

long long prim(const std::vector<int> &add) {
	
	long long res = 0;
	
	clear();
	q.emplace(0, 1);
	
	while(q.empty() == false) {
		
		node t = q.top();
		q.pop();
		
		if(vis[t.u] == true) {
			
			continue;
		}
		
		vis[t.u] = true;
		res += t.val;
		
		if(t.u > n) {
			
			for(int i = 1; i <= n; ++i) {
				
				if(vis[i] == false) {
					
					q.emplace(w[t.u - n][i], i);
				}
			}
			
			continue;
		}
		
		for(int cur = g.head[t.u]; cur != 0; cur = g.edge[cur].nxt) {
			
			int v = g.edge[cur].to, w = g.edge[cur].val;
			
			if(vis[v] == false) {
				
				q.emplace(w, v);
			}
		}
		
		for(int v : add) {
			
			if(vis[v] == false) {
				
				q.emplace(w[v - n][t.u], v);
			}
		}
	}
	
	return res;
}

int main() {

    freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	n = read(); int m = read(), k = read();

	for(int i = 0, u, v, w; i < m; ++i) {

		u = read(); v = read(); w = read();

		g.add(u, v, w);
		g.add(v, u, w);
	}
	
	bool flag = true;

	for(int i = 1; i <= k; ++i) {

		cost[i] = read();
		flag &= cost[i] == 0;

		for(int j = 1; j <= n; ++j) {

			w[i][j] = read();
			flag &= w[i][j] == 0;
		}
	}
	
	if(flag) {
		
		cout << prim(std::vector<int>());
		return 0;
	}
	
	long long ans = LLONG_MAX;
	
	for(int i = 0; i < (1 << k); ++i) {

		std::vector<int> add;
		
		for(int j = 1, t = i; t > 0; ++j, t >>= 1)  {
			
			if((t & 1) == 1) {
				
				add.emplace_back(n + j);
			}
		}
		
		long long s = 0;
		
		for(int j : add) {
			
			s += cost[j - n];
		}
		
		ans = std::min(ans, prim(add) + s);
	}

	printf("%lld", ans);

	return 0;
}
