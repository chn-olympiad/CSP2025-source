#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,t,h,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[0];
	sort(a,a+n*m);
	for(int i=0;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			t=i+1;
			break;
		}
	}
	l=(t-1)/n+1;
	if(l%2==1)
	{
		h=t%n;
		if(h==0)
		{
			h=n;
		}
	}
	else
	{
		h=(n-t%n)%n+1;
	}
	cout<<h<<' '<<l;
	return 0;
}
