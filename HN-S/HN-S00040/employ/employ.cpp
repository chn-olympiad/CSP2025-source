#include <bits/stdc++.h>

using namespace std;

const int N = 510;
int n, m, a[N], b[N], c[N], answer = 0;
string s;

void dfs (int q)
{
	if (q == n)
	{
		int cnt = 0, ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s[i - 1] == '1' && cnt < b[i])
			{
				ans++;
			}
			else
			{
				cnt++;
			}
		}
		if (ans >= m)
		{
			answer++;
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == 0)
		{
			c[i] = 1;
			b[q + 1] = a[i];
			dfs(q + 1);
			b[q + 1] = 0;
			c[i] = 0;
		}
	}
}

int main ()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dfs(0);
	cout << answer;
	return 0;
}
