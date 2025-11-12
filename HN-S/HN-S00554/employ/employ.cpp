#include<bits/stdc++.h>
using namespace std;
const int N = 505;
long long n, m, a[N], f[N], b[N], ans;
string s;
void dfs(int k)
{
	if (k >= n)
	{
		int out = 0;
		for (int i = 1;i <= n;i++)
		{
			if (s[i] == '0' || a[b[i]] <= out)
			{
				out++;
			}
		}
		if (n - out >= m)
		{
			ans++;
		}
		return;
	}
	k++;
	for (int i = 1;i <= n;i++)
	{
		if (!f[i])
		{
			f[i] = 1;
			b[k] = i;
			dfs(k);
			f[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	dfs(0);
	cout << ans;
	return 0;
}
