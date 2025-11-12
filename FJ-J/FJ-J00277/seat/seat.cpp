#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],f[15][15],r;
bool cmp(int a,int b)
{
	return a>b;
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
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{ 
			
			for(int j=1;j<=m;j++)
			{
				f[j][i]=a[m*(i-1)+j];
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				f[m-j+1][i]=a[m*(i-1)+j];
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(f[i][j]==r)
			{
				cout<<j<<" "<<i;
				break;
			} 
		}
	}
	return 0;
}
