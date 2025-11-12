#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000009],v[1000009],w[1000009];
int c[20],a[20][1000009];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long int ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	int a;
	for(int i=1;i<=k;i++)
	{
		cin>>a;
		for(int j=1;j<=n;j++)
		{
			cin>>a;
		}
	}
	cout<<ans;
    return 0;
}

