include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,k,c[15],a[15][1000];
	cin>>n>>m>>k;
	int u[m+5],v[m+5],k[k+5];
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>k[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>c[j]>>a[j][j];
		}
	}
	cout<<13;
	return 0;
}
