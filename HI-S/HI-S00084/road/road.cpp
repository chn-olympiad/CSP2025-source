#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,c;
long long w,sum;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		sum+=w;
		for(int j=1;j<=k;j++)
		{
			for(int q=1;q<=n+1;q++)
			{
				cin>>c;
			}
		}
	}
	cout<<w;
	return 0;
}

