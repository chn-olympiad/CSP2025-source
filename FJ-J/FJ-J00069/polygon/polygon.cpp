#include <bits/stdc++.h>
using namespace std;

int n, ans;
int v[5001], a[5001];

void dfs(int step)
{
	if (step > n)
	{
		int maxn = 0, cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 1)
			{
				cnt += v[i];
				maxn = max(maxn, v[i]);
			}
		}
		if (cnt > maxn * 2) ans ++;
		ans %= 998244353;
		
		return;
	}
	
	a[step] = 0;
	dfs(step + 1);
	a[step] = 1;
	dfs(step + 1);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i];
	
	dfs(1);
	
	cout << ans << endl;
	
	return 0;
}
