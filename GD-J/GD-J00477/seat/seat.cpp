#include <bits/stdc++.h>
using namespace std;
int n,m,a[101],num,cnt;
bool cmp(int x,int y)
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
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	cnt=0;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cnt++;
			if (i%2==0)
			{
				if (a[cnt]==num)
				{
					cout<<i<<" "<<n-j+1;
					return 0;
				}
			}
			else
			{
				if (a[cnt]==num)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
