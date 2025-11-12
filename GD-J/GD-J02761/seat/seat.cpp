#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],p[20][20],sc,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++)
	{
		cin>>a[i];
		if(i==1) sc=a[i];
	}
	sort(a+1,a+num+1);
	l=n*m;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			p[i][j]=a[l];
			l--;
			if(p[i][j]==sc)
			{
				if(j%2==1)
				{
					cout<<j<<" "<<i;
					return 0;
				}else
				{
					cout<<j<<" "<<n-i+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
