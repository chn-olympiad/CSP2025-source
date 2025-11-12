#include<bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
bool cmp(int a,int b)
{
	return a>b;
}
int main()`
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<' ';
	int t=0;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				b[i][j]=a[++t];
			}
		}
		else 
		{
			for(int i=n;i>0;i--)
			{
				b[i][j]=a[++t];
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//cout<<b[i][j]<<' ';
			if(b[i][j]==x)
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
		//cout<<'\n';
	}
	return 0;
}
