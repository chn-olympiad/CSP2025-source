//GZ-S00436 贵阳市南明区李端棻中学 邓景一 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	int n,m,k,u,v,w,ans=0,x=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		ans+=w;
	}
	for(int j=1;j<=n;j++)
		cin>>x;
	cout<<ans;
	return 0;
}
