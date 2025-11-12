#include<bits/stdc++.h>
using namespace std;
long long n,m,b,x,r,z;
struct str
{
	bool al;
	long long c;
}a[200];
bool cmp(str x,str y)
{
	return x.c>y.c;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	for(long long i=1;i<=z;i++)
	{
		a[i].al=false;
	}
	for(long long i=1;i<=z;i++)
	{
		cin>>a[i].c;
	}
	a[1].al=true;
	sort(a+1,a+z+1,cmp);
	for(long long i=1;i<=z;i++)
	{
		//cout<<a[i].c<<endl;
		if(a[i].al==true) x=i;
	}
	if(x%n==0)
	{
		b=x/n;
		if(b%2==0) cout<<b<<" "<<1;
		else cout<<b<<" "<<n;
	}
	else if(x%n!=0)
	{
		b=x/n+1;
		r=x%n;
		if(b%2==0) cout<<b<<" "<<n-r+1;
		else cout<<b<<" "<<r;
	}
	return 0;
}
