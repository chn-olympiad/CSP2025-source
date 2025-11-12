#include <bits/stdc++.h>
using namespace std;
int n,m;
int x[100][100];
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int h=n*m;
	for(int i=1;i<=h;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	int i=0,j=1,flag=1;
	sort(a+1,a+h+1);
	for(int d=h;d>=1;d--)
	{
		i+=flag;
		if(i==n+1)i=n,j++,flag=-1;
		else if(i==0)i=1,j++,flag=1;
		x[i][j]=a[d];

	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(x[i][j]==r)
			{
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
