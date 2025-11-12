#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
long long a[500010],c[5010][5010];
long long d[5010][5010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i][i]=a[i];
		if(a[i]>m)
		{
			c[i][i]=1;
		}
		if(c[i][i]==m)
		  x++;
	}
	for(long long i=2;i<=n;i++)
	{
		for(long long k=1;k<=n;k++)
		{
			int j=k+i-1;
			if(j<=n)
			{
				if(d[k][(k+j)/2]==1||d[(k+j)/2][j]==1)
				  d[i][j]==1;
				else
				{
					c[k][j]=c[k][(k+j)/2]+c[(k+j)/2+1][j];
					if(c[k][j]==m) x++;
					if(c[k][j]>k) d[k][j]=1;
				}
			}
		}
	}
	cout<<x;
	return 0;
 } 
