#include <bits/stdc++.h>
using namespace std;
const int M=3000010;
int m,n,k,a[10010][10010],c[10010],ans=0;
int main()
{
	ifstream cin("road.in");
	ofstream cout("road.out");
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[1];
		for(int i=1;i<=n;i++)
		{
			cin>>c[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;i++)
			{
				if(a[i][j]>c[i]+c[j])
				{
					a[i][j]=a[j][i]=c[i]+c[j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int p=0x3f3f3f3f;
		for(int j=1;j<i;j++)
		{
			p=min(p,a[i][j]);
		}
		ans+=p;
	}
	cout<<ans;
	return 0;
}
