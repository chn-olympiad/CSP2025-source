#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,m,r,c=0,d;
int a[n+1][m+1],b[10000]={0};
bool ud=1;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
cin>>r;
b[0]=r;
for(int i=1;i<=m*n-1;i++)
{
	cin>>b[i];
}
for(int i=0;i<=n*m;i++)
{
	for(int j=0;j<=n*m;j++)
	{
		if(b[j]<b[j+1])
		{
			d=b[j+1];
			b[j+1]=b[j];
			b[j]=d;
		}
	}
}
for(int i=1;i<=m;i++)
{
	if(ud==0)
	{
		for(int j=n;j>=1;j--)
			{
				a[j][i]=b[c];
				c++;
				if(a[j][i]==r)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
	}
		if(ud==1)
	{
		for(int j=1;j<=n;j++)
			{
				a[j][i]=b[c];
				c++;
				if(a[j][i]==r)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
	}
	if(ud==0)
	ud=1;
	else ud=0; 
}
}