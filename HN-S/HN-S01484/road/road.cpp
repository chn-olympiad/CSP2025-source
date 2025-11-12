#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, u, v, w, ans;
int main()
{
	//freopen("road.in", "r", stdin);	
	//freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	if (k == 0)
	{
		for (int i = 1; i <= m; i++) 
		{
			cin >> u >> v >> w;
			ans += w; 
		}
		cout << ans;
		return 0;
	}
	return 0;	
} 
