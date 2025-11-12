#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 10010, M = 1000010;

int p[N];
int n, m, k;
int edges_cnt;
LL extend[17][N];
struct Edge
{
	LL a, b, w;
	bool operator<(const Edge &T) const
	{
		return w < T.w;
	}
} edges[M];

inline int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

inline LL get_weight()
{
	sort(edges + 1, edges + 1 + edges_cnt);
	
	LL res = 0, cnt = 0;
	for (int i = 1; i <= edges_cnt; ++ i )
	{
		LL a = edges[i].a, b = edges[i].b, w = edges[i].w;
		
		a = find(a), b = find(b);
		if (a != b)
		{
			p[a] = b;
			res += w;
//			printf("%d ", w);
			cnt ++ ;
		}
	}
//	printf("\n");
	return res;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++ i )
		scanf("%lld%lld%lld", &edges[i].a, &edges[i].b, &edges[i].w);
	for (int i = 1; i <= k; ++ i )
		for (int j = 1; j <= n + 1; ++ j )
			scanf("%lld", &extend[i][j]);
	
	LL res = 1e18;
	for (int mask = 0; mask < (1 << k); ++ mask )
	{
		edges_cnt = m;
		
		LL cur_res = 0;
		for (int i = 1; i <= k; ++ i )
			if ((mask >> (i - 1)) & 1)
			{
				cur_res += extend[i][1];
//				printf("mask = %d, %d\n", mask, extend[i][1]);
				for (int j = 1; j <= n; ++ j )
					edges[ ++ edges_cnt ] = { i + n, j, extend[i][j + 1] };
			}
		
		for (int i = 1; i <= n + k; ++ i )
			p[i] = i;
		
		cur_res += get_weight();
		
		res = min(res, cur_res);
//		printf("%d: %d\n", mask, cur_res);
	}
	
	printf("%lld\n", res);
	return 0;
}
