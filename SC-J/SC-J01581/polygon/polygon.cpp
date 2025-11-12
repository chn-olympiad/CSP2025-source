# include<bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10, mod = 998244353;
long long a[N], jc[N], C[N][N], f[N][N], mx;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n; cin >> n;
	for(int i = 1;i <= n;i ++ ) cin >> a[i];
	sort(a + 1, a + n + 1); mx = a[n];
	C[0][0] = 1;
	for(int i = 1;i <= n;i ++ ) 
	{
		C[i][0] = 1;
		for(int j = 1;j <= n;j ++ )
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	for(int j = 0;j <= mx;j ++ ) f[0][j] = 1;
	for(int i = 1;i <= n;i ++ )
	{
		for(int j = 0;j <= mx;j ++ )
		{
			f[i][j] = f[i - 1][j] % mod;
			if(j >= a[i]) f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % mod;
		}
	}
	
	long long ans = 0;
	for(int i = 3;i <= n;i ++ )
	{
		long long sum = 0;
		for(int j = 0;j < i;j ++ ) sum = (sum + C[i - 1][j]) % mod;
		ans = (ans + ((sum - f[i - 1][a[i]]) % mod + mod) % mod) % mod;
	}
	cout << ans;
	return 0;
}