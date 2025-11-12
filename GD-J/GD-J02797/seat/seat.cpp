#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[105],r,s[15][15];

bool cmp(int x,int y)
{
	return x>y; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)r=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			if(i%n==0)
			{
				if((i/n)%2==0)
				{
					cout<<i/n<<' '<<1;
					return 0;
				}
				else
				{
					cout<<i/n<<' '<<n;
					return 0;
				}
			}
			else
			{
				if((i/n+1)%2==0)
				{
					cout<<i/n+1<<' '<<n-(i%n)+1;
					return 0;
				}
				else
				{
					cout<<i/n+1<<' '<<i%n;
					return 0; 
				}
			}
		}
	}
}
