#include<bits/stdc++.h>
using namespace std;
int o[15][15];
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>a[i];
	}
	x=a[1];
	for(int i=1;i<n*m;++i)
	{
		for(int j=i+1;j<=n*m;++j)
		{
			if(a[i]<a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
	int ans=1;
	for(int i=1;i<=m;++i)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;++j)
			{
				o[j][i]=a[ans];
				ans++;
			}
		}
		else
		{
			for(int j=n;j>=1;--j)
			{
				o[j][i]=a[ans];
				ans++;
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(o[i][j]==x)
			{
				cout<<j<<" "<<i;
				exit(1);
			 }
		}
	}
}
