#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
#define repf(i, a, b) for(int i = (a); i >= (b); i -- )
#define ls cur << 1
#define rs cur << 1 | 1
typedef long long ll;
using namespace std;
const int N = 1e4 + 100;
const int M = 1e6 + 10;
struct node
{
	int x, y, val;
}a[M], b[M], ch[M];
bool cmp(node n1, node n2)
{
	return n1.val < n2.val;
}
int fa[N];
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int c[15];
int cm[15][N];
ll ans = 0;
vector<int> v;
int n, m, k, tot;
void dfs(int dep, int cnt)
{
	if(dep == k + 1) 
	{
		// 加边 ksl 
		if(v.size() == 0) return;
		int tt = tot;
		rep(i, 1, tot) ch[i] = b[i];
		ll res = 0;
		int C = n;
		for(auto x : v)
		{
			// 加入的农村点
			++ C;
			res += c[x];
			rep(i, 1, n) ch[++ tt] = {C, i, cm[x][i]};
		}
		rep(i, 1, C) fa[i] = i;
		sort(ch + 1, ch + 1 + tt, cmp);
		rep(i, 1, tt)
		{
			int x = ch[i].x, y = ch[i].y;
			int fx = find(x), fy = find(y);
			if(fx != fy)
			{
			fa[fx] = fy;
			res += ch[i].val;
			}
		}
		ans = min(ans, res);
		return;
	}
	v.push_back(dep);
	dfs(dep + 1, cnt + 1);
	v.pop_back();
	dfs(dep + 1, cnt);
}
int main()
{
	ios ::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, 1, m) cin >> a[i].x >> a[i].y >> a[i].val;
	rep(i, 1, k)
	{
		cin >> c[i];
		rep(j, 1, n) cin >> cm[i][j];
	}
	sort(a + 1, a + 1 + m, cmp);
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m)
	{
		int x = a[i].x, y = a[i].y;
		int fx = find(x), fy = find(y);
		if(fx != fy)
		{
			b[++ tot] = {x, y, a[i].val};
			fa[fx] = fy;
			ans += a[i].val;
		}
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}
