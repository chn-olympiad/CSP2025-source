#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,a1,i,j,n,m,s=0;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a;
		if(i==1)
		{
			a1=a;
			a1=101-a1;
		}
	}
	for(i=1;i<=m;i++)
	{
		if(s%2==0)
		{
			for(j=1;j<=n;j++)
			{
				a1--;
				if(a1==0)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(j=n;j>=1;j--)
			{
				a1--;
				if(a1==0)
				{
					cout<<m<<" "<<n;
					return 0;
				}
			}
		}
		s++;
	}
	return 0;
}
