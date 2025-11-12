#include <bits/stdc++.h>
using namespace std;

int a[100003][5];
int n, maxn;

void dfs(int s, int suma, int sumb, int sumc, int sum)
{
	if(s > n)
	{
		maxn = max(maxn, sum);
		return;
	}
	if(suma < n / 2)
	{
		dfs(s + 1, suma + 1, sumb, sumc, sum + a[s][1]);
	}
	if(sumb < n / 2)
	{
		dfs(s + 1, suma, sumb + 1, sumc, sum + a[s][2]);
	}
	if(sumc < n / 2)
	{
		dfs(s + 1, suma, sumb, sumc + 1, sum + a[s][3]);
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
			}
		}
		maxn = 0;
		dfs(1, 0, 0, 0, 0);
		cout << maxn << endl;	
	}	
	return 0;
} 
