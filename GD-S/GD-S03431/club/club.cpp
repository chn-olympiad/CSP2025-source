#include<bits/stdc++.h>
using namespace std;
int a[100005][5],Max,n,b[5],c[5],d[100005];
void dfs(int i,int s)
{
	if(i > n)
	{
		Max = max(Max,s);
		return;	
	}
	for(int j = 1;j <= 3;j++)
	{
		if(b[j] + 1 <= n / 2)
		{
			s += a[i][j];
			b[j]++;
			dfs(i + 1,s);
			b[j]--;
			s -= a[i][j];
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		Max = 0;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				cin >> a[i][j];
				if(j == 2)
				{
					if(a[i][j] == 0) c[j]++;
				}
				if(j == 3)
				{
					if(a[i][j] == 0) c[j]++;
				}
			}
		}
		if(n <= 30) dfs(1,0);
		else
		{
			if(c[2] == n && c[3] == n)
			{
				for(int i = 1;i <= n;i++)
				{
					d[i] = a[i][1];
				}
				sort(d,d + n + 1);
				for(int i = n;i > n / 2;i--)
				{
					Max += d[i];
				}
			}
		}
		cout << Max << "\n";
	 } 
	return 0;
 } 
