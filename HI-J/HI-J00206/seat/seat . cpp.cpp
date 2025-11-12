#include<bits/stdc++.h>

using namespace std;



int w[15][15],c[105];
int main()
{
	//freopen("seat.in","r",stdin)
	//freopen("seat.out","w",stdout)
	
	int n,m;
	
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++)
	{
		cin>>c[i];
	}
	int r=c[1];
	
	//≈≈–Ú 
	int b=0;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if( c[i]>c[j] )
			{
				b=c[i];
				c[i]=c[j];
				c[j]=b;
			}
		}
	}
	int t=1;
	for(int i=1;i<=n*m;i++)
	{
		if( c[i]==r )
		{
			if( i%m==0)
			{
				cout<<i/m<<" "<<n;
			}
			else
			{
				cout<<i/m+1<<" "<<i-m;
			}
		}
	}
	
	
	
	//fclose(stdin)
	//fclose(stdout)
	
	return 0;
} 
