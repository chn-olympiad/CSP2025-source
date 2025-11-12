#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6 + 114;

ll T;
ll n;
ll cntc, cnta, cntb;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for(int k = 1; k <= T; k++)
	{
		cnta = 0;
		cntb = 0;
		cntc = 0;
		cin >> n;
		ll a[n + 114][n + 114];
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
				if(a[i][3] == 0)
				{
					cntc++;
				}
				if(a[i][2] == 0)
				{
					cntb++;
				}
			}
		}
		ll ans = 0;
		if(cntb == cntc)
		{
			for(int i = 1; i <= n; i++)
			{	
				for(int j = 1; j <= n; j++)
				{
					if(i == j) continue;
					if(a[i][1] > a[j][1])
					{
						ll tmp = a[i][1];
						a[i][1] = a[j][1];
						a[j][1] = tmp;
					}
				}
			}
			for(int i = 1; i <= n / 2; i++)
			{
				ans += a[i][1];
			}
			cout << ans << '\n';
			return 0; 
		}
		for(int i = 1; i <= n; i++)
		{	
			for(int j = 1; j <= n; j++)
			{
				if(i == j) continue;
				if(a[i][2] > a[j][2])
				{
					ll tmp = a[i][2];
					a[i][2] = a[j][2];
					a[j][2] = tmp;
				}
			}
		}
		for(int i = 1; i <= n / 2; i++)
		{
			ans += a[i][1];
		}
		for(int i = 1; i <= n; i++)
		{	
			for(int j = 1; j <= n; j++)
			{
				if(i == j) continue;
				if(a[i][3] > a[j][3])
				{
					ll tmp = a[i][3];
					a[i][2] = a[j][2];
					a[j][2] = tmp;
				}
			}
		}
		for(int i = 1; i <= n / 2; i++)
		{
			ans += a[i][1];
		}
		cout << ans << '\n';
	}
	return 0;
}

