#include <bits/stdc++.h>
using namespace std;
long long read()
{
	long long wbh = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		wbh = (wbh << 3) + (wbh << 1) + ch - '0';
		ch = getchar();
	}
	return wbh;
}
const long long N = 100005;
long long T, n, a[N][5], maxn1[N], maxn2[N], p, ans, sum, maxn, x;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T = read();
	while(T--)
	{
		n = read();
		for (long long i = 1; i <= n; i++)
			for (long long j = 1; j <= 3; j++)
				a[i][j] = read();
		priority_queue <long long> f[5];
		ans = sum = 0;
		for (long long i = 1; i <= n; i++)
		{
			maxn1[i] = maxn2[i] = -1;
			p = 0;
			for (long long j = 1; j <= 3; j++)
			{
				if (a[i][j] > maxn1[i])
				{
					maxn2[i] = maxn1[i];
					maxn1[i] = a[i][j];
					p = j;
				}
				else if (a[i][j] > maxn2[i])
					maxn2[i] = a[i][j];
			}
			ans += maxn1[i];
			f[p].push(maxn2[i] - maxn1[i]);
		}
		maxn = max(f[1].size(), max(f[2].size(), f[3].size()));
		if (maxn <= n / 2)
		{
			printf("%lld\n", ans);
			continue;
		}
		if (f[1].size() == maxn)
			x = 1;
		else if (f[2].size() == maxn)
			x = 2;
		else if (f[3].size() == maxn)
			x = 3;
		while(maxn > n / 2)
		{
			maxn--;
			ans += f[x].top();
			f[x].pop();
		}
		printf("%lld\n", ans);
	}
}
