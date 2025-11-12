#include <bits/stdc++.h>
using namespace std;


int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);





	int c,r,R;
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int x=n*m;
	int b[x];
	int h[x];
	
	for(int i=0;i<=x-1;i++)
	{
		cin>>h[i];
	}
	R=h[0];
	sort(h,h+x);
	int p=0;
	for(int i=x-1;i>=0;i--)
	{
		b[p]=h[i];
		
		p=p+1;
	}
	
	
	
	
	
	
	for(int i=0;i<=m-1;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<=n-1;j++)
			{
				a[i][j]=b[i*n+j];
			}
		}
		
		if(i%2==1)
		{
			for(int j=n-1;j>=0;j--)
			{
				a[i][j]=b[i*2*n-j-1];
			}
			
		}
		
		
	}
	for(int i=0;i<=m-1;i++)
	{
		
		for(int j=0;j<=n-1;j++)
		{
			if(a[i][j]==R)
			{
				r=i+1;
				c=j+1;
				cout<<r<<" "<<c;
			}
		}
	}
	
	
	
	return 0;
}