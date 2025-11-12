#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a,l,s,sn,sm;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a;
		if(i==1)l=a;
		if(a>=l)s++;
	}
	sm=s/(n*2);
	sm*=2;
	s%=n*2;
	if(s<=n)sm++,sn=s;
	else sm+=2,sn=n-(s-n)+1;
	cout<<sm<<" "<<sn;
	return 0;
}
