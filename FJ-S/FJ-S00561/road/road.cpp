#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 15, M = 1e6 + 5, K = 15;
typedef long long LL;
const LL INF = 1e14;
typedef pair<LL, int> PLI;
int n, m, k, par[N];
LL res, c[K];
struct node
{
	int a, b;
	LL c;
	int fr;
}E[M];
bool cmp(node x, node y){return x.c < y.c;}
int find(int x)
{
	if (par[x] == x)return x;
	else return par[x] = find(par[x]);
}
vector<node> trans[K];
LL work(int Status)
{
	for (int i = 1; i <= n + k + 1; i ++)par[i] = i;
	int point = n, cur[K] = {0};
	LL cost = 0;
	vector<int> pos;
	pos.push_back(k);
	for (int i = 0; i <= k; i ++)
	{
		if (Status >> i & 1)
		{
			cost += c[i];
			point ++;
			pos.push_back(i);
		}
		cur[i] = 0;
	}
	if (cost > res)return res;
	int cnt = 0;
	while (cnt < point - 1)
	{
		node edge = {0, 0, INF, k + 1};
		for (int i : pos)
		{
			if (cur[i] < (int)trans[i].size() && cmp(trans[i][cur[i]], edge))edge = trans[i][cur[i]];
		}
		cur[edge.fr] ++;
		int a = find(edge.a), b = find(edge.b);
		if (a == b)continue;
		par[a] = b;
		cnt ++;
		cost += edge.c;
		if (cost >= res)return res;
	}
	return cost;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i ++)par[i] = i;
	for (int i = 1; i <= m; i ++)scanf("%d%d%lld", &E[i].a, &E[i].b, &E[i].c);
	sort(E + 1, E + m + 1, cmp);
	for (int i = 1; i <= m; i ++)
	{
		int a = find(E[i].a), b = find(E[i].b);
		if (a == b)continue;
		par[a] = b;
		trans[k].push_back({E[i].a, E[i].b, E[i].c, k});
		res += E[i].c;
	}
	for (int i = 0; i < k; i ++)
	{
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j ++)
		{
			LL x;
			scanf("%lld", &x);
			trans[i].push_back({n + i + 1, j, x, i});
		}
		sort(trans[i].begin(), trans[i].end(), cmp);
	}
	for (int S = 1; S < (1 << k); S ++)res = min(res, work(S));
	printf("%lld", res);
	return 0;
}