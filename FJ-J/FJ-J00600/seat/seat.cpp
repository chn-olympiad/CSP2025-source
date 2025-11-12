#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],rs,Rcj,Rmc,ls,hs;
	cin>>n>>m;
	rs=n*m;
	for(int i=1;i<=rs;i++)
	{
		cin>>a[i];
	}
	Rcj=a[1];
	sort(a+1,a+rs+1);
	for(int i=rs;i>=1;i--)
	{
		if(a[i]==Rcj)
		{
			Rmc=rs-i+1;
			break;
		}
	}
	if(Rmc%n==0)
	{
		ls=Rmc/n;
	}
	else
	{
		ls=(Rmc/n)+1;
	}
	if(ls%2==1)
	{
		if(Rmc%n==0)
		{
			hs=n;
		}
		else
		{
			hs=Rmc%n;
		}
	}
	else
	{
		if(Rmc%n==0)
		{
			hs=1;
		}
		else
		{
			hs=n-(Rmc%n)+1;
		}
	}
	cout<<ls<<' '<<hs;
	return 0;
}
