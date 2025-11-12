#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e4 + 25, K = 12;
const ll inf = 1e18;
struct edge
{
	int u, v, w;
	edge(int u0 = 0, int v0 = 0, int w0 = 0)
	{
		u = u0;
		v = v0;
		w = w0;
	}
	friend bool operator < (edge e1, edge e2)
	{
		return e1.w < e2.w;
	}
};
vector<edge> qwq[K], val[K], tmp, res;
int fa[N], c[N], n, k;
ll cur, ans = inf;
int getf(int x)
{
	return (fa[x] == x) ? x : (fa[x] = getf(fa[x]));
}
bool un(int x, int y)
{
	x = getf(x);
	y = getf(y);
	if(x == y)
		return 0;
	fa[x] = y;
	return 1;
}
void work()
{
	res = {};
	int i;
	for(i = 1; i <= n + k; i++)
		fa[i] = i;
	for(auto o: tmp)
		if(un(o.u, o.v))
			res.emplace_back(o);
}
void dfs(int x)
{
	int i, j;
	ll sum;
	if(x > k)
	{
		sum = cur;
		for(auto o: qwq[k])
			sum += o.w;
		ans = min(ans, sum);
		return ;
	}
	qwq[x] = qwq[x - 1];
	dfs(x + 1);
	cur += c[x];
	i = j = 0;
	tmp.clear();
	while(i < qwq[x - 1].size() || j < val[x].size())
		if(i < qwq[x - 1].size() && (j == val[x].size() || qwq[x - 1][i] < val[x][j]))
			tmp.emplace_back(qwq[x - 1][i++]);
		else
			tmp.emplace_back(val[x][j++]);
	work();
	qwq[x] = res;
	dfs(x + 1);
	cur -= c[x];
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int m, u, v, w, i, j;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		tmp.emplace_back(edge(u, v, w));
	}
	sort(tmp.begin(), tmp.end());
	for(i = 1; i <= k; i++)
	{
		scanf("%d", c + i);
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &w);
			val[i].emplace_back(edge(n + i, j, w));
		}
		sort(val[i].begin(), val[i].end());
	}
	work();
	qwq[0] = res;
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}