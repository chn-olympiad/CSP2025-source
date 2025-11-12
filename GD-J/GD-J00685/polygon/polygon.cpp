#include <iostream>
#include <algorithm>
using namespace std;

bool flag[5005] = {};

int n, ans = 1;

int a[5005];

void dfs()
{
	int maxn = 0, cnt = 0, sum = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if(flag[i] == true)
		{
			maxn = max(maxn, a[i]);
			cnt++;
			sum += a[i];
		}
	}
	if(cnt <= 3) return ;
	for(int i = 0; i < n; i++)
	{
		if(flag[i] == true)
		{
			if(sum - a[i] > 2 * maxn)
			{
				flag[i] = false;
				ans++;
				ans %= 998244353;
				dfs();
				flag[i] = true;
			}
			else return ;
		}
	}
	return ;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = n; i < 5005; i++)
	{
		a[i] = 1e9;
	}
	sort(a, a + n);
	for(int i = 0; i <= 5000; i++)
	{
		flag[i] = true;
	}
	dfs();
	cout << ans % 998244353;
	return 0;
}
