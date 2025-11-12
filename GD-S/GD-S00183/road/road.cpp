#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Bri
{
	ll to, val;
	bool flag;
};
vector<Bri> vec[10051];
ll f[15];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int p, q, v;
		cin >> p >> q >> v;
		vec[p].push_back({q, v, 0});
		vec[q].push_back({p, v, 0});
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> f[i];
		for(int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			vec[j].push_back({f[i], x, 1});
			vec[f[i]].push_back({j, x, 1});
		}
	}
	for(int i = 1; i <= n; i++)
	{
		
	}
	return 0;
}
