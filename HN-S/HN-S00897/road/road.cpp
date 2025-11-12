#include<bits/stdc++.h>
using namespace std;
long long n,m,k,v,u,t,c[20][10010],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>v>>u>>t;
		ans+=t;
	}
	for(int i=1;i<=k;i++)
	{
		long long h=0;
		cin>>c[i][0];
		h+=c[i][0];
		for(int j=1;j<=n;j++)
		  cin>>c[i][j],h+=c[i][j];
		ans=min(ans,h);
	}
	cout<<ans;
	return 0;
}
