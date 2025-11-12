#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[2100][4];
int b[2100][2100];
int sum;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i][1];
		cin>>a[i][2];
		cin>>a[i][3];
		sum+=a[i][3];	
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i][1];
		for(int j=2;j<=n+1;j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<sum;
	return 0;
}
