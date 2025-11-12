#include<bits/stdc++.h>
using namespace std;
int n,m,s[105][105],a[105][105];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>s[i][j];
			a[i][j]=0;
		}
	}
	a[1][1]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(s[i][n]<s[i+1][1])
			{
				swap(s[i][n],s[i+1][1]);
				swap(a[i][n],a[i+1][1]);
			}
			if(s[i][j]<s[i][j+1])
			{
				swap(s[i][j],s[i][j+1]);
				swap(a[i][j],a[i][j+1]);
			}	
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			swap(s[i][j],s[j][i]);
			swap(a[i][j],a[i][j]);
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]==1)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
