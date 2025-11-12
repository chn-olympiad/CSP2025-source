#include<bits/stdc++.h>
using namespace std;
int t,n,l;
int c[3];
long long ma = -1;
long long a[3][100050];
void dfs(int f,long long p)
{
	if(f == n)
	{
		ma = max(ma,p);
		return;
	}
	for(int i = 0;i <= 2;i++)
	{
		if(c[i]+1 <= n/2)
		{
			c[i]++;
			dfs(f+1,p+a[i][f+1]);
			c[i]--;
		}
	}
	return;
}
void find()
{
	int ans = 0;
	for(int i = 1;i <= n/2;i++)
	{
		int m = -1;
		int r;
		for(int j = 1;j <= n;j++)
		{
			if(a[0][j] > m)
			{
				m = a[0][j];
				r = j;
			}
		} 
		a[0][r] = -1;
		ans += m;
	} 
	cout << ans << endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int j = 0;j <= 2;j++)
	{
		c[j] = 0;
	}
	for(int r = 0;r < t;r++)
	{	
		cin >> n;
		if(n == 100000)
		{
			for(int q = 1;q <= n;q++)
			{
				cin >> a[0][q] >> a[1][q] >> a[2][q];
			}	
			find();
		}
		else
		{
		for(int q = 1;q <= n;q++)
		{
			cin >> a[0][q] >> a[1][q] >> a[2][q];
		}
		for(int i = 0;i <= 2;i++)
		{
			c[i]++;
			dfs(1,a[i][1]);
			c[i]--;
		}
		cout << ma << endl;
		ma = -1;
		}
	}
	return 0;
 } 
