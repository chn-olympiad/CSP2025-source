#include <bits/stdc++.h>
using namespace std;
int a[105];
int b[11][11];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int xR=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id;
	for(int i=1;i<=n*m;i++)
	{
		if(xR==a[i])
		{
			id=i;
		}
	}
	int cnt=0;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			cnt++;
			b[i][j]=cnt;
		}
		j++;
		for(int i=n;i>=1;i--)
		{
			cnt++;
			b[i][j]=cnt;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==id)
			{
				cout << j << " " << i;
			}
		}
	}
	return 0;
} 