#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		int n, ans = 0;
		cin >> n;
		vector<int> x[3];
		
		for(int i = 1; i <= n; i++)
		{
			pair<int, int> a[3];
			cin >> a[0].first >> a[1].first >> a[2].first;
			a[0].second = 0;
			a[1].second = 1;
			a[2].second = 2;
			sort(a, a + 3);
			ans += a[2].first;
			x[a[2].second].push_back(a[2].first - a[1].first);
		}
		
		sort(x[0].begin(), x[0].end());
		sort(x[1].begin(), x[1].end());
		sort(x[2].begin(), x[2].end());
		
		if(x[0].size() > n / 2) 
		{
			int tmp = x[0].size() - n / 2;
			for(int i = 0; i < tmp; i++)
				ans -= x[0][i];
		}
		if(x[1].size() > n / 2) 
		{
			int tmp = x[1].size() - n / 2;
			for(int i = 0; i < tmp; i++)
				ans -= x[1][i];
		}
		if(x[2].size() > n / 2) 
		{
			int tmp = x[2].size() - n / 2;
			for(int i = 0; i < tmp; i++)
				ans -= x[2][i];
		}
		
		cout << ans << endl;
	}
	
	return 0;
}

