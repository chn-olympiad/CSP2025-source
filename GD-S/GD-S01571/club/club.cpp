#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e05 + 7;

int T, n;

#define int long long

int ca, cb, cc;

int d[MAXN];

struct Node {
	int x, id;
} a[MAXN], b[MAXN], c[MAXN];

int p[MAXN];

bool cmp(int a, int b)
{
	return a > b;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d", &n);
		memset(d, 0, sizeof d);
		ca = cb = cc = 0;
		for(int i = 1; i <= n; i++)
			scanf("%lld%lld%lld", &a[i].x, &b[i].x, &c[i].x), a[i].id = i, b[i].id = i, c[i].id = i;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i].x >= b[i].x and a[i].x >= c[i].x)
				d[i] = 1, ca++, ans += a[i].x;
			else if(b[i].x >= a[i].x and b[i].x >= c[i].x)
				d[i] = 2, ++cb, ans += b[i].x;
			else if(c[i].x >= a[i].x and c[i].x >= b[i].x)
				d[i] = 3, ++cc, ans += c[i].x;
		}
		if(ca <= n / 2 and cb <= n / 2 and cc <= n / 2)
		{
			printf("%lld\n", ans);
			continue;
		}
		if(ca > n / 2)
		{
			int cnt = 0;
			for(int i = 1; i <= n; i++)
			{
				if(d[i] == 1)
					p[++cnt] = -a[i].x + b[i].x, p[cnt] = max(p[cnt], -a[i].x + c[i].x); 
			}
			sort(p + 1, p + ca + 1, cmp);
			int now = ca;
			for(int i = 1; i <= ca; i++)
			{
				ans += p[i];
				--now;
				if(now == n / 2)
					break;
			}
		}
		else if(cb > n / 2)
		{
			int cnt = 0;
			for(int i = 1; i <= n; i++)
			{
				if(d[i] == 2)
					p[++cnt] = -b[i].x + a[i].x, p[cnt] = max(p[cnt], -b[i].x + c[i].x); 
			}
			sort(p + 1, p + cb + 1, cmp);
			int now = cb;
			for(int i = 1; i <= cb; i++)
			{
				ans += p[i];
				--now;
				if(now == n / 2)
					break;
			}
		}
		else if(cc > n / 2)
		{
			int cnt = 0;
			for(int i = 1; i <= n; i++)
			{
				if(d[i] == 3)
					p[++cnt] = -c[i].x + b[i].x, p[cnt] = max(p[cnt], -c[i].x + a[i].x); 
			}
			sort(p + 1, p + cc + 1, cmp);
			int now = cc;
			for(int i = 1; i <= cc; i++)
			{
				ans += p[i];
				--now;
				if(now == n / 2)
					break;
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
/*
QwQ
T_T
*/
