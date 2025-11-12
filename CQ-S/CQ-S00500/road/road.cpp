#include <bits/stdc++.h>
using namespace std;
#define maxe 1000005
#define maxn 100005
int n, fst[maxn];
struct node
{
	int u, v, w;
	bool operator <(const node &n)const
	{
		return w < n.w;
	}
}arr[maxe], a[maxn], b[maxn * 11];
int tot;
vector<pair<int, int> > p[11];
int fa[maxn << 1], cnt;
int findroot(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = findroot(fa[x]);
}
int m, k;
vector<node> q[1024], now;
long long c[1024];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) cin >> arr[i].u >> arr[i].v >> arr[i].w;
	stable_sort(arr + 1, arr + m + 1);
	for (int i = 1; i <= n + k; ++i) fa[i] = i;
	long long sum = 0, ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		int p = findroot(arr[i].u), q = findroot(arr[i].v);
		if(p != q)
		{
			a[++tot] = arr[i];
			fa[p] = q;
			sum += arr[i].w;
		}
	}
	ans = sum;
	for (int i = 1; i <= k; ++i)
	{
		cin >> c[1 << i - 1];
		for (int j = 1; j <= n; ++j)
		{
			int x;
			cin >> x;
			p[i].push_back(make_pair(x, j));
		}
		stable_sort(p[i].begin(), p[i].end());
		for (int j = 0; j < p[i].size(); ++j)
		{
			node now;
			now.u = i + n, now.v = p[i][j].second, now.w = p[i][j].first;
			q[1 << i - 1].push_back(now);
		}
	}
	for (int sta = 1; sta < (1 << k); ++sta)
	{
		if(__builtin_popcount(sta) > 1)
		{
			int x = sta & -sta;
			int y = sta - x;
			int l = 0, r = 0;
			while(l < q[x].size() || r < q[y].size())
			{
				if(l >= q[x].size()) q[sta].push_back(q[y][r++]);
				else if(r >= q[y].size()) q[sta].push_back(q[x][l++]);
				else if(q[x][l].w < q[y][r].w) q[sta].push_back(q[x][l++]);
				else q[sta].push_back(q[y][r++]);
			}
			c[sta] = c[x] + c[y];
		}
		int siz = __builtin_popcount(sta);
		int all = 0;
		int l = 1, r = 0;
		while(l <= tot || r < q[sta].size())
		{
			if(l > tot) b[++all] = q[sta][r++];
			else if(r >= q[sta].size()) b[++all] = a[l++];
			else if(a[l].w < q[sta][r].w) b[++all] = a[l++];
			else b[++all] = q[sta][r++];
		}
		for (int j = 1; j <= n + k; ++j) fa[j] = j;
		long long sum = 0;
		int need = 0;
		for (int i = 1; i <= all; ++i)
		{
			int p = findroot(b[i].u), q = findroot(b[i].v);
			if(p != q)
			{
				fa[p] = q;
				sum += b[i].w;
				++need;
			}
			if(need == n + siz - 1) break;
		}
		ans = min(ans, sum + c[sta]);
	}
	cout << ans << endl;
	return 0;
}

