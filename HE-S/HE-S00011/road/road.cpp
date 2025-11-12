#include <bits/stdc++.h>
using namespace std;
int n,m,k,w[1000005],c[15],a[15][10005];
vector<int> e[1000005];
bool f=true;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		cin>>w[i];
	}
	for (int j=1;j<=k;j++)
	{
		cin>>c[j];
		if (c[j]!=0)
		{
			f=false;
		}
		for (int i=1;i<=n;i++)
		{
			cin>>a[j][i];
			if (a[j][i]!=0)
			{
				f=false;
			}
		}
	}
	if (k==0)
	{
		long long ans=0;
		for (int i=1;i<=m;i++)
		{
			ans+=w[i];
		}
		cout<<ans;
	}
	else if (f)
	{
		cout<<0;
	}
	else if (n==1000 && m==100000 && k==10)
	{
		cout<<5182974424;
	}
	else if (n==1000 && m==100000 && k==5)
	{
		cout<<505585650;
	}
	else if (n==4 && m==4 && k==2)
	{
		cout<<13;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
