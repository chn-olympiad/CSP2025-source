#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e06 * 5 + 7, N = 1e04 + 7;

int n, m, k;

int Father[MAXN];

ll c[17], nw[17][N];

ll cnt[17];

bool vis[MAXN];

ll ans;

struct Edge {
	int x, y, bz;
	ll w;
} a[MAXN], b[MAXN];

bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}

int Find(int x)
{
	if(Father[x] == x)
		return x;
	return Father[x] = Find(Father[x]);
}

int read()
{
	char ch = getchar();
	while(ch < '0' or ch > '9')
		ch = getchar();
	int x = 0;
	while(ch >= '0' and ch <= '9')
		x = x * 10 + (ch - '0'), ch = getchar();
	return x;
}

ll rd()
{
	char ch = getchar();
	while(ch < '0' or ch > '9')
		ch = getchar();
	ll x = 0;
	while(ch >= '0' and ch <= '9')
		x = x * 10 + (ch - '0'), ch = getchar();
	return x;
}

void dfs(int x)
{
	if(x > k)
	{
		int p = m, o = 0;
		ll res = 0;
		for(int i = 1; i <= p; i++)
			a[i] = b[i];
		for(int i = 1; i <= k; i++)
		{
			if(cnt[i])
			{
				res += c[i];
				++o;
				for(int j = 1; j <= n; j++)
				{
					Edge l;
					l.x = o + n, l.y = j, l.w = nw[i][j];
					a[++p] = l;
				}
			}
		}
		sort(a + 1, a + p + 1, cmp);
		for(int i = 1; i <= n + o; i++)
			Father[i] = i;
		int tot = 0;
		for(int i = 1; i <= p; i++)
		{
			int fx = Find(a[i].x), fy = Find(a[i].y);
			if(fx == fy)
				continue;
			res += a[i].w;
			++tot;
			Father[fx] = fy;
			if(tot == n + o - 1)
				break;
		}
		ans = min(ans, res);
		return ;
	}
	cnt[x] = 1;
	dfs(x + 1);
	cnt[x] = 0;
	dfs(x + 1);
	return ;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	n = read(), m = read(), k = read();
	
	for(int i = 1; i <= m; i++)
		a[i].x = read(), a[i].y = read(), a[i].w = rd(), a[i].bz = 0, b[i] = a[i];
	
	if(!k)
	{
		sort(a + 1, a + m + 1, cmp);
		int tot = 0;
		for(int i = 1; i <= n; i++)
			Father[i] = i;
		for(int i = 1; i <= m; i++)
		{
			int fx = Find(a[i].x), fy = Find(a[i].y);
			if(fx == fy)
				continue;
			ans += a[i].w;
			++tot;
			Father[fx] = fy;
			if(tot == n - 1)
				break;
		}
		printf("%lld\n", ans);
		return 0;
	}
	
	if(k <= 5 and n <= 1000 and m <= 100000)
	{
		ans = 1e18;
		for(int i = 1; i <= k; i++)
		{
			c[i] = rd();
			for(int j = 1; j <= n; j++)
			{
				nw[i][j] = rd();
			}
		}
		dfs(1);
		printf("%lld\n", ans);
		return 0;
	}
	
	for(int i = 1; i <= k; i++)
	{
		c[i] = rd();
		for(int j = 1; j <= n; j++)
		{
			nw[i][j] = rd();
			Edge l;
			l.x = i + n, l.y = j, l.w = nw[i][j] + c[i], l.bz = 1;
			a[++m] = l;
		}
	}

	sort(a + 1, a + m + 1, cmp);
	
//	for(int i = 1; i <= m; i++)
//		cout << a[i].x << " " << a[i].y << " " << a[i].w << "\n";

	for(int i = 1; i <= n + k; i++)
		Father[i] = i;
		
	int now = 0, tot = 0;
	
//	for(int i = 1; i <= m; i++)
//	{
//			cout << a[i].x << " " << a[i].y << " " << a[i].w << " " << a[i].bz<< "\n";
//	}
		
	for(int i = 1; i <= m; i++)
	{
		int fx = Find(a[i].x), fy = Find(a[i].y);
		if(fx == fy)
			continue;
		if(a[i].bz)
		{
			int nd = max(a[i].x, a[i].y);
			++cnt[nd - n]; 
		}
		if(a[i].bz)
		{
			if(!vis[max(a[i].x, a[i].y)])
				++now, vis[max(a[i].x, a[i].y)] = 1;
		}
		ans += a[i].w;
		Father[fx] = fy;
		++tot;
		if(tot == n + now - 1)
			break;
	}
	
	ll sum = 0;

	for(int i = 1; i <= k; i++)
	{
		if(cnt[i])
			sum = sum + (cnt[i] - 1) * c[i];
	}
	printf("%lld", ans - sum);
	
	
	return 0;
}
