#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,m,k;
ll ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1,u,v,w;i <= n;i++)
	{
		cin >> u >> v >> w;
		ans += w;
	}
	cout << ans;
	return 0;
}
