#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 998244353;
int n, m;
int s[510];
int c[510];
int dp[510][510];
int a[20], b[20];
int ans;

bool cmp(int xx, int yy)
{
	return c[xx] < c[yy];
}

void dfs(int x, int fl, int sum)
{
	if(x > n)
	{
		if(sum >= m) ans ++;
		ans %= mod; 
		return;
	}
	for(int i = 1;i <= n;i ++)
	{
		if(a[i] == 0)
		{
			a[i] = 1;
			b[x] = i;
			if(c[i] > fl && s[x] == 1) dfs(x + 1, fl, sum + 1);
			else dfs(x + 1, fl + 1, sum);
			a[i] = 0;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string t;
	cin >> t;
	int val = 0;
	bool ck = 0;
	for(int i = 1;i <= n;i ++)
	{
		cin >> c[i];
		s[i] = (t[i - 1] - '0');
		val += s[i];
		if(s[i] == 0) ck = 1;
	}
	if(val < m)
	{
		cout << 0;
		return 0;
	}
	if(n == m)
	{
		int sum = 0;
		for(int i = 1;i <= n;i ++) sum += (c[i] > 0), ans *= i, ans %= mod;
		if(sum < m)
		{
			cout << 0;
			return 0;
		}
		cout << ans;
	}
	else
	{
		dfs(1, 0, 0);
		cout << ans;
	}
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

4 4
1111
2 4 2 1
*/
