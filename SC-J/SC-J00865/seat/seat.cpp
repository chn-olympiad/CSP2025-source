#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],x;
bool cmp(int y,int z)
{
	return y>z;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(x==a[i])
		{
			if(((i+n-1)/n)%2==1)
			{
				cout<<(i+n-1)/n<<' ';
				if(i%n==0)
				{
					cout<<n;
				}
				else
				{
					cout<<i%n;
				}
			}
			else
			{
				cout<<(i+n-1)/n<<' ';
				if(i%n==0)
				{
					cout<<1;
				}
				else
				{
					cout<<n+1-i%n;
				}
			}
			break;
		}
	}
	return 0;
}