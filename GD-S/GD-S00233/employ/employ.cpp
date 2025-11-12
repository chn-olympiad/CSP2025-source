#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n ,m;
int a[N];
char c[N];
int k[N];
long long ans;
bool u[N];
inline void dfs(int now)
{
	if(now > n)
	{
		int sum = 0;
		for (int i = 1; i <= n; ++i)
		{
//			cout << c[i] << " " << k[i] << endl;
			if (c[i] == '0' || sum >= k[i])
			{
				sum++;
			}
		}
//		cout << endl;
		if (n - sum >= m)
		{
			ans++;
		}
		return ;
	}
	for (int i = 1; i <= n ;++i)
	{
		if (!u[i])
		{
			u[i] = true;
			k[now] = a[i];
			dfs(now + 1);
			u[i] = false;
		}
	}
	return ;
}
long long ans1;
int dp[510][510][510];
int main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> n >> m;
	bool f = true;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
		if (c[i] != 1)
		{
			f = false;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] != 0)ans1++;
	}
	if (f)
	{
		ans1 = 1;
		for (int i = 2; i <= n; ++i)
		{
			ans1 = ans1 * i % 998244353;
		}
		cout << ans1;
		return 0;
	}
	if (n> 18)
	{
		if (n <= m)
		{
			cout << 0;
			return 0;
		}
	}
	dfs(1);
	cout << ans;
	return 0;
}
/*
3 2
101
1 1 2
*/
