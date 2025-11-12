#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
long long n, a[N], b[N], ans = 0;

void dfs(long long k)
{
	if(k == n + 1)
	{
		long long sum = 0, mx = 0;
		for(int i = 1; i <= n; i ++)
		{
			sum += b[i];
			mx = max(b[i], mx);
		}
		if(mx * 2 < sum)
		{
			ans ++;
		}
		return;
	}
	b[k] = a[k];
	dfs(k + 1);
	b[k] = 0;
	dfs(k + 1);
	return;
}

int main()
{
	#ifdef LOCAL
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	#endif
	cin >> n;
	bool p = true;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if(a[i] != 1)
		{
			p = false;
		}
	}
	if(p == true)
	{
		for(int i = 3; i <= n; i ++)
		{
			long long q = 1;
			for(int j = n; j >= n - j + 1; j --)
			{
				q *= j; 
			}
			for(int j = 1; j <= i; j ++)
			{
				q /= j;
			}
			ans += q;
		}
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1);
	dfs(1);
	cout << ans;
}
