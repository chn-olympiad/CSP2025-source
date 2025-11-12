#include <bits/stdc++.h>
using namespace std;
int T,n,a[100005][5],sz[5],ans,maxx;
void dfs(int x,int g)
{
	if (sz[g]>n/2)
	{
		return;
	}
	if (x>=n)
	{
		ans=max(ans,maxx);
		return;
	}
	for (int i=1;i<=3;i++)
	{
		maxx+=a[x+1][i];
		sz[i]++;
		dfs(x+1,i);
		maxx-=a[x+1][i];
		sz[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n;
		bool flag=2;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=3;j++)
			{
				cin >> a[i][j];
				if (a[i][2]!=0 && a[i][3]!=0)
				{
					flag=1;
				}
			}
		}
		ans=0;
		if (flag==1)
		{
			maxx=0;
			dfs(0,0);
			cout << ans << "\n";
		}
		if (flag==2)
		{
			for (int i=1;i<=n;i++)
			{
				ans+=a[i][1];
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
