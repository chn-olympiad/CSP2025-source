// GZ-S00205 盘州市第二中学 曹立桐 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
const int N = 1e6 + 100;
const LL LNF = 1e18;

int n, m, k;
bool st[N];
int p[N];

struct node
{
	int a, b, c, w;
	
	bool operator <(const node &W) const
	{
		return c < W.c;
	}
}g[N], bg[N];

int find(int x)
{
	if(p[x] == x) return p[x];
	return p[x] = find(p[x]);
}

LL krusal(int n)
{
	for(int i = 1; i <= n; i ++) p[i] = i;
	sort(bg + 1, bg + 1 + n);
	
	LL res = 0;
	for(int i = 1; i <= n; i ++)
	{
		int a = bg[i].a, b = bg[i].b;
		a = find(a), b = find(b);
		if(a != b)
		{
			p[a] = b;
			res += bg[i].c;
		}
	}
	
	return res;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	
	for(int i = 1; i <= m; i ++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[i] = {a, b, c, 0};
		bg[i] = {a, b, c, 0};
	}
	
	for(int i = 1; i <= k; i ++)
	{
		int cost;
		scanf("%d", &cost);
		int id = n + i;
		for(int j = 1; j <= n; j ++)
		{
			int c;
			scanf("%d", &c);
			g[m + (i - 1) * n + j] = {id, j, c, cost};
		}
	}
	
	LL ans = 1e18;
	
	// 二进制枚举
	for(int i = 0; i < (1 << k); i ++)
	{
		int cntm = m;
		int cost2 = 0;
		for(int j = 0; j <= k; j ++)
		{
			if((i >> j) & 1)
			{
				for(int z = m + j * n + 1; z <= m + (j + 1) * n; z ++)
				{
					bg[++ cntm] = g[z];
				}
				cost2 += g[m + j * n + 1].w;
			}
		}
		
		ans = min(ans, krusal(cntm) + cost2);
	}
	
	printf("%lld", ans);
	
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
