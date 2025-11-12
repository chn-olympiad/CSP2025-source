#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, m;
string str;
int res = 0;
int c[505];
int fac(int x)
{
	if (x < 0)
		return 0;
	else if (x == 0)
		return 1;
	int ans = 1;
	for (int i=1;i<=x;i++)
		ans *= i, ans %= mod;
	return ans;
}
bool vis[505];
int tmp[505];
int cnt1[505];
void dfs(int k, int cnt, int sum)
{
	if (sum >= m)
	{
		res += fac(n-k+1);
		res %= mod;
		return ;
	}
	if (sum+cnt1[k] < m)
		return ;
	if (k > n)
	{
		if (sum < m)
			return ;
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		if (vis[i] == 0)
		{
			vis[i] = 1;
			int newcnt = cnt, newsum = sum;
			if (cnt >= c[i])
			{
				newcnt++;
			}
			else 
			{
				if (str[k] == '1')
					newsum++;
				else newcnt++;
			}
			tmp[k] = i;
			dfs(k+1, newcnt, newsum);
			vis[i] = 0;
		}
	}
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	cin >> n >> m;
	cin >> str;
	str = " "+str;
	for (int i=1;i<=n;i++)
	{
		cin >> c[i];
	}
	for (int i=n;i>=1;i--)
		cnt1[i] = cnt1[i+1]+str[i]-48;
	if (m == n)
	{
		bool flag = 1;
		for (int i=1;i<=n;i++)
			flag = (flag && (str[i] == '1'));
		if (flag == 0)
			cout << 0;
		else 
		{
			flag = 1;
			for (int i=1;i<=n;i++)
				flag = (flag && c[i]);
			if (flag)
			{
				int ans = 1;
				for (int i=1;i<=n;i++)
					ans = ans*i%mod;
				cout << ans;
			}
			else 
			{
				cout << 0;
			}
		} 
	} 
	else if (n <= 10)
	{
		dfs(1, 0, 0);
		cout << res;
	}
	else if (m == 1)
	{
		bool flag = 0;
		int pos = 0;
		for (int i=1;i<=n;i++)
		{
			flag = (flag || (str[i] == '1'));
			if (str[i] == '1' && pos == 0)
				pos = i;
		}
		if (flag == 0)
			cout << 0;
		else 
		{
			int cnt = 0;
			for (int i=1;i<=n;i++)
			{
				if (c[i] > pos-1)
					cnt++;
			}
			cout << cnt%mod*fac(n-1)%mod ;
		}
	} 
	else 
	{
		cout << 0;
	}
	return 0;
}
