#include<bits/stdc++.h>
using namespace  std;
long long n,m,a[110],pm,fs,ls,hs;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	fs=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==fs)
		{
			pm=n*m-i+1;
		}
	}
	ls=pm/n+1;
	if(pm%n==0)
	{
		ls--;
	}
	cout<<ls<<" ";
	hs=pm%n;
	if(hs==0)
	{
		hs=n;
	}
	if(ls%2==0)
	{
		hs=n-hs+1;
	}
	cout<<hs;
	return 0;
}
