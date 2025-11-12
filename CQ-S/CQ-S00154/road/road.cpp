#include<bits/stdc++.h>
using namespace std;
long long n,m,k,i,j,ans;
long long b[15][10005],c[15];
struct node
{
	long long u,v,w;
}a[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long long j=1;j<=n;j++)
		{
			cin>>b[i][j];
			ans+=b[i][j];
		}
		ans+=c[i];
	}
	if(ans%(n*2+2)!=0)
	cout<<ans/(n*2+2)+1;
	else
	cout<<ans/(n*2+2);
	return 0;
}
