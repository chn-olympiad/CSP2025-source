#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],ans,s[1005][1005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				s[i][j]=a[(i-1)*n+j];
			}
		}
		if(i%2==0)
		{
			for(int j=1;j<=m;j++)
			{
				s[i][j]=a[(i-1)*n+m-j+1];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]==ans)
			{
				cout<<i<<' '<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}