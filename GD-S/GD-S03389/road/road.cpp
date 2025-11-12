#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m ,k;
	cin >> n >> m >> k;
	int sum = 0;
	
	int mn = 99999999999999;
	for(int i = 1;i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		//cout << sum <<" ";
		sum += w;
		
		
	}
//	cout <<sum <<" ";
	for(int i = 1; i <= k; i++)
	{int smm = 0;
		int a;
		cin >> a;
		smm += a;
		for(int j = 1;j <= n; j++)
		{
			int b;
			cin >> b;
			smm += b;
		}
	//	cout << smm <<" ";
		mn = min(mn, smm);
	}
	mn = min(mn, sum);
	cout << mn;
}
