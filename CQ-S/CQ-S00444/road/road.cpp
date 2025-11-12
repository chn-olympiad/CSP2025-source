#include <bits/stdc++.h>
using namespace std;

#define LOCAL
//#define DEBUG

typedef long long int ll;
typedef pair<int, int> PII;

const int N = 1e4 + 50, M = 1e6 + 1e5 + 1e3 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m, k, cnt, ans;
int a[N], c[N];
int dis[1010][1010];

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int _u, int _v, int _w) {
		u = _u;
		v = _v;
		w = _w;
	}
	
	inline bool operator < (const Edge& other) const {
		return w < other.w;
	}
} edge[M];

class DSU_class {
private:
	int fath[N];
public:
	inline void init(int n) {
		for (int i = 1; i <= n; i ++) {
			fath[i] = i;
		}
	}
	
	inline int get_father(int x) {
		return (x == fath[x] ? fath[x] : fath[x] = get_father(fath[x]));
	}
	
	inline bool unite(int x, int y) {
		x = get_father(x);
		y = get_father(y);
		
		if (x == y) return false;
		fath[x] = y;
		return true;
	}
} DSU;

#if defined(__unix__) || defined(__linux__)
#define getchar getchar_unlocked
#else
#define getchar _getchar_nolock
#endif

namespace IO_fast_int32 {
	inline void read(int& x) {
		x = 0;
		int f = 1;
		char ch = getchar();

		while (!isdigit(ch)) {
			if (ch == '-') f = -1;
			ch = getchar();
		}

		while (isdigit(ch)) {
			x = (x << 3) + (x << 1) + (ch ^ 48);
			ch = getchar();
		}

		x = x * f;
	}

	inline void write(int x) {
		if (x < 0) {
			putchar('-');
			x = -x;
		}

		if (x > 9) write(x / 10);
		putchar((char)(x % 10 + 48));
	}

	inline void writefln(int x) {
		write(x);
		putchar(' ');
	}

	inline void writeln(int x) {
		write(x);
		putchar('\n');
	}

	template <typename ..._Tp>
	inline void read(int& x, _Tp& ...y) {
		read(x);
		read(y...);
	}

	template <typename ..._Tp>
	inline void writefln(int x, _Tp ...y) {
		writefln(x);
		writefln(y...);
	}

	template <typename ..._Tp>
	inline void writeln(int x, _Tp ...y) {
		writeln(x);
		writeln(y...);
	}
}

using namespace IO_fast_int32;

vector<Edge> edge1;

inline void solve() {
	read(n, m, k);
	
	for (int i = 1; i <= m; i ++) {
		int u, v, w;
		read(u, v, w);
		edge[i] = Edge(u, v, w);
		edge1.push_back(edge[i]);
	}
	bool flag1 = true;
	for (int i = 1; i <= k; i ++) {
		read(c[i]);
		if (c[i] != 0) flag1 = false;
		for (int j = 1; j <= n; j ++) {
			int x;
			read(x);
			if (flag1) edge[++ m] = Edge(i + n, j, x);
			dis[i][j] = x; 
		}
	}
	
	if (flag1) {
		int i = 1;
		cnt = 0;
		sort(edge + 1, edge + m + 1);
		
		DSU.init(n + k);
		
		while (i <= m && cnt < n + k - 1) {
			int u = edge[i].u, v = edge[i].v;
		
			if (DSU.unite(u, v)) {
				ans += edge[i].w;
				cnt ++;
			}
			
			i ++;
		}
	} else {
		ans = INF;
		for (int mask = 0; mask < (1 << k); mask ++) {
			int now = 0;
			vector<Edge> edge2 = edge1;
			
			for (int i = 1; i <= k; i ++) {
				if (mask & (1 << (i - 1)) == 1) {
					now += c[i];
					for (int j = 1; j <= n; j ++) edge2.push_back(Edge(i + n, j, dis[i][j]));
				}
			}
			
			int i = 0;
			cnt = 0;
			int len = edge2.size();
			sort(edge2.begin(), edge2.end());
			
			DSU.init(n + k);
			
			while (i < len && cnt < n + k - 1) {
				int u = edge2[i].u, v = edge2[i].v;
				if (DSU.unite(u, v)) {
					now += edge2[i].w;
					cnt ++;
				}
				
				i ++;
			}
			
			ans = min(ans, now);
		}
	}
	
	write(ans);
}

int main(int argc, const char *argv[]) {
#ifdef LOCAL
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#else defined(DEBUG)
	freopen("road4.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = 1;
//	cin >> t;

	while (t --) {
		solve();
	}

	return 0;
}

