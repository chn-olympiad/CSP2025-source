#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct road{
	int u,v,w;
}r[N];
int c[15],a[15][N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>r[i].u>>r[i].v>>r[i].w;
		ans+=r[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i]; 
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			ans+=a[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
 } 
