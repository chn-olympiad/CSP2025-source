#include <bits/stdc++.h>
using namespace std;
int a[20][20],b[200],c[5]={1,-1};
bool cmp(int e,int r)
{
	return e>r;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x;
	cin>>b[1];
	x=b[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+n*m+1,cmp);
	
	int i=1,j=1,f=0,s=0,k=0;
	if(n*m==1)
	cout<<1<<" "<<1;
	while(s<n*m)
	{
		a[i][j]=b[++s];
		
		if(k==1)
		{
			i+=c[f];
			k=0;
		}
		else if(i==1&&s!=1)
		{
			f=0;
			j++;
			k=1;
		}
		else if(i==n)
		{
			f=1;
			j++;
			k=1;
		}
		else
		{
			i+=c[f];
			
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			
			if(a[i][j]==x)
			cout<<j<<" "<<i;
			
		}
	}
	return 0;
}
