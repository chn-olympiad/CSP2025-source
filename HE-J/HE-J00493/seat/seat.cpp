#include<bits/stdc++.h>
using namespace std;
int mp[15][15];
int m,n,x,d,ans,f;
int nm[105];
queue<int> num;
int main()
{
	freeopen(" number.in","r",stdin);
	freeopen(" number.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	ans=x;
	nm[1]=x;
	for(int i=2;i<=m*n;i++)
	{
		cin>>x;
		nm[i]=x; 
	}
	for(int j=1;j<=m*n;j++)
	{
		for(int i=1;i<=m*n;i++)
		{
			if(nm[i]>=nm[j])
			{
				d=nm[i];
				nm[i]=nm[j];
				nm[j]=d;
			}
		}
	}
	for(int i=m*n;i>=1;i--)
	{
		f=nm[i];
		num.push(f);
  	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				mp[j][i]=num.front();
				num.pop();
			}
		}
		else
		{
			for(int k=n;k>=1;k--)
			{
				mp[k][i]=num.front();
				num.pop();
			}
		 } 
	}
	for(int i=1;i<=n;i++)
	{ 
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==ans) cout<<j<<" "<<i;
		 } 
	} 
 } 
