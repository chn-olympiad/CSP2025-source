#include<bits/stdc++.h>
using namespace std;
int n,m; 
int a[120];
int b[20][20];
int z;
int qq=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	z=a[1];
	qq=n*m;
	sort(a+1,a+qq+1,cmp);
	int cc=0;
	for(int j=1;j<=m;j++)
	{	
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				cc++;
				b[i][j]=a[cc];
			}
			
		}
		else
		{
			for(int k=n;k>=1;k--)
			{
				cc++;
				b[k][j]=a[cc];
			}
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==z)
			{
				cout<<j<<" "<<i;
				
			}
		}
	}
	return 0;
}
