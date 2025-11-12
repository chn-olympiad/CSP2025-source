#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10001],b[10001][10001],f=1,c[10001],k=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>c[i];
	}
	int num=c[1];
	sort(c+1,c+n*m+1);
	{
		for(int i=n*m;i>=1;--i)
		{
			a[k]=c[i];
			++k;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(i%2==0)
		{
			for(int j=m;j>=1;--j)
			{
				b[i][j]=a[f];
				++f;
			}
		}
		else{
			for(int j=1;j<=m;++j)
			{
				b[i][j]=a[f];
				++f;
			}
		}
		
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(b[i][j]==num)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0; 
}
