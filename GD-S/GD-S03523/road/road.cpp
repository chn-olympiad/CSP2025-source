#include <bits/stdc++.h>
using namespace std;
const int N = 10024, T = 32768, E = 1000240 * 2, K = 10 + 2, I = -1u >> 1;
struct Edge
{
	int u, v, w;
	Edge() {}
	Edge(int U, int V, int W) : u(U), v(V), w(W) {}
} e[N], ep[N];

int n, m, k;
class SegTree
{
public:
	int a[N], x[T], K;
#define lc (d << 1)
#define rc (lc | 1)
	inline void Getup(int d)
	{
		x[d] = a[x[lc]] < a[x[rc]] ? x[lc] : x[rc];
	}

public:
	inline void Init(int n)
	{
		for (K = 1; K < n; K <<= 1)
			;
		--K;
		for (int i = 0; i <= n; ++i)
			a[i] = I;
		for (int i = 1; i <= n; ++i)
			x[i + K] = i;
		for (int d = K; d > 0; --d)
			Getup(d);
//		for (int i = 1; i <= (k * 2 - 1); ++i)
//		{
//			int j = 0;
//			cerr << x[i] << ' ';
//			if ((1 << j) < i)
//				++j, cerr << '\n';
//		}
	}
	inline void Change(int d, int v)
	{
		a[d] = v;
		d += K;
		for (d >>= 1; d > 0; d >>= 1)
			Getup(d);
	}
	inline int Query()
	{
		return x[1];
	}
} QwQ;

int h[N], nxt[E], to[E], w[E], tt;
inline void AE(int x, int y, int z)
{
	nxt[++tt] = h[x];
	to[h[x] = tt] = y;
	w[tt] = z;
}
bool b[N];
int c[N], a[K][N];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k; 
	for (int i = 1; i <= m; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		AE(x, y, z);
		AE(y, x, z);
	}
	QwQ.Init(n);
	QwQ.Change(1, 0);
	for (int i = 1; i <= n; ++i)
		ep[i] = Edge(i, i, I);
	for (int i = 1; i <= n; ++i)
	{
		int x = QwQ.Query();
//		cerr << "// " << x << '\n';
		e[i] = ep[x];
		QwQ.Change(x, I);
		b[x] = true;
		for (int j = h[x]; j != 0; j = nxt[j])
		{
			int y = to[j], z = w[j];
			if (b[y])
				continue;
			if (QwQ.a[y] > z)
			{
				ep[y] = Edge(x, y, z);
				QwQ.Change(y, z);
			}
		}
//		for (int j = 1; j <= n; ++j)
//			cerr << i << " ?? " << ep[j].u << ' ' << ep[j].v << ' ' << ep[j].w << '\n';
	}
//	for (int i = 1; i <= n; ++i)
//		cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << '\n';
	fill(h + 1, h + n + 1, 0);
	tt = 0;
	for (int i = 2; i <= n; ++i)
	{
		int x = e[i].u, y = e[i].v, z = e[i].w;
		AE(x, y, z);
		AE(y, x, z);
	}

	for (int j = 1; j <= k; ++j)
	{
		cin >> c[j];
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[j][i];
			AE(n + j, i, a[j][i]);
			AE(i, n + j, a[j][i]);
		}
	}

	long long s = -1llu >> 2, t;
	for (int Bn = 0; Bn < (1 << k); ++Bn)
	{
		t = 0;
		int cnt = 0;
		fill(b + 1, b + n + k + 1, false);
		for (int j = 1; j <= k; ++j)
			if (((Bn >> (j - 1)) & 1) == 0)
				b[n + j] = true;
			else
				t += c[j], ++cnt;
		QwQ.Init(n + k);
		QwQ.Change(1, 0);
		for (int i = 1; i <= n + cnt; ++i)
		{
			int x = QwQ.Query();
			t += QwQ.a[x];
			QwQ.Change(x, I);
			b[x] = true;
			for (int j = h[x]; j != 0; j = nxt[j])
			{
				int y = to[j], z = w[j];
				if (b[y])
					continue;
				if (QwQ.a[y] > z)
					QwQ.Change(y, z);
			}
		}
		s = min(s, t);
	}
	cout << s;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
