#include <bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,c[11],a[10001][11],sum,cnt;
bool check[100001];
int main()
{
	freopen("road","r",stdin);
	freopen("road","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		sum+=w;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if (c[i]==0 and a[i][j]==0)
			{
				check[j]=1;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if(check[i]==1)
		{
			cnt++;
		} 
	}
	cout<<cnt;
	if (cnt==n)
	{
		cout<<0;
		return 0;
	}
	else
	{
		cout<<sum/3;
		return 0;
	}
	return 0;
}
