#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,u,v,w,a,b,c,d,e,minn=1e18,sum;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a;
		sum=a;
		for(int j=1;j<=n;j++)
		{
			cin>>b;
			sum+=b;
		}
		minn=min(minn,sum);
	}
	cout<<minn;
	return 0;
}
/*
4 1
1011
0 0 2 1
*/

