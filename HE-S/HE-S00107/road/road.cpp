#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[m][3],c[m][3];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	int b[k][5];
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=2;j<m;j++)
		{
			if(a[i][3]>a[j][3])
			{
				c[i][3]=a[i][3];
				a[i][3]=a[j][3];
				a[j][3]=c[i][3];
			}
		}	
	}
	int o,d[k][5];
	o=a[1][3]+a[2][3];
	for(int i=1;i<=k;i++)
	{
		if(b[i][1]>b[i+1][1])
		{
			d[i][1]=b[i][1];
			b[i][1]=b[i+1][1];
		}
	}
	o=o+b[1][1]+b[1][2]+b[1][4];
	cout<<o<<endl;
	return 0;
}
