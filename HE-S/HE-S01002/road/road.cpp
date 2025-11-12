#include <bits/stdc++.h>
using namespace std;
int n,m,k,l,p,x,y;
int a[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>l;
		if(l==0) 
		{
			cout<<0;
			return 0;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>p;
		}
	}
	cout<<sum;
	return 0;
}
