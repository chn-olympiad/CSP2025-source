//orz zbojin
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int ans, n, m, k, fa[10020], c[20], a[20][10010], cnt = 0, ecnt = 0, excnt = 0;
bool specA = true;

inline int rt(int u)
{
	while (u != fa[u])
		u = fa[u] = fa[fa[u]];
	return u;
}

struct edge
{
	int u, v, w;
	edge(int a, int b, int c) : u(a), v(b), w(c) {}
	edge() = default;
	inline bool operator<(const edge _) const
	{
		return w < _.w; 
	}
	inline bool operator>(const edge _) const
	{
		return w > _.w;
	}
}ed[1100010];

priority_queue<edge, vector<edge>, greater<edge> > pq, temp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++)
		fa[i] = i;
	int u, v, w;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		ed[i].u = u, ed[i].v = v, ed[i].w = w;
	}
	ecnt = m;
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if (c[i])
			specA = false;
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (specA)
				ed[++ecnt] = edge(i + n, j, a[i][j]);
		}
	}
	if (k == 0)
	{
		sort(ed + 1, ed + m + 1);
		for (int i = 1; i <= m; i++)
		{
			int fu = rt(ed[i].u), fv = rt(ed[i].v);
			if (fu != fv)
			{
				fa[fu] = fv;
				ans += ed[i].w;
				cnt++;
				if (cnt == n - 1)
					break;
			}
		}
		cout << ans;
	}
	else if (specA)
	{
		sort(ed + 1, ed + ecnt + 1);
		for (int i = 1; i <= ecnt; i++)
		{
			int fu = rt(ed[i].u), fv = rt(ed[i].v);
			if (fu != fv)
			{
				fa[fu] = fv;
				ans += ed[i].w;
				cnt++;
				if (cnt == n + k - 1)
					break;
			}
		}
		cout << ans;
	}
	else
	{
		for (int i = 1; i <= m; i++)
			temp.push(ed[i]);
		
		int mxn = (1 << k);
		ans = 0x3f3f3f3f;
		for (int i = 0; i < mxn; i++)
		{
			int res = 0;
			int cc = 0;
			cnt = 0;
			pq = temp;
			for (int ii = 0; ii < k; ii++)
				if (i & (1 << ii))
				{
					int t = (1 << ii);
					cc++;
					res += c[t];
					for (int iii = 1; iii <= n; iii++)
						pq.emplace(t + n, iii, a[t][iii]);
				}
				for (int i = 1; i <= n + k; i++)
					fa[i] = i;
			while (!pq.empty())
			{
				edge e = pq.top();
				pq.pop();
				int fu = rt(e.u), fv = rt(e.v);
				if (fu != fv)
				{
					fa[fu] = fv;
					res += e.w;
					cnt++;
					if (cnt == n + cc - 1)
						break;
				}
			}
			ans = min(ans, res);
		}
		cout << ans;
	}
}
