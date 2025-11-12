#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int sum[N];
int n;
int a[N];
long long ans;
long long sum1;
long long Sum[N];
void dfs(int now , int cnt , int sum , int maxn)
{
	if (now <= n)
	{
		dfs(now + 1 , cnt + 1 , sum + a[now] , max(maxn , a[now]));
		dfs(now + 1 , cnt , sum , maxn);
	}
	if (now > n)
	{
		if (cnt < 3)
		{
			return ;
		}
		if (sum > 2 * maxn)
		{
//			cout << now << " " << cnt << " " << sum << " " << maxn << endl;
			ans = (ans + 1) % 998244353;
		} 
		return ;
	}
	return ;
}
long long dp[510][510];
int maxnn;
long long S(int now)
{
	if (now == 0)
	{
		return 1;
	}
	long long sum = 1;
	for (int i = 1; i <= now ;++i)
	{
		sum = sum * i % 998244353;
	}
	return sum;
}
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
//	cout << S(5);
	cin >> n; 
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		maxnn = max(a[i] , maxnn);
	}
	if (maxnn == 1)
	{
		ans = 0;
		for (int i = n ; i >= 3 ; --i)
		{
			ans = (ans % 998244353 + S(n) / S(i) / S(n - i) % 998244353) % 998244353;
		}
		cout << ans;
	}else if (n <= 20)
	{
		dfs(1 , 0 , 0 , 0);
		cout << ans;
	}else
	{
		sort(a + 1 , a + 1 + n);
		for (int i = 1; i <= n; ++i)
		{
			Sum[i] = Sum[i - 1] + a[i];
		}
		for (int j = 0; j < n ; ++j)
		{
			for(int i = j + 3; i <= n; ++i)
			{
				if (Sum[i] > 2 * a[i])
				{
					ans = (ans + 1) % 998244353;
				}
			}
		 } 
		cout << ans;
	}
	return 0;
}
//cnm = n!/ m!/(n-m)!
/*
5
1 2 3 4 5
1 5 16 42 99 219 466 968
*/
