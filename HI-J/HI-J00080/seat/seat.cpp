# include <bits/stdc++.h>
using namespace std;
int n,m,s,cnt;
int a[105][105];
int b[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
	{
		cin >> b[i];
	}
	s=b[1];
	sort(b+1,b+1+n*m,cmp);
	for (int j=1;j<=m;j++)
	{
		if (j%2==1)
		{
			for (int i=1;i<=n;i++)
			{
				cnt ++;
				a[i][j]=b[cnt];
			}
		}
		else if (j%2==0)
		{
			for (int i=n;i>=1;i--)
			{
				cnt ++;
				a[i][j]=b[cnt];
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]==s)
			{
				cout << j << " " << i << endl;
				return 0;
			}
		}
	}
	return 0;
}
