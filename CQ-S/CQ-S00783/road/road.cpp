#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int min1=1e9;
	long long sum=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		min1=min(u,min1);
		min1=min(v,min1);
		min1=min(w,min1);
		sum+=min1;
		min1=1e9;
	}
	int minn=1e9;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=(n+1);j++)
		{
			int a;
			cin>>a;
			minn=min(minn,a);
		}
		sum+=minn;
	}
	cout<<sum;
	return 0;
} 
