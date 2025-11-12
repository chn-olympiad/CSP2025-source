#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

#define int long long

using namespace std ;
struct Edge
{
	int u, v, w ;
	bool operator<(const Edge& r)const
	{
		return w < r.w ;
	}
} ;

struct Edge2
{
	int u, v, w, id ;
	bool operator<(const Edge& r)const
	{
		return w < r.w ;
	}
} ;

const int N = 1e4 + 5, N2 = 2 * N, M = 1e6 + 5, K = 1e1 + 5 ;

int n, m, k, res, a[K][N] ;

int fa[N + K] ;
Edge ed[M] ;

int idx ;

vector<Edge> nwE ;

int find(int x)
{
	if (fa[x] == x) return x ;
	return fa[x] = find(fa[x]) ;
}
inline void merge(int x, int y)
{
	fa[find(x)] = fa[find(y)] ;
}
int kruskal1()
{
	int sum = 0 ;
	sort(ed + 1, ed + m + 1) ;
	for (int i = 0 ; i < N ; i ++ ) fa[i] = i ;
	
	for (int i = 1 ; i <= m ; i ++ )
	{
		if (find(ed[i].u) != find(ed[i].v))
			merge(ed[i].u, ed[i].v), sum += ed[i].w ;
	}
	return sum ;
}

int kruskal2()
{
	int sum = 0 ;
	sort(nwE.begin(), nwE.end()) ;
	for (int i = 0 ; i < N + K ; i ++ ) fa[i] = i ;
	
	for (int i = 0, Len = nwE.size() ; i < Len ; i ++ )
	{
		if (find(nwE[i].u) != find(nwE[i].v))
			merge(nwE[i].u, nwE[i].v), sum += nwE[i].w ;
	}
	return sum ;
}

signed main()
{
	freopen("road.in", "r", stdin) ;
	freopen("road.out", "w", stdout) ;
	ios::sync_with_stdio(false) ;
	
	cin >> n >> m >> k ;
	for (int i = 1 ; i <= m ; i ++ )
	{
		cin >> ed[i].u >> ed[i].v >> ed[i].w ;
		if (ed[i].u > ed[i].v)
			swap(ed[i].u, ed[i].v) ;
	}
	
	int losum = kruskal1() ;
	if (k == 0)
	{
		cout << losum << '\n' ;
		return 0 ;
	}
	for (int i = 1, x ; i <= k ; i ++ )
	{
		cin >> x ;
		if (x > losum) // joker
		{
			k -- , i --  ;
			for (int j = 1, useless ; j <= n ; j ++ )
				cin >> useless ;
			continue ;
		}
		
		a[i][0] = x ;
		for (int j = 1 ; j <= n ; j ++ )
			cin >> a[i][j] ;
	}
	
	res = losum ;
	int total = 0 ;
	for (int state = 1 ; state < (1 << k) ; state ++ )
	{
		nwE.clear() ;

		bool flag = false ;
		for (int i = 0 ; i < k ; i ++ )
			if ((state >> i) & 1)
			{
				total += a[i + 1][0] ;
				if (total > res)
				{
					flag = true ;
					break ;
				}
				for (int u = 1 ; u <= n ; u ++ )
					nwE.push_back(Edge{n + i + 1, u, a[i + 1][u]}) ;
			}

		if (flag) continue ;
		for (int i = 1 ; i <= m ; i ++ )
			nwE.push_back(Edge{ed[i].u, ed[i].v, ed[i].w}) ;
		
		total += kruskal2() ;
		res = min(total, res) ;
	}
	
	cout << res << '\n' ;
	
	return 0 ;
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
