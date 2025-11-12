#include<bits/stdc++.h>
using namespace std;
int g[10001][19001]={0x3f};
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		int j,l;
		cin>>j>>l;
		cin>>g[j][l];
	}

	  int w,a[100001];
	for(int l=1;l<=k;l++)
	{
		
		cin>>w;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++){
			g[i][j]=min(g[i][j],a[i]+a[j]);
			}		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++){
			sum+=g[i][j];
			}		}
	cout<<sum;
	  
	return 0;
}
