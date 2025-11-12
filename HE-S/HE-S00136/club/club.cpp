#include <bits/stdc++.h>
using namespace std;
int n,a[1000005][4],t,ans,m[4],mans,maxx[100000];
void dfs(int x)
{
	if (x==n+1)
	{
		mans=max(mans,ans);
		return ;
	}
	for (int i=1;i<=3;i++)
	{
		if (m[i]<(n/2))
		{
			m[i]++;
			ans+=a[x][i];
			dfs(x+1);
			ans-=a[x][i];
			m[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int k=1;k<=t;k++)
	{
		cin >> n;
		ans=0;
		mans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=3;j++)
			{
				cin >> a[i][j];
			}
		}
		dfs(1);
		maxx[k]=mans;
	}
	for (int i=1;i<=t;i++)
	{
		cout << maxx[i] << endl;
	}
	return 0;
}
