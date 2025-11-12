#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],t,c,r;
	cin>>n>>m;
	int l=n*m;
	for(int i=1; i<=l; i++)
	{
		cin>>a[i];
		t=a[1];
	}
	sort(a+1,a+l+1);
	for(int i=1; i<=l; i++)
	{
		cout<<a[i]<<' ';
		if(t==a[i])
		{
			if(i%n==0)
			{
				c=i/n;
				if(c%2==0) r=1;
				else r=n;
			}
			else
			{
				c=i/n+1;
				if(c%2==0) r=n-i%n;
				else r=i%n;
			}
		}
	}
	cout<<r<<" "<<c;
	return 0;
}
