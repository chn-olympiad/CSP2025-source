#include<bits/stdc++.h>
using namespace std;
int n,m,k,z;
long long ans=0;
int u[1000001],v[1000001],w[1000001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	for(int i=1;i<=k*(n+1);i++) cin>>z;
	cout<<ans;
	return 0;
	
}
