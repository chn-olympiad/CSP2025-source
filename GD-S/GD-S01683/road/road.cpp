#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int n, m, k, ron, ans, c[N];
bool mp[1004][1004], bdg[N];

int top;
struct stu
{
	int u, v, w;
	bool b;
}rod[N];

bool cmp(stu x, stu y)
{
	return x.w < y.w;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> rod[i].u >> rod[i].v >> rod[i].w;
		rod[i].b = 0;
		++top;
	}
	
	for (int i = 1; i <= k; ++i)
	{
		cin >> c[i];
		for (int j = 1; j <= n; ++j)
		{
			int aji;
			cin >> aji;
			if (c[i] <= n)
			{
				if (c[i] == aji)
				{
					ans += aji;
					continue;
				}
				++top;
				rod[top].u = c[i];
				rod[top].v = j;
				rod[top].w = aji;
				rod[top].b = 1;
			}
		}
	}
	
	sort(rod + 1, rod + top + 1, cmp);
	
	for (int i = 1; i <= top; ++i)
	{
		if (mp[rod[i].u][rod[i].v])continue;
		
		ans += rod[i].w;
		if (rod[i].b == 1 && !bdg[rod[i].u])
		{
			ans += c[rod[i].u];
			bdg[rod[i].u] = 1;
		}
		if (mp[rod[i].u][rod[i].v] == 0)++ron;
		mp[rod[i].u][rod[i].v] = mp[rod[i].v][rod[i].u] = 1;
		
		for (int j = 1; j <= n; ++j)
		{
			if (mp[rod[i].u][j] == 0)++ron;
			if (mp[rod[i].v][j] == 0)++ron;
			if (mp[rod[i].u][j] || mp[j][rod[i].u])mp[rod[i].v][j] = mp[j][rod[i].v] = 1;
			if (mp[rod[i].v][j] || mp[j][rod[i].v])mp[rod[i].u][j] = mp[j][rod[i].u] = 1;
		}
	}
	cout << ans;
	return 0;
}
