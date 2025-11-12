#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int a[100010][4] = {};
int l;
int maxn = 0;
int sum = 0;
int g[4] = {};
void dfs(int step)
{
	if(step == n+1)
	{
		maxn = max(maxn , sum);
	}
	for(int i = 1;i <= 3;++i)
	{
		if(g[i] >= l)
		{
			continue;
		}
		sum += a[step][i];
		g[i]++;
		dfs(step+1);
		sum -= a[step][i];
		g[i]--;
	}
}
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while(t--)
	{
		maxn = 0;
		sum = 0;
		cin >> n;
		l = n/2;
		if(n <= 10)
		{
			for(int i = 1;i <= n;++i)
			{
				for(int j = 1;j <= 3;++j)
				{
					cin >> a[i][j];
				}
			}
			dfs(1);
			cout << maxn << endl;
		}
	}
	
	
	
	return 0;
}
