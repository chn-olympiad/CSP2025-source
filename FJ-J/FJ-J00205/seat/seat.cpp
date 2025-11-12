#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],s[15][15],x,o=1,p;
bool cmp(long long y,long long z)
{
	return y > z;
}
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin >> n >> m;
	x=n*m;
	for(int i = 1; i<=x;i++)
	{
		cin >> a[i];
	}
	p=a[1];
	sort(a+1,a+1+x,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				s[j][i]=a[o];
				o++;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				s[j][i]=a[o];
				o++;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(s[i][j]==p)
			{
				cout << i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}