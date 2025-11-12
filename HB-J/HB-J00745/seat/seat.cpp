#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int R;
int c,r;
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
	}
	R=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
//			cout<<a[i]<<" "<<i;
			if(i%n==0)
			{
				c=i/n;
			}
			else
			{
				c=(i/n)+1;
			}
			if(c%2==1)
			{
				if(i%n==0)
					r=n;
				else
					r=i%n;
			}
			else
			{
				if(i%n==0)
					r=1;
				else
					r=n-(i%n)+1;
			}
			cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
}
