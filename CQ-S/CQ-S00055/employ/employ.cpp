//No one cares you else yourself.
#include<bits/stdc++.h>
using namespace std;
int t;		//t:1µÄ¸öÊý 
int ans;
int n, m;
int a[505];
int vis[505];
int l[505];
string s;
void dfs(int u)
{
	if (u > n)
	{
		int sorry = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s[i - 1] == '0')
			{
				sorry++;
			}
			else
			{
				if (l[i] <= sorry)
				{
					sorry++;
				}
			}
		}
		if (sorry <= n - m)
		{
			ans++;
//			for (int i = 1; i <= n; i++)
//			{
//				cout << l[i] << " ";
//			}
//			cout << "\n";
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			l[u] = a[i];
			dfs(u + 1);
			l[u] = 0;
			vis[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		t += s[i - 1] - '0';
	}
	if (t < m)
	{
		cout << "0\n";
		return 0;
	}
	if (n <= 18)
	{
		dfs(1);
		cout << ans % 998244353 << "\n";
	}
	else
	{
		cout << "0\n";
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
