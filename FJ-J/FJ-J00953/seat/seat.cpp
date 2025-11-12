#include <bits/stdc++.h>
using namespace std;
int a[11][11];
int b[102];
int n,m,r,c,d;
bool cnt(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	cout<<r<<endl;
	sort(b+1,b+n*m+1,cnt);
	int num=1;
	for(int j=1;j<=m;j++)
	{
		if (j%2)
		{
			for(int i=1;i<=n;i++)
			{
				a[i][j]=b[num++];
			}
		}
		else
		{
			for(int i=n;1<=i;i--)
			{
				a[i][j]=b[num++];
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if (r==a[i][j])
			{
				c=j;
				d=i;
				break;
			}
	cout<<c<<" "<<d;
	return 0;
}
