#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m,k,u,v,w,x,a[100001],sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++)
	{
	    cin>>x;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
	}
	return 0;
}