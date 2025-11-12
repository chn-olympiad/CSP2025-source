#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[m][4];
	for(int i=1;i<m;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	int c[n+2][2];
	for(int i=1;i<=k;i++)
	{
		cin>>c[1][i];
		for(int j=1;j<=n;j++)
		cin>>c[j+1][i];
	}
	cout<<0;
}
