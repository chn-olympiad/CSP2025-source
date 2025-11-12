//GZ-S00144 幸进尧 贵阳市云城中学 
#include <bits/stdc++.h>
using namespace std;

int read()
{
	static constexpr int S = 1 << 20;
	static char b[S], *p1, *p2;
	#define gc() (p1 == p2 && (p2 = (p1 = b) + fread(b, 1, S, stdin), p1 == p2) ? EOF : *p1++)
	#define dg(c) (c >= '0' && c <= '9')
	int x = 0, c = gc();
	while (!dg(c)) c = gc();
	while (dg(c)) x = x * 10 + (c & 15), c = gc();
	return x;
	#undef gc
	#undef dg
}

typedef long long LL;
constexpr int N = 1e5 + 5;

LL val[N][3];
int cur[N];
LL dlt[N];

void solve()
{
	int n = read();
	LL res = 0; int cnt[3] = {0, 0, 0};
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j < 3; j ++)
			val[i][j] = read();
		if (val[i][0] >= max(val[i][1], val[i][2]))
			res += val[i][0], ++cnt[0], cur[i] = 0;
		else if (val[i][1] >= val[i][2])
			res += val[i][1], ++cnt[1], cur[i] = 1;
		else res += val[i][2], ++cnt[2], cur[i] = 2;
	}
	
	int t = -1, m = 0;
	if (cnt[0] > n / 2) t = 0;
	if (cnt[1] > n / 2) t = 1;
	if (cnt[2] > n / 2) t = 2;
	if (t == -1) return (void)printf("%lld\n", res);
	for (int i = 1; i <= n; i ++)
		if (cur[i] == t)
		{
			int v = max(val[i][(t + 1) % 3], val[i][(t + 2) % 3]);
			dlt[++m] = v - val[i][t];
		}
	sort(dlt + 1, dlt + m + 1);
	for (int i = n / 2 + 1; i <= m; i ++) res += dlt[i];
	printf("%lld\n", res);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T = read();
	while (T --) solve();
	
	return 0;
}
