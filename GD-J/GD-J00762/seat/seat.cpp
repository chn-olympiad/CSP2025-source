#include<bits/stdc++.h>
using namespace std;
int n,m,mc,a,r,ans=0,ans2=0,t=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<=n*m-1;i++)
	{
		cin>>a;
		if(a>r)mc++;
	}
	mc++;
	while(mc>=n)
	{
		mc=mc-n;
		t++;
	}
	if(mc==0)
	{
		if(t%2==1)
		{
			cout<<t<<" "<<n;
		}
		else 
		{
			cout<<t<<" "<<1;
		}
	}
	else 
	{
		if(t%2==1)
		{
			cout<<t+1<<" "<<n-mc+1;
		}
		else cout<<t+1<<" "<<mc;
	}
	return 0;
}
