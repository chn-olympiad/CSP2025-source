#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int tmp[400];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans;
	for (int i = 1;i<=n*m;i++)
	{
		cin>>tmp[i];
	}
	ans = tmp[1];
	sort(tmp+1,tmp+n*m+1,cmp);
	for (int i = 1;i<=n*m;i++)
	{
		int n1,m1;
		if (i%n==0)
		{
			n1 = n;
			m1 = i/n;
		}
		else
		{
			n1 = i%n;
			m1 = i/n+1;
		}
		if (m1%2==0)
		{
			a[n-n1+1][m1]=tmp[i];
		}
		else
		{
			a[n1][m1]=tmp[i];
		}
	}
	for (int i = 1;i<=n;i++)
	{
		for (int j = 1;j<=m;j++)
		{
			if (a[i][j]==ans)
			{
				cout<<j<<" "<<i;
				break;
			}
	    }
	}
	return 0;
}
