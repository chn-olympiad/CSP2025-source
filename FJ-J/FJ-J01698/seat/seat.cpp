#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[107],f[107];
int b[17][17];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	
	int sum=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=n*m;i++)
	{
		f[n*m-i+1]=a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j%2==1)
			{
				b[i][j]=f[(j-1)*n+i];
			}
			
			else
			{
				b[i][j]=f[j*n-i+1];
			}
			
		}
		
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==sum)
			{
				cout<<j<<" "<<i;
				return 0;
			}
			
		}
		
	}
	
	return 0;
}
