#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int n,m;
int b[105];
int jsq=1;
bool cmp(const int &a,const int &b)
{
	return a>b;
}
int main()
{
		freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int ans;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	ans=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				a[i][j]=b[jsq];
				jsq++;
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=b[jsq];
				jsq++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==ans)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
