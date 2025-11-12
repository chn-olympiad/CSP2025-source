#include <cstdio>
#include <algorithm>
inline void read(int &x)
{
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	for (; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + (c & 15);
}
const int V = 10003, mod = 998244353;
inline int M(int x) { return x >= mod ? x - mod : (x < 0 ? x + mod : x); }
int n, ans, a[5007], f[V + 4], pf[V + 4];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	std::sort(a + 1, a + n + 1);
	f[0] = 1;
	for (int i = 0; i <= V; ++i)
		pf[i] = 1;
	for (int i = 1, p2i1 = 1; i <= n; ++i, p2i1 = M(p2i1 << 1))
	{
		ans = M(ans + p2i1 - pf[a[i]]);
		for (int j = V; j >= a[i]; --j)
			f[j] = M(f[j] + f[j - a[i]]);
//		for (int j = 1; j <= 15; ++j)
//			printf("%d ", f[j]);
//		printf("ans = %d\n", ans);
		for (int j = 1; j <= V; ++j)
			pf[j] = M(pf[j - 1] + f[j]);
	}
	printf("%d", ans);
	fclose(stdin), fclose(stdout);
	return 0;
}