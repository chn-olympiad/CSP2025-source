#include<bits/stdc++.h>
using namespace std;
int a[1001000][5]={0};
int b[10100]={0};
int c[10100]={0};
int ans[10010]={0};
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int x,y,v;
		cin>>x>>y>>v;
		a[i][0]=x;
		a[i][1]=y;
		a[i][2]=v;
	}
	for(int i=0;i<k;i++)
	{
		int c1;
		cin>>c1;
		for(int j=1;j<=n;j++)
		{
			int v;
			cin>>v;
			a[((i+1)*n)+j][1]=j;
			a[((i+1)*n)+j][0]=n+i+1;
			a[((i+1)*n)+j][2]=c1+v;
			m++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[j]=0;
			c[j]=1000000;
		}
		b[i]=1;
		for(int j=1;j<n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(a[k][0]==j&&b[a[k][1]]!=1)
				{
					c[a[k][1]]=min(a[k][2],c[a[k][1]]);
				}else if(a[k][1]==j&&b[a[k][0]]!=1)
				{
					c[a[k][0]]=min(a[k][2],c[a[k][0]]);
				}
			}
			int ma=1;
			for(int k=2;k<=n;k++)
			{
				if(c[ma]>c[k])
				{
					ma=k;
				}
			}
			b[ma]=1;
			ans[i]+=c[ma];
			for(int k=1;k<=n;k++)
			{
				c[k]=1000000;
			}
		}
	}
	int ans1=10000000;
	for(int i=1;i<=n;i++)
	{
		ans1=min(ans1,ans[i]);
	}
	cout<<ans1;
	return 0;
}
