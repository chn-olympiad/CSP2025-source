#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m,s=1,c,r;
int main()
{
	//by FLtops
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			s++;
		}
	}
	c=ceil(s*1.0/n);
	if(c%2)
	{
		r=s%n;
		if(r==0)
		{
			r=n;
		}
	}
	else
	{
		r=n-s%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

