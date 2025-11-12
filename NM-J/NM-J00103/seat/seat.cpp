#include<bits/stdc++.h>
using namespace std;
long long n,m,z[111],x[111],i,j,l,f[111][111],c;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	x[1]=1;
	cin>>n>>m;
	l=n*m;
	for(i=1;i<=l;i++)
	{
		cin>>z[i];
	}
	for(i=1;i<=l-1;i++)
	{
		for(j=1;j<=l-1;j++)
		{
			if(z[j]<z[j+1])
			{
				swap(z[j],z[j+1]);
				swap(x[j],x[j+1]);
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			c++;
			f[i][j]=z[c];
			if(x[c]==1)
			{
				if(i%2==1)
				{
					cout<<i<<" "<<j<<endl;
				}
				if(i%2==0)
				{
					cout<<i<<" "<<n-j+1<<endl;
				}
			}
		}
	}
	return 0;
}
