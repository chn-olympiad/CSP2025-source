#include <bits/stdc++.h>
using namespace std;

int a[5005];
bool f[5005];
int n, sum = 0;

bool check(int x)
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(f[i])
		{
			cnt += a[i];
		}
	}
	return cnt > 2 * x;
}

void dfs(int s, int cnt, int i, int maxn)
{
	if(cnt == i)
	{
		if(check(maxn))
		{
			sum++;
		}
		return;
	}
	if(s > n)
	{
		return;
	}
	if(n - s + cnt + 1 < i)
	{
		return;
	}
	f[s] = 1;
	dfs(s + 1, cnt + 1, i, max(maxn, a[s]));
	f[s] = 0;
	dfs(s + 1, cnt, i, maxn);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 3; i <= n; i++)
	{
		memset(f, 0, sizeof(f));
		dfs(1, 0, i, 0);
	}
	cout << sum;
	return 0;
}
