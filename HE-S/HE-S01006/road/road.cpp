#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
int ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans<<endl;
	return 0;
}
