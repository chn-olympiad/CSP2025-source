#include <bits/stdc++.h>

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
const int MAXN = 100005;
int n, a[MAXN][3], opt[MAXN];
void mian()
{
	n = read();
	for (int i = 1; i <= n; i++)
		a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
	int sum = 0, cnt[3] = {0, 0, 0};
	for (int i = 1; i <= n; i++)
	{
		int v = std::max({a[i][0], a[i][1], a[i][2]});
		for (opt[i] = 0; v > a[i][opt[i]]; opt[i]++);
		sum += v, cnt[opt[i]]++;
	}
	int o = 0;
	while (o < 3 && cnt[o] <= n / 2) o++;
	if (o < 3)
	{
		static int dif[MAXN];
		int m = 0;
		for (int i = 1; i <= n; i++) if (opt[i] == o)
		{
			int v = 0;
			for (int j = 0; j < 3; j++)
				if (j != o) Fmax(v, a[i][j]);
			dif[++m] = a[i][o] - v;
		}
		std::sort(dif + 1, dif + m + 1);
		for (int i = 1; i <= cnt[o] - n / 2; i++)
			sum -= dif[i];
	}
	write(sum);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (int Tcnt = read(); Tcnt--; ) mian();
	return 0;
} 
