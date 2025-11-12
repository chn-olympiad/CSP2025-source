#include <bits/stdc++.h> 
using namespace std;
int n,m,Rs;
int a[200];
int s[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> Rs;
	for(int i=2;i<=n*m;i++)
		cin >> a[i];
	a[1]=Rs;
	sort(a+1,a+n*m+1,cmp);
	int wh=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
			for(int j=1;j<=n;j++)
				s[i][j]=a[++wh];
		else if(i%2==0)
			for(int j=n;j>=1;j--)
				s[i][j]=a[++wh];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]==Rs)
			{
				cout << i << " " << j;
			}
		}
	}
	return 0;
}