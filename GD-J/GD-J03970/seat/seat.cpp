#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[110],s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		b[n*m-i+1]=a[i];
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				s++;
				if(b[s]==a1)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				s++;
				if(b[s]==a1)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
