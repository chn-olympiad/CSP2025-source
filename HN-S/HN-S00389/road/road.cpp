#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
	int u, v, w;
}s[1000005];

struct node2
{
	int v, w;
};

bool cmp(node x , node y)
{
	if (x.w < y.w) return true;
	return false;
}

int n, m, k, c[15], a[15][1000005], ans, f[1000005], f2[1000005];
vector <node2> v[1000005];
bool ff[1000005];

int find(int x)
{
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

void dfs(int x)
{
	ff[x] = true;
	for (auto i : v[x])
	{
		if (ff[i.v]) continue;
		f2[i.v] = x;
		dfs(i.v);
	}
	ff[x] = false;
}

int main()
{
	ios::sync_with_stdio(0) , cin.tie(0);
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for (int i = 1 ; i <= m ; i ++)
	{
		int uu, vv, ww;
		cin >> uu >> vv >> ww;
		s[m].u = uu, s[m].v = vv, s[m].w = ww;
		node2 t;
		t.v = vv, t.w = ww;
		v[uu].push_back(t);
	}
	for (int i = 1 ; i <= k ; i ++)
	{
		cin >> c[i];
		for (int j = 1 ; j <= n ; j ++)
		{
			f[j] = j;
			f2[j] = j;
			cin >> a[i][j];
		}
	}
	dfs(1);
	sort(s + 1 , s + m + 1 , cmp);
	for (int i = 1 ; i <= n ; i ++)
	{
		if (f2[s[i].u] != s[i].v) swap(s[i].u , s[i].v);
		if (find(s[i].u) == 1 || find(s[i].v) == 1) continue;
		f[s[i].u] = s[i].v;
		ans += s[i].w;
	}
	cout << ans;
	return 0;
}

