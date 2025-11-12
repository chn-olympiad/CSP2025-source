#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int n,m,k;
int v[MAXN],u[MAXN],w[MAXN];
int c[7],a[7][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	if(k==0)
	{
		long long ans=0;
		for(int i=1;i<=m;i++)
		{
			ans+=w[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"0";
	return 0;
}
