#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
const int maxe = 1e4 + 1, maxv = 4e6 + 1;

int fa[maxv], con;
void init(int x)
{
	con = x;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
}
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	fa[find(x)] = find(y);
}

struct node
{
	int vt1, vt2, cst;
	bool operator<(node n2)
	{
		return cst < n2.cst;
	}
} rds[maxe];
int idx = 0;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ll ans = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		rds[idx++] = { u, v, w };
	}
	for (int i = 1; i <= k; i++)
	{
		int c;
		scanf("%d", &c);
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &c);
			if (j == c) continue;
			rds[idx++] = { i, j, c };
		}
	}
	init(n);
	sort(rds, rds + idx);
	for (int i = 0; i < idx; i++)
	{
		if (con > 1 && find(rds[i].vt1) != find(rds[i].vt2))
		{
			ans += rds[i].cst;
			con--;
			merge(rds[i].vt1, rds[i].vt2);
		}
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
