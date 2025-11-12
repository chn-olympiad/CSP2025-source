#include <cstdio>
inline void read(int &x)
{
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	for (; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + (c & 15);
}
const int MAXN = 5e5 + 7;
int n, m, a[MAXN], pp[MAXN], lst[(1 << 20) | 7], f[MAXN], pf[MAXN];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i < ((1 << 20) | 7); ++i)
		lst[i] = -1;
	for (int i = 1; i <= n; ++i)
		read(a[i]), a[i] ^= a[i - 1], pp[i] = lst[a[i] ^ m], lst[a[i]] = i;
	for (int i = 1; i <= n; ++i)
		(~pp[i]) && (f[i] = pf[pp[i]] + 1), pf[i] = f[i] > pf[i - 1] ? f[i] : pf[i - 1];
	printf("%d", pf[n]);
	fclose(stdin), fclose(stdout);
	return 0;
}