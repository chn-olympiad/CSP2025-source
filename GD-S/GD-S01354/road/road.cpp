#include <bits/stdc++.h>
typedef long long LL;

char buf[1 << 20], *p1 = 0, *p2 = 0; 
#define getchar() ((p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), (p1 == p2))) ? 0 : (*p1++))
int read()
{
	int s = 0; int f = 1, c = getchar();
	for (; !isdigit(c); c = getchar()) f ^= (c == '-');
	for (; isdigit(c); c = getchar()) s = s * 10 + (c ^ 48);
	return f ? s : -s;
}
template<typename T> void write(T x, char end = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static int d[100]; int cur = 0;
	do { d[++cur] = x % 10; } while (x /= 10);
	while (cur) putchar(48 ^ d[cur--]);
	putchar(end);
}
template<typename T> void Fmax(T &x, T y){ if (x < y) x = y; }
template<typename T> void Fmin(T &x, T y){ if (y < x) x = y; }
const int MAXN = 10115, MAXM = 1000005;
int CNT = 0;
struct UFDS
{
	int fa[MAXN], siz[MAXN];
	void init(int n)
	{
		std::iota(fa + 1, fa + n + 1, 1);
		std::fill(siz + 1, siz + n + 1, 1);
	}
	int find(int x){ while (x != fa[x]) x = fa[x] = fa[fa[x]]; return x; }
	bool merge(int x, int y)
	{
//		++CNT;
		x = find(x), y = find(y);
		if (x == y) return false;
		if (siz[x] < siz[y]) std::swap(x, y);
		fa[y] = x, siz[x] += siz[y];
		return true;
	}
} ufds;
int n, m, K;
int val[15];
LL ans = 0;
struct Edge
{
	int u, v, w;
	friend bool operator<(Edge e1, Edge e2){ return e1.w < e2.w; }
} t_e[MAXM], e[MAXN], a[15][MAXN];
void input()
{
	n = read(), m = read(), K = read();
	for (int i = 1; i <= m; i++)
		t_e[i].u = read(), t_e[i].v = read(), t_e[i].w = read();
	for (int i = 1; i <= K; i++)
	{
		val[i] = read();
		for (int j = 1; j <= n; j++) 
			a[i][j].u = i + n, a[i][j].v = j, a[i][j].w = read();
		std::sort(a[i] + 1, a[i] + n + 1);
	}
	std::sort(t_e + 1, t_e + m + 1);
}
void init()
{
	int cur = 0;
	ufds.init(n);
	for (int i = 1; i <= m; i++)
		if (ufds.merge(t_e[i].u, t_e[i].v)) 	
			ans += t_e[i].w, e[++cur] = t_e[i];
//	assert(cur == n - 1);
}
int Ext;
Edge ext[MAXN * 10], tmp[MAXN * 10];
LL dlt;
void add(int id)
{
	dlt += val[id];
	int ctmp = Ext;
	for (int i = 1; i <= Ext; i++)
		tmp[i] = ext[i];
	Ext = 0;
	int i = 1, j = 1;
	while (i <= ctmp && j <= n)
		if (tmp[i].w < a[id][j].w) ext[++Ext] = tmp[i++];
		else ext[++Ext] = a[id][j++];
	while (i <= ctmp) ext[++Ext] = tmp[i++];
	while (j <= n) ext[++Ext] = a[id][j++];
//	assert(Ext <= K * n);
}
void remove(int id)
{
	dlt -= val[id];
	int ctmp = Ext;
	for (int i = 1; i <= Ext; i++) tmp[i] = ext[i];
	Ext = 0;
	for (int i = 1; i <= ctmp; i++)
		if (tmp[i].u != id + n) ext[++Ext] = tmp[i];
//	assert(Ext <= K * n);
}
LL calc()
{
	ufds.init(n + K);
	int j = 1; LL sum = 0;
	for (int i = 1; i < n; i++)
	{
		for (; j <= Ext && ext[j].w <= e[i].w; j++)
			if (ufds.merge(ext[j].u, ext[j].v)) sum += ext[j].w;
//		if (e[i].u > n) printf("!%d %d\n", i, e[i].u); 
//		assert(e[i].u <= n);
		if (ufds.merge(e[i].u, e[i].v)) sum += e[i].w;
	}
//	for (; j <= Ext; j++) if (ufds.merge(ext[j].u, ext[j].v)) sum += ext[j].w;
	return sum;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	input();
	init();
	int lst = 0;
	for (int s = 1; s < (1 << K); s++)
	{
		int cur = (s ^ (s >> 1));
		int p = __builtin_ctz(lst ^ cur);
		if (lst >> p & 1) remove(p + 1);
		else add(p + 1);
//		printf("%d: %d\n", __builtin_popcount(cur) * n, Ext);
		lst = cur;
		Fmin(ans, calc() + dlt);	
	}
	write(ans);
//	fprintf(stderr, "%d\n", CNT);
	return 0;
} 
