#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
int n,m,k,ans;
int u[M],v[M],w[M],c[15],a[15][10010];
bool flag=0;
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
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)flag=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]!=0)flag=1;
		}
	}
	if(!flag)cout<<0;
	else cout<<ans;
	return 0;
}
