#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n;
int a[N];
void dfs()
{
	int res = 0;
	int sum = 0,idx;
	for(int i = 1; i <= n -2; i ++)
	{
		for(int j = i + 1; j <= n - 1; j ++)
		{
			for(int z = j + 1; z <= n; z ++)
			{
				sum = 0;
				idx = max(a[i],max(a[j],a[z]));
				sum = a[i] + a[j] + a[z];
				if(sum > 2 * idx) res ++;
			}
		}
	}
	if(n < 4) 
	{
		cout << res;
		return;
	}
	for(int i = 1; i <= n -3; i ++)
	{
		for(int j = i + 1; j <= n - 2; j ++)
		{
			for(int z = j + 1; z <= n-1; z ++)
			{
				for(int x = z + 1; x <= n; x ++)
				{
					sum = 0;
					idx = max(max(a[x],a[i]),max(a[j],a[z]));
					sum = a[i] + a[j] + a[z] + a[x];
					if(sum > 2 * idx) res ++;
				}
			}
		}
	}
	if(n < 5) 
	{
		cout << res;
		return;
	}
	for(int i = 1; i <= n -4; i ++)
	{
		for(int j = i + 1; j <= n - 3; j ++)
		{
			for(int z = j + 1; z <= n-2; z ++)
			{
				for(int x = z + 1; x <= n-1; x ++)
				{
					for(int y = x+1; y <= n; y ++)
					{
						sum = 0;
						idx = max(max(a[x],a[i]),max(a[y],max(a[j],a[z])));
						sum = a[i] + a[j] + a[z] + a[x] + a[y];
						if(sum > 2 * idx) res ++;
					}
				}
			}
		}
	}
	if(n < 6) 
	{
		cout << res;
		return;
	}
	for(int i = 1; i <= n -5; i ++)
	{
		for(int j = i + 1; j <= n - 4; j ++)
		{
			for(int z = j + 1; z <= n-3; z ++)
			{
				for(int x = z + 1; x <= n-2; x ++)
				{
					for(int y = x+1; y <= n-1; y ++)
					{
						for(int w = y + 1; w <= n; w ++)
						{
							sum = 0;
							idx = max(max(a[w],max(a[x],a[i])),max(a[y],max(a[j],a[z])));
							sum = a[i] + a[j] + a[z] + a[x] + a[y] +a[w];
							if(sum > 2 * idx) res ++;
						}
					}
				}
			}
		}
	}
	cout << res;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	dfs();
	return 0;
}
