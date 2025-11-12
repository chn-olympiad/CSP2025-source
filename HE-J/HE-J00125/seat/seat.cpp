#include<bits/stdc++.h>
using namespace std;
int a[120];
bool ma(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xm,xmxb=0;
	int xmf=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	xmf=a[1];
	sort(a+1,a+1+n*m,ma);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==xmf)
		{
			xmxb=i;
		}
	}
	int l,h;
	if(xmxb%n==0)
	{
		l=xmxb/n;
	}
	else if(xmxb%n!=0)
	{
		l=xmxb/n+1;
	}
	if(l%2==0)
	{
		if(xmxb%n==0)
		{
			h=n;
		}
		else {
			h=n-xmxb%n+1;
		}
		
	}
	else if(l%2!=0)
	{
		if(xmxb%n==0)
		{
			h=n-xmxb%n;
		}
		else{
			h=xmxb%n;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
