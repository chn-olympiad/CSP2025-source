#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int b[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			int x;
			cin>>x;
			if(j==1) b[i]=x;
		}
	}
	int minn=INT_MAX;
	for(int i=1;i<=k;i++)
	{
		minn=min(minn,b[i]);
	}
	cout<<minn;
	return 0;
}

