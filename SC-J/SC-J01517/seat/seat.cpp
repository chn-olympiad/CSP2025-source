#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],r,rm,rh,rl;
bool f=false;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==r)
		{
			rm=n*m-i+1;
			break;
		}
	}
	if(rm%n==0)
	{
		rl=rm/n;
	}
	else
	{
		rl=rm/n+1;
	}
	if(rl%2==1)
	{
		rh=rm%n;
		if(rh==0)
		{
			rh=n;
		}
	}
	else
	{
		if(rm%n==0)
		{
			rh=1;
		}
		else
		{
			rh=n-rm%n+1;
		}
	}
	cout<<rl<<" "<<rh;
	return 0;
} 