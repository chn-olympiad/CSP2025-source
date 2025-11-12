#include <bits/stdc++.h>
#define ll long long

using namespace std;

int t, n;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		int a[n][3], b[3][n];
		vector<int> c(n);
		vector<int> d(n);
		vector<int> e(n);
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < 3; j++)
				cin >> a[i][j];
				
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < n; j++)
				b[i][j] = a[j][i];
				
		for(int i = 0; i < n; i++)
			c[i] = b[0][i];
		sort(c.begin(), c.end());
		
		for(int i = 0; i < n; i++)
			d[i] = b[1][i];
		sort(d.begin(), d.end());
			
		for(int i = 0; i < n; i++)
			e[i] = b[2][i];
		sort(e.begin(), e.end());
		
		for(int i = 0; i < n; i++)
			b[0][i] = c[i];
			
		for(int i = 0; i < n; i++)
			b[1][i] = d[i];
			
		for(int i = 0; i < n; i++)
			b[2][i] = e[i];
			
		ll ans = 0;
		if(n == 2)
		{
			for(int i = 0; i < 3; i++)
			{
				int y = b[i][0];
				for(int j = 0; j < 3; j++)
					if(j != i)
						ans = max(ans, (y + b[j][1]) * 1LL);
			}
		}
		
		else
		{
			ans = c[n-1] + d[n-1] + e[n-1];
			int m = n - 3;
			for(int i = 0; i < m; i++)
			{
				ll f = ans;
				ans = max(ans, f + c[n-i-2]);
				ans = max(ans, f + d[n-i-2]);
				ans = max(ans, f + e[n-i-2]);
			}
		}	
		
		cout << ans << endl;	
	}
	
	return 0;
}
