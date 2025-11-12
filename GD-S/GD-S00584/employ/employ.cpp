#include <bits/stdc++.h>
using namespace std;

int a[505] = {};
int b[505] = {};
int num[505] = {};
int l = 1;
int ans = 1;
int maxn = 0;

int dfs(int x)
{
	if (x > maxn)
	{
		return 0;
	}
	if (num[x] == 0)
	{
		dfs(x + 1);
	}
	else
	{
		ans = max(ans * num[x],dfs(x + 1)) % 998244353;
		dfs(x + num[x] - 1);
	}
	return 0;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	int k = s.length();
	int f = 1;
	s = " " + s;
	for(int i = 1;i <= n;i++)
	{
		a[i] = 1 - (s[i] - '0');
		if (a[i] == 0)
		{
			f = 0;
		}
	}
	for(int i = 1;i <= n;i++)
	{
	    cin >> b[i];
	}
	if (f)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		num[a[i]]++;
		maxn = max(maxn,a[i]);
	}
	if (num[0] != 0)
	{
		dfs(num[0]);
	}
	dfs(num[1]);
	cout << ans;
	return 0;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
/*
2204128
*/
