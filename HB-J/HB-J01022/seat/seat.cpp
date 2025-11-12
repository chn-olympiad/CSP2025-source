#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int R;
int ans[15][15];
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
		cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if((i/n)%2==0)
		{
			if(i%n==0) ans[1][i/n]=a[i];
			else ans[i%n][i/n+1]=a[i];
		}
		else
		{
			if(i%n==0) ans[n][i/n]=a[i];
			else ans[n-i%n+1][i/n+1]=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]==R)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
