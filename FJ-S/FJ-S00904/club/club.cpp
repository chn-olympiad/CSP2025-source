#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T;
struct Satisfy
{
	int id, val;
}a[N], b[N], c[N];
int n, st[N];
int f[50][50][50][50], cnt[3], lim;
int g[210][110][110];
bool vis[N];
bool cmp(Satisfy x, Satisfy y)
{
	return x.val > y.val;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T --)
	{
		int flag1 = 0, flag2 = 0;
		scanf("%d", &n);
		lim = n / 2;
		for(int i = 1;i <= n;i ++)
		{
			a[i].id = b[i].id = c[i].id = i;
			scanf("%d%d%d", &a[i].val, &b[i].val, &c[i].val);
			if(b[i].val == 0 && c[i].val == 0) flag1 ++;
			if(c[i].val == 0) flag2 ++;
		}
		if(flag1 == n)
		{
			int ans = 0;
			sort(a + 1, a + n + 1, cmp);
			for(int i = 1;i <= lim;i ++)
				ans += a[i].val;
			cout << ans << endl;
		}
		else if(flag2 == n)
		{
			memset(g, 0, sizeof g);
			for(int i = 1;i <= n;i ++)
			{
				for(int j = 0;j <= lim;j ++)
					for(int k = 0;k <= lim;k ++)
						{
							if(j >= 1) g[i][j][k] = max(g[i][j][k], g[i - 1][j - 1][k] + a[i].val);
							if(k >= 1) g[i][j][k] = max(g[i][j][k], g[i - 1][j][k - 1] + b[i].val);
						}
			}
			cout << g[n][lim][lim] << endl;
		}
		else
		{
			memset(f, 0, sizeof f);
			for(int i = 1;i <= n;i ++)
			{
				for(int j = 0;j <= lim;j ++)
					for(int k = 0;k <= lim;k ++)
						for(int u = 0;u <= lim;u ++)
						{
							if(j >= 1) f[i][j][k][u] = max(f[i][j][k][u], f[i - 1][j - 1][k][u] + a[i].val);
							if(k >= 1) f[i][j][k][u] = max(f[i][j][k][u], f[i - 1][j][k - 1][u] + b[i].val);
							if(u >= 1) f[i][j][k][u] = max(f[i][j][k][u], f[i - 1][j][k][u - 1] + c[i].val);
						}
			}
			cout << f[n][lim][lim][lim] << endl;
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
