#include<bits/stdc++.h>
using namespace std;
int n,m,nn,xx,cnt,id;
int b[105];
int a[15][15],c[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	nn=n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			b[++cnt]=a[i][j];
		}
	}
	xx=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		c[i][1]=i;
		for(int j=2;j<=m;j++)
		{
			if(j%2==0)
				c[i][j]=c[i][j-1]+2*n-(2*i-1);
			else
				c[i][j]=c[i][j-1]+(2*i-1);
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		if(b[i]==xx)
		{
			id=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j]==id)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
