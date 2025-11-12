#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int n,m,k;
	int u[100005],v[100005],w[100005],x;
	int ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		ans=ans+w[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>x;
		}
	}
	cout<<ans;
	return 0;
}

