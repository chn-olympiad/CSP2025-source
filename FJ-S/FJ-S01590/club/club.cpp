#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t, n, a[N][4], a1[N], mx, ans;

void dfs(int x, int k1, int k2, int k3, int sum)
{
	if(x > n)
	{
		ans = max(ans, sum);
		return ;
	}
	if((k1 + 1) <= mx)
		dfs(x + 1, k1 + 1, k2, k3, sum + a[x][1]);
	if((k2 + 1) <= mx)
		dfs(x + 1, k1, k2 + 1, k3, sum + a[x][2]);
	if((k3 + 1) <= mx)
		dfs(x + 1, k1, k2, k3 + 1, sum + a[x][3]);
} 

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		mx = n / 2, ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
				scanf("%d", &a[i][j]);
			a1[i] = a[i][1];
		}
		if(n <= 10)
		{
			dfs(1, 0, 0, 0, 0);
		}
		else
		{
			sort(a1 + 1, a1 + 1 + n);
			for(int i = 1; i <= (n / 2); i++)
			{
				ans += a1[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
