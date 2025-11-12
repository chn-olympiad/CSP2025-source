//T2暴力，挂了
//昔涟别歪就行
#include <bits/stdc++.h>
#define pll pair<long long , long long>
using namespace std;
typedef long long ll;
ll n , m , k;
ll u , v , w;
ll a[10005];
ll s[5005][5005];
vector<ll> G[10005];
ll cnt , sum , ans = LONG_LONG_MAX;
void dfs(ll x , ll fa)
{
//	cout << x << ' ' << fa << ' ' << sum << endl;
	cnt++;
	if(cnt == n)
	{
		cnt--;
		ans = min(ans , sum);
		return ;
	}
	for(auto y : G[x])
	{
		if(y == fa)
		{
			continue;
		}
		sum += s[x][y];
		dfs(y , x);
		sum -= s[x][y];
	}
	cnt--;
}
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	memset(s , 0x7f , sizeof(s));
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> u >> v >> w;
		s[u][v] = min(s[u][v] , w);
		s[v][u] = min(s[v][u] , w);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1;i <= k;i++)
	{
		ll x;
		cin >> x;
		for(int j = 1;j <= n;j++)
		{
			cin >> a[j];
		}
		for(int j = 1;j <= n;j++)
		{
			for(int k = 1;k <= n;k++)
			{
				if(j == k)
				{
					continue;
				}
				ll ss = a[j] + a[k] + x;
				if(s[j][k] == 9187201950435737471)
				{
					G[j].push_back(k);
				}
				s[j][k] = min(s[j][k] , ss);
			}
		}
	}
//	cout << G[1].size() << endl;
//	for(int j = 1;j <= n;j++)
//	{
//		for(int k = 1;k <= n;k++)
//		{
//			cout << s[j][k] << ' ';
//		}
//		cout << endl;
//	}
	dfs(1 , 0);
	cout << ans;
	return 0;
}