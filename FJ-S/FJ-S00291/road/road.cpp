#include <cstdio>
#include <algorithm>

const int N = 1e4 + 7;
const int M = 3e6 + 7;

typedef long long ll; 

int n, m, k, father[N], tot;
ll ans;

using namespace std;

struct node
{
	int u, v;
	ll cst;
}graph[M];

void add_graph (int u, int v, ll cst)
{
	graph[++ tot].v = v;
	graph[tot].cst = cst;
	graph[tot].u = u;
}

bool cmp (node x, node y)
{
	return x.cst < y.cst;
}

int find_father (int x)
{
	if (father[x] == x)
		return x;
	return father[x] = find_father (father[x]);
}

bool pending (int x, int y)
{
	return father[x] == father[y];
}

void join (int x, int y)
{
	father[x] = y;
}

void kruskal ()
{
	sort (graph + 1, graph + tot + 1, cmp);
	int i = 1;
//	printf ("%d %d %lld\n", graph[1].u, graph[1].v, graph[1].cst); 
	for (int j = 1; i < n; j ++)
	{
		int a = graph[j].u, b = graph[j].v;
		ll c = graph[j].cst;
//		printf ("%d %d %lld\n", a, b, c); 
//		printf ("%d %d\n", father[a], father[b]); 
		if (pending (find_father (a), find_father (b)))
			continue;
//		printf ("C%lld\n", c); 
		ans += c;
		join (find_father (a), find_father (b));
//		printf ("%d %d\n", father[a], father[b]); 
		i ++;
//		printf ("%d\n", i); 
	}
}

int main ()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout); 
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i ++)
		father[i] = i; 
	for (int i = 1; i <= m; i ++)
	{
		int u, v;
		ll cst;
		scanf ("%d %d %lld", &u, &v, &cst); 
//		puts("*");
		add_graph (u, v, cst);
		add_graph (v, u, cst);
	}
	for (int i = 1; i <= k; i ++)
	{
		int Z;
		scanf ("%d", &Z);
		for (int j = 1; j <= n; j ++)
		{
			int X;
			scanf ("%d", &X);
			add_graph (i, j, X + Z);
		}
	}
	kruskal ();
	printf ("%lld", ans);
}
/*
6 7 1
1 2 2
2 3 2
2 4 3
3 4 7
4 5 3
5 6 4
3 6 4
0 1 0 7 2 4 3
*/
