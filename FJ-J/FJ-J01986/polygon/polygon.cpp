#include <bits/stdc++.h>
using namespace std;

int n, a[10000], sum = 0;

void dfs(int ls, int tot, int ed)
{
	if (tot > a[ed])
	{
		++sum;
	}
	
	if (ls < ed)
	{
		for (int i = ls; i < ed; ++i)
		{
			dfs(i + 1, tot + a[i], ed);
		}
	}
	
	return ;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	sort(a, a + n);
	
	for (int i = 2; i < n; ++i)
	{
		dfs(0, 0, i);
	}
	
	cout << sum;
}
