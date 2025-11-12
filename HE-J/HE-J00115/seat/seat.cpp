#include<bits/stdc++.h>
using namespace std;
int k[1010][1010];
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a=1,b,c,d,e=0,f=1,m,n,q[100100],x,z;
	cin>>m;
	cin>>n;
	c=m*n;
	x=c;
	for(int i=1;i<=c;i++)
	{
		cin>>q[i];
	}
	z=q[1];
	sort(q+1,q+c+1);
	for(int i=1;i<=n;i++)
	{
		if(f%2==1)
		{
			for(int j=1;j<=m;j++)
		   {
			  k[j][i]=q[x];
			  x--;
		   }
		   f++;
		   continue;
		}
		if(f%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				k[j][i]=q[x];
				x--;
			}
			f++;
			continue;
		}
	}
		for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(k[i][j]==z)
			{
			  	cout<<j<<" "<<i;
			  	return 0;
			}
		}
	}
	return 0;
}
