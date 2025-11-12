#include <bits/stdc++.h>
using namespace std;
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
	int a[n*m+5];
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i]; 
	}
	int maxn=a[1];
	sort(a+1,a+n*m+1,cmp);
	int mn=0;
    for (int i=1;i<=n*m;i++)
	{
	    if (a[i]==maxn)
	    {
	    	mn=i;
	    	break;
		}
	}
	int c=mn/n;
	if (mn%n)
	{
		c++;
	}
	int r;
	if (c%2==1)
	{
		r=mn%n;
		if (r==0)
		{
			cout<<c<<" "<<n;
			return 0;
		}
	}
	else
	{
		r=n-mn%n+1;
		if (r==n+1)
		{
			cout<<c<<" "<<1;
			return 0;
		}
	}
	cout<<c<<" "<<r;
	return 0;		
}
