/*-- Confidence works miracles. --*/
// Time Limit: 1.0 s
// Memory Limit: 512 MB
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef __int128 i128;
#define I inline
#define reg register
typedef pair<int, int> pint;
#define fi first
#define se second
#define mk make_pair

char BG;

namespace FastIO {
	char ibuf[(1<<21)+1], *p1 = ibuf, *p2 = ibuf, obuf[1<<22], *O = obuf;
	#define gh() (((p1==p2)&&(p2=(p1=ibuf)+fread(ibuf,1,1<<21,stdin)),p1==p2)?EOF:*p1++)
	I int read() {
		reg int x = 0, sgn = 1;
		reg char c = gh();
		while (!isdigit(c)) (c=='-')&&(sgn=-1), c = gh();
		while (isdigit(c)) x = (x<<3)+(x<<1)+(c^48), c = gh();
		return x*sgn;
	}
	I void putc(char c) { *O++ = c; }
	void write(int x) {
		if (x < 0) *O++ = '-', x = -x;
		if (x > 9) write(x/10);
		*O++ = x%10+'0';
	}
	I void flush() {
		fwrite(obuf, O-obuf, 1, stdout);
		O = obuf;
	}
}
using namespace FastIO;

constexpr int N = 1e4+25;

int n, m, k;
struct Node {
	int u, v, w, idx;
	friend bool operator < (const Node& x, const Node& y) {
		return x.w < y.w;
	}
}; 
vector<Node> ed, vec;

int ds[1<<10][N];
i64 rst[1<<10];
int find(int* fa, int x) {
	return fa[x] < 0 ? x : fa[x] = find(fa, fa[x]);
}

char ED;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read();
		ed.push_back(Node{u, v, w, 0});
	}
	sort(ed.begin(), ed.end());
	memset(ds[0], -1, sizeof ds[0]);
	for (Node x : ed) {
		int u = find(ds[0], x.u), v = find(ds[0], x.v);
		if (u != v) {
			vec.push_back(x);
			if (ds[0][u] > ds[0][v]) swap(u, v);
			ds[0][u] += ds[0][v];
			ds[0][v] = u;
		}
	}
	for (int i = 1; i <= k; i++) {
		int c = read(), v;
		for (int S = 0; S < (1<<k); S++)
			if (S&(1<<(i-1))) rst[S] += c; 
		for (int j = 1; j <= n; j++) {
			v = read();
			vec.push_back(Node{n+i, j, v, i});
		}
	}
	sort(vec.begin(), vec.end());
	memset(ds, -1, sizeof ds);
	for (Node x : vec) {
		int w = x.w, idx = x.idx;
		for (int S = 0; S < (1<<k); S++) {
			if (idx && !(S&(1<<(idx-1)))) continue;
			int u = find(ds[S], x.u), v = find(ds[S], x.v);
			if (u != v) {
				rst[S] += w;
				if (ds[S][u] > ds[S][v]) swap(u, v);
				ds[S][u] += ds[S][v];
				ds[S][v] = u;
			}
		}
	}
	i64 ans = 1e18;
	for (int S = 0; S < (1<<k); S++) {
		ans = min(ans, rst[S]);
	}
	printf("%lld", ans);
	
	return 0;
}
/*
Expectation: 100 pts
Log: - 读错题了。但好像并不影响，改一点点就行了。 
     - Finished at 15:17.
*/
