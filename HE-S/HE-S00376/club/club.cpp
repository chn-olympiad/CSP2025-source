#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
int T;
int n;
const int N = 1e5 + 5; 
int a[N][3];
int k[N];
int f[205][105][105];
int anss = 0;
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> n;
		bool isA = true;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
			if (a[i][2] != 0 || a[i][3] != 0)
				isA = false;
		}
		if (isA)
		{
			for (int i = 1; i <= n; i++)
				k[i] = a[i][1];
			sort(k + 1, k + n + 1);
			int ans = 0;
			for (int i = n; i >= n / 2 + 1; i--)
				ans += k[i];
			cout << ans << endl;
			return 0;	
		}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n / 2; j++)
				for (int k = 0; k <= n / 2; k++)
					f[i][j][k] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int ca = 0; ca <= n / 2 && ca <= i; ca++)
			{
				for (int cb = 0; cb <= n / 2 && ca + cb <= i; cb++)
				{
					int cc = i - ca - cb;
					if (cc > n / 2) continue;
					if (ca)
						f[i][ca][cb] = max(f[i][ca][cb], f[i - 1][ca - 1][cb] + a[i][1]);
					if (cb)
						f[i][ca][cb] = max(f[i][ca][cb], f[i - 1][ca][cb - 1] + a[i][2]);
					if (cc)
						f[i][ca][cb] = max(f[i][ca][cb], f[i - 1][ca][cb] + a[i][3]);
				}		
				
			}
		}
		int ans = 0;
		for (int ca = 0; ca <= n / 2; ca++)
		{
			for (int cb = 0; cb <= n / 2; cb++)
			{
				int cc = n - ca - cb;
				if (cc > n / 2) continue;
				ans = max(ans, f[n][ca][cb]);
			}	
		} 
		cout << ans << endl;
	}	
} 
