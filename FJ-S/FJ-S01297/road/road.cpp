#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e4 + 10, M = 1e6 + 10, T = (1 << 10) + 10;

struct node
{
	int a, b, c, op;
	
	bool operator < (const node &W) {return c < W.c;}
}e[M], te[M];
int c[15], f[N + 10];
bool ok[15];

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9')
	{
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

int find(int x)
{
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}

void solve()
{
	int n = read(), m = read(), K = read();
	for (int i = 1; i <= m; i ++ ) e[i].a = read(), e[i].b = read(), e[i].c = read();
	sort(e + 1, e + 1 + m);
	int cnt = 0; LL res = 0;
	for (int i = 1; i <= n + K; i ++ ) f[i] = i;
	for (int i = 1; i <= m; i ++ )
	{
		int fa = find(e[i].a), fb = find(e[i].b);
		if (fa != fb)
		{
			f[fa] = fb, te[ ++ cnt] = e[i], te[cnt].op = K, res += e[i].c;
			if (cnt == n - 1) break;
		}
	}
	for (int i = 0; i < K; i ++ )
	{
		c[i] = read();
		for (int j = 1; j <= n; j ++ ) te[ ++ cnt] = {n + i + 1, j, read(), i};
	}
	sort(te + 1, te + 1 + cnt); ok[K] = true;
	for (int s = 1; s < (1 << K); s ++ )
	{
		int cc = 0, cnt1 = 0, mx; LL sum = 0; bool flag = true;
		for (int i = 0; i < K; i ++ ) ok[i] = false;
		for (int i = 0; i < K; i ++ )
		{
			if (!((s >> i) & 1)) continue;
			cnt1 ++ , ok[i] = true, sum += c[i];
			if (sum >= res) {flag = false; break;}
		}
		if (!flag) continue;
		for (int i = 1; i <= n + K; i ++ ) f[i] = i;
		for (int i = 1; i <= cnt; i ++ )
		{
			if (!ok[te[i].op]) continue;
			int fa = find(te[i].a), fb = find(te[i].b);
			if (fa != fb)
			{
				f[fa] = fb, cc ++ , sum += te[i].c;
				if (sum >= res || cc == n + cnt1 - 1) break;
			}
		}
		res = min(res, sum);
	}
	printf("%lld\n", res);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int T = 1;
	while (T -- ) solve();
	return 0;
}
