#include <bits/stdc++.h>
#define ll long long
#define fi  first
#define se second
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while('0' > ch || ch > '9')
	{
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
	return s * w;
}
int n, m, k;
struct node
{
	int u, v, w;
}e[M + M], EEE[M + M];
int etot, ntot;
bool cmp(node a, node b)
{
	return a.w < b.w;
}
int fa[N + 20], c[12], a[12][N];
int find(int x)
{
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
void work()
{
	for(int i = 1; i <= n + k; i++) fa[i] = i;
	for(int j = 1; j <= k; j++) for(int i = 1; i <= n; i++) e[++etot] = {i, n + j, a[j][i]};
	stable_sort(e + 1, e + etot + 1, cmp);
	int cc = 0;
	ll now = 0;
	ntot = n + k;
	for(int i = 1; i <= etot; i++)
	{
		int fx = find(e[i].u), fy = find(e[i].v);
		if(fx == fy) continue;
		if(cc == ntot - 1) break;
		fa[fx] = fy;
		now += e[i].w, cc++;
	}
//	cout << ans << endl;
//	ll aaa = 0;
//	for(int i = 1; i <= k; i++) aaa += c[i];
//	cout << aaa << endl;
	printf("%lld\n", now);
	exit(0);
}
int TOT;
void solve()
{
	ll ans = 1e18;
	for(int j = 0; j <= (1 << k) - 1; j++)
	{
		ll now = 0;
		etot = n - 1;
		for(int i = 1; i <= n + k; i++) fa[i] = i;
		for(int i = 1; i <= n - 1; i++) e[i] = EEE[i];
		for(int p = 1; p <= k; p++)
		{
			if(j & (1 << (p - 1)))
			{
				for(int i = 1; i <= n; i++) e[++etot] = {i, n + p, a[p][i]};
				now += c[p];
//				cout << p << " ";
			}
		}
//		puts("");
		stable_sort(e + 1, e + etot + 1, cmp);
		int cc = 0;
		for(register int i = 1; i <= etot; i++)
		{
			int fx = find(e[i].u), fy = find(e[i].v);
			if(fx == fy) continue;
			fa[fx] = fy;
			now += e[i].w;
			cc++;
//			if(cc == ntot - 1) break;
		}
//		cout << ntot << " " << etot << " " << lm << " " << etot << endl;
		if(now <= ans) ans = now;
	}
	printf("%lld\n", ans);
	exit(0);
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++) e[i] = {read(), read(), read()};
	etot = m, ntot = n;
	bool fl = 1;
	for(int i = 1; i <= k; i++)
	{
		c[i] = read();
		fl &= (c[i] == 0);
		for(int j = 1; j <= n; j++) a[i][j] = read();
	}
	if(fl) work();
	sort(e + 1, e + etot + 1, cmp);
	for(int i = 1; i <= ntot; i++) fa[i] = i;
	ll ans = 0;
	for(int i = 1; i <= etot; i++)
	{
		int fx = find(e[i].u), fy = find(e[i].v);
		if(fx == fy) continue;
		EEE[++TOT] = e[i];
		fa[fx] = fy;
		ans += e[i].w;
//		cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
	}
	solve();
//	ll lst = 0, lm = etot;
////	cout << ans << endl;
//	for(int j = 1; j <= k; j++)
//	{
//		ll now = 0;
//		lm = etot;
//		for(int i = 1; i <= n + k; i++) fa[i] = i;
//		for(int i = 1; i <= etot; i++) e[i] = EEE[i];
//		for(int i = 1; i <= n; i++) e[++etot] = {i, n + j, a[j][i]};
//		stable_sort(e + 1, e + etot + 1, cmp);
////		int cc = 0;
//		for(int i = 1; i <= etot; i++)
//		{
//			int fx = find(e[i].u), fy = find(e[i].v);
//			if(fx == fy) continue;
////			if(cc == ntot) break;
//			fa[fx] = fy;
//			now += e[i].w;
//		}
////		cout << ntot << " " << etot << " " << lm << " " << etot << endl;
//		now += (lst + c[j]);
//		if(now <= ans) ans = now, lst += c[j];
//		else etot = lm;
////		cout << ans << " " << lst << " " << etot << endl;
//	}
//	printf("%lld\n", ans);
	return 0;
}
/*
4 4 3
1 4 6
2 3 7
4 2 5
4 3 4
0 0 8 2 4
0 0 1 1 1
0 0 3 2 4
qwq48

!!!!!!!!!!!!! passssssssed!

freeopen freeopen freeopen freeopen freeopen freeopen freeopen freeopen freeopen 
*/
