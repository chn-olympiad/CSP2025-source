#include<bits/stdc++.h>
using namespace std;
long long n,m,b[3000],r,h[1005],s=0,z=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(long long i=1;i<n*m;i++)
	{
		cin>>b[i];
		h[b[i]]=1;
	}
	for(long long i=r+1;i<=100;i++)
	{
		if(h[i]==1)
		{
			s++;
		}
	}
	s++;
	z=s/n;
	s%=n;
	if(z%2==1)
	{
		if(s==0)
		{
			cout<<z<<" "<<n;
		}
		else
		{
			cout<<z+1<<" "<<n-s+1;
		}
	}
	else
	{
		if(s==0)
		{
			cout<<z<<" "<<1;
		}
		else
		{
			cout<<z+1<<" "<<s;
		}
	}
	return 0;
}
