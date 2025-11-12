#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct node
{
	int u,v,w;
}a[1000005];
int c[15],b[15][10005];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++) 
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		ans+=a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>b[i][j];
	}
	cout<<ans;
	return 0;
}
