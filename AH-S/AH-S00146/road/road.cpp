#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int read() {
	int x = 0; char c = getchar();
	while (c < '0' || c > '9') { c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	return x;
}

struct edge {
	friend bool operator < (const edge &a, const edge &b) {
		return a.w < b.w;
	}
	long long u, v, w;
};

#define MAXK 10
#define MAXN 10000

long long n, m, k;
vector <edge> edges;
long long c[MAXK + 10], a[MAXK + 10][MAXN + 10];
bool flagA = true, tf;

namespace KKK {
	class DJSet {
	private:
		int fa[MAXN + 10];
	public:
		DJSet(int n) {
			for (int i = 1; i <= n; ++i) fa[i] = i;
			return;
		}
		
		bool inquire(int x, int y) {
			return qe(x) == qe(y);
		}
		
		void fUnion(int x, int y) {
			fa[qe(x)] = qe(y);
		}
		
		int qe(int x) {
			if (fa[x] == x) return x;
			return fa[x] = qe(fa[x]);
		}
	};
	
	long long kkk(vector <edge> es) {
		DJSet mySet(n);
		long long ans = 0;
		sort(es.begin(), es.end());
		for (int i = 0; i < m; ++i) {
			if (!mySet.inquire(es[i].u, es[i].v)) {
				ans += es[i].w;
				mySet.fUnion(es[i].u, es[i].v);
			}
		}
		return ans;
	}
};

long long anss = 1e18;

vector <edge> f(vector <edge> es, int idx) {
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			es.push_back({i, j, a[idx][i] + a[idx][j]});
		}
	}
	return es;
}

void dfs(int idx, long long val, vector <edge> es) {
	if (idx == k + 1) {
		long long tmp = KKK::kkk(es) + val;
		if (tmp < anss) anss = tmp;
		return;
	}
	m = m + n * (n - 1) / 2;
	dfs(idx + 1, val + c[idx], f(es, idx));
	m = m - n * (n - 1) / 2;
	dfs(idx + 1, val, es);
	return;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1, u, v, w; i <= m; ++i) {
		u = read(), v = read(), w = read();
		edges.push_back({u, v, w});
	}
	for (int i = 1; i <= k; ++i) {
		c[i] = read();
		if (c[i]) flagA = false;
		tf = false;
		for (int j = 1; j <= n; ++j) {
			a[i][j] = read();
			if (!a[i][j]) tf = true;
		}
		if (!tf) flagA = false;
	}
	if (k == 0) {
		printf("%lld\n", KKK::kkk(edges));
		return 0;
	}
	if (flagA) {
		for (int ii = 1; ii <= k; ++ii) {
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					++m;
					edges.push_back({i, j, a[ii][i] + a[ii][j]});
				}
			}
		}
		printf("%lld\n", KKK::kkk(edges));
		return 0;
	}
	dfs(1, 0, edges);
	printf("%lld\n", anss);
	return 0;
}
