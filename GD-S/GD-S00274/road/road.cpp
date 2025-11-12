#include <bits/stdc++.h>
using namespace std;

#define FIONAME "road"
struct Edg {
	int u, v;
	long long w;
	Edg (int _u = 0, int _v = 0, long long _w = 0): u (_u), v (_v), w (_w) {}
	bool operator< (const Edg& z) const {
		return w > z.w;
	}
} e[1848576];
int c[16];
int a[16][1048576];

namespace Subtask1234A {
	int fa[16384];
	int vused[16];
	long long wt[16];
	int Fd (int u) {
		return (fa[u] == u) ? (u) : (fa[u] = Fd (fa[u]));
	}
	int qry (int u, int v) {
		return Fd (u) == Fd (v);
	}
	int mrg (int u, int v) {
		if (qry (u, v)) return 0;
		fa[Fd (v)] = Fd (u);
		return 1;
	}
	int solve (int n, int m) {
		sort (e + 1, e + 1 + m, [] (const Edg & x, const Edg & y) {
			return x.w < y.w;
		});
		for (int i = 1; i <= n; ++i) {
			fa[i] = i;
		}
		long long ans = 0;
		for (int i = 1; i <= m; ++i) {
			int u = e[i].u, v = e[i].v;
			long long w = e[i].w;
			if (qry (u, v)) continue;
			mrg (u, v);
			ans += w;
		}
		printf ("%lld", ans);
		return 0;
	}
	int solve2 (int n, int m, int k) {
		for (int i = 1; i <= n; ++i) {
			fa[i] = i;
		}
		for (int i = n + 1, j = 1; j <= k; ++i, ++j) {
			fa[i] = i;
		}
		int etot = m;
		for (int j = 1; j <= k; ++j) {
			for (int i = 1; i <= n; ++i) {
				e[++etot] = Edg (j + n, i, a[j][i]);
			}
		}
		sort (e + 1, e + 1 + etot, [] (const Edg & x, const Edg & y) {
			return x.w < y.w;
		});
		long long ans = 0;
		for (int i = 1; i <= etot; ++i) {
			int u = e[i].u, v = e[i].v;
			long long w = e[i].w;
			if (qry (u, v)) continue;
			if (u > n) {
				//	virtual node
				int j = u - n;
				++vused[j];
				wt[j] = w;
			}
			mrg (u, v);
			ans += w;
		}
		//	clear
		for (int j = 1, i = n + 1; j <= k; ++i, ++j) {
			if (vused[j] == 1) {
				ans -= wt[j];
			}
		}
		printf ("%lld", ans);
		return 0;
	}
}
namespace curr {

	int c[16];
	struct NewEdg {
		int v;
		long long w;
		NewEdg (int _v = 0, long long _w = 0): v (_v), w (_w)  {}
		bool operator< (const NewEdg& z) const {
			return w > z.w;
		}
	};
	int fa[16384];
	int vused[16];
	long long wt[16];
	int Fd (int u) {
		return (fa[u] == u) ? (u) : (fa[u] = Fd (fa[u]));
	}
	int qry (int u, int v) {
		return Fd (u) == Fd (v);
	}
	int mrg (int u, int v) {
		if (qry (u, v)) return 0;
		fa[Fd (v)] = Fd (u);
		return 1;
	}
//	Memory Analysis
	priority_queue<Edg> Q;
	priority_queue<NewEdg> A[16];
	int main (int n, int m, int k) {
		for (int i = 1; i <= m; ++i) {
			Q.push (Edg (e[i].u, e[i].v, e[i].w));
		}

		for (int j = 1; j <= k; ++j) {
			for (int i = 1; i <= n; ++i) {
				A[j].push (NewEdg (i, a[j][i]));
			}
			NewEdg tp = A[j].top ();
			A[j].pop ();
			Q.push (Edg (j + n, tp.v, tp.w + 0ll + c[j]));
		}
		for (int i = n + k; i; --i) {
			fa[i] = i;
		}
		long long ans = 0;
		while (Q.size ()) {
			Edg tp = Q.top ();
			Q.pop ();
			int u = tp.u, v = tp.v;
			long long w = tp.w;
			if (qry (u, v)) {
				if (u > n) {
					int j = u - n;
					if (A[j].empty ()) continue;
					NewEdg tp2 = A[j].top ();
					A[j].pop ();
					Q.push (Edg (u, tp2.v, tp2.w + 0ll + (vused[j] ? 0 : c[j])));
				}
				continue;
			}
			mrg (u, v);
			if (u > n) {
				int j = u - n;
				++ vused[j];
				wt[j] = w;
				if (A[j].size ()) {
					NewEdg tp2 = A[j].top ();
					A[j].pop ();
					Q.push (Edg (u, tp2.v, tp2.w));
				}
			}
			ans += w;
		}

		for (int j = 1, i = n + 1; j <= k; ++i, ++j) {
			if (vused[j] == 1) {
				ans -= wt[j];
			}
		}
		printf ("%lld", ans);
		return 0;
	}
}
int main (void) {
	freopen (FIONAME ".in", "r", stdin);
	freopen (FIONAME ".out", "w", stdout);
	int n, m, k;
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
	}
	if (k == 0) {
		return Subtask1234A::solve (n, m);
	}
	//	hint: special constraits A eg3
	int flga = 0;
	for (int j = 1; j <= k; ++j) {
		scanf ("%d", c + j);
		flga += (c[j] == 0);
		for (int i = 1; i <= n; ++i) {
			scanf ("%d", &a[j][i]);
		}
	}
	if (flga == k) {
		return Subtask1234A::solve2 (n, m, k);
	}
	return curr::main (n, m, k);
}

/*
patch

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
