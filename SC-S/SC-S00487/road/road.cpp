#include<bits/stdc++.h>
#define ll long long
#define furina puts("QAQ");
using namespace std;
const int maxm = 4e6 + 5;
const int maxn = 1e4 + 55;

int n, m, k;
int cnt;

int tot;
ll sum[1050];
int num[1050];
int pre[1050];

int fa[1050][maxn];
int siz[1050][maxn];

struct Gragh
{
	int u;
	int v;
	ll w;
	
	int col;
}a[maxm];

bool cmp (Gragh x, Gragh y)
{
	return x.w < y.w;
}

int find (int x, int id)
{
	if (fa[id][x] != x)
	{
		return find (fa[id][x], id);
	}
	return fa[id][x];
}

void merge(int x, int y, int id)
{
	x = find (x, id);
	y = find (y, id);
	
	if (siz[id][x] > siz[id][y])
	{
		swap(x, y);
	}
	
	fa[id][x] = y;
	siz[id][y] += siz[id][x];
}

int pop_cnt (int x)
{
	int ret = 0;
	while (x)
	{
		if (x & 1)
		{
			ret++;
		}
		x >>= 1;
	}
	return ret;
}

signed main()
{
//	system("fc road.out road.ans");
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	
	for (int j = 0; j <= (1 << k) - 1; j++)
	{
		pre[j] = n + pop_cnt(j) - 1;
		for (int i = 1; i <= n + k; i++)
		{
			siz[j][i] = 1;
			fa[j][i] = i;
		}
	}	
	
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		ll val;
		
		cin >> u >> v >> val;
		a[++cnt] = Gragh({u, v, val, 0});
	}	
	
	for (int i = 1; i <= k; i++)
	{
		ll val;
		cin >> val;
		
		for (int j = 0; j < (1 << k); j++)
		{
			if (j & (1 << (i - 1)))
			{
				sum[j] += val;
			}
		}
		
		for (int j = 1; j <= n; j++)
		{			
			cin >> val;			
			a[++cnt] = Gragh({j, n + i, val, i});
		}
	}
	
	sort (a + 1, a + cnt + 1, cmp);
	
	for (int i = 1; i <= cnt; i++)
	{
		if (tot == (1 << k)) break;
		
		int u = a[i].u;
		int v = a[i].v;
		ll w = a[i].w;
		int id = a[i].col;		
		
		if (id == 0)
		{
			for (int i = 0; i < (1 << k); i++)
			{
				if (num[i] < pre[i])
				{
					if (find (u, i) != find (v, i))
					{
						merge(u, v, i);
						sum[i] += w;
						num[i]++;	
						
						if (num[i] == pre[i]) tot++;
					}
				}
			}
			continue;
		}
		
		for (int i = 0; i < (1 << k); i++)
		{
			if (i & (1 << (id - 1)) && num[i] < pre[i])
			{
				if (find (u, i) != find (v, i))
				{
					merge(u, v, i);
					sum[i] += w;
					num[i]++;
					
					if (num[i] == pre[i]) tot++;
				}
			}
		}
	}
	
//	cout << (1 << k)  - 1 << ' ' << tot;
	ll ans = sum[0];
	for (int i = 0; i < (1 << k); i++)
	{	
		ans = min (ans, sum[i]);
	}
	
	cout << ans;
	return 0;
}
//图论建模 
//注意开long long 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/