#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

const int M = 1 << 21;

int n, k;

int a[N];

int f[N];

int sum[N];

int p[M + 10];

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	
	cin >> n >> k;
	
	for (int i=1; i<=n; i++)
		cin >> a[i];
	
	for (int i=1; i<=n; i++)
		sum[i] = sum[i-1] ^ a[i];
	
	for (int i=1; i<=n; i++)
	{
		p[sum[i]] = i;
		
		f[i] = f[i-1];
		
		if (a[i] == k)
		{
			f[i] = f[i-1] + 1;
		}
		else
		{
			if (!p[sum[i] ^ k] && (sum[i] ^ k) > 0)
				continue;
			
			f[i] = max(f[i], f[p[sum[i] ^ k]] + 1);
		}
	}
	
	cout << f[n] << '\n';
	
	return 0;
}
