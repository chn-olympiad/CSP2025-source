#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10001, mod = 998244353;
int n, ans = 0, cnt = 0, a[N];
int f[25000001], b[N];
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = b[i - 1] + a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i < n; i++)
	{
		for(int j = b[n]; j >= a[i]; j--)
		{
			if(j > a[i])
			{
				f[j] += f[j - a[i]];
				f[j] %= mod;
			}
		}
		f[a[i]]++;
		f[a[i]] %= mod;
		if(i > 1)
		{
			for(int j = a[i + 1] + 1; j <= b[i]; j++)
			{
				ans += f[j];
				ans %= mod;
			}
		}
	}
	cout << ans;
}
