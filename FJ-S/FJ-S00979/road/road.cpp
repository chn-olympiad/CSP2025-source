#include<bits/stdc++.h>
using namespace std;
int ans,n,m,k,u[10005],v[10005],w[1000005],c[11],a[10][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i],ans+=w[i];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;i++)
		cin>>a[i][j];
	}
	cout<<ans;
}
