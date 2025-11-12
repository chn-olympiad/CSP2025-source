#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int t[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x1=1,x2=1,x3=0;
	while(x3<=m*n)
	{
		while(x1<=n)
		{
			t[x1][x2]=100-x3;
			x1++;
			x3++;
		}
		x3--;
		t[x1][++x2]=101-x3;
		while(x1>=1)
		{
			t[x1][x2]=100-x3;
			x1--,x3++;
		}
		x3--;
		t[x1][++x2]=101-x3;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(t[i][j]==a[1])
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
