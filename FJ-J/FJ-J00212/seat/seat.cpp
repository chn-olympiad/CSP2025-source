#include<bits/stdc++.h>
using namespace std;
int n,m,d,c[105],score,l,r,e;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	d=n*m;
	for(int i=1;i<=d;i++)
	{
		cin>>c[i];
		if(i==1) score=c[i];
	}
	sort(c+1,c+1+d);
	for(int i=d;i>=1;i--)
	{
		if(c[i]==score) e=d-i+1;
	}
	if(e%n==0) l=e/n;
	else l=floor(e/n)+1;
	r=e%n;
	if(l%2!=0&&r==0)
	{
		cout<<l<<" "<<n;
		return 0;
	}
	else if(l%2!=0&&r!=0)
	{
		cout<<l<<" "<<r;
		return 0;
	}
	else if(l%2==0&&r==0)
	{
		cout<<l<<" "<<"1";
		return 0;
	}
	else if(l%2==0&&r!=0)
	{
		cout<<l<<" "<<n-r+1;
		return 0;
	}
	return 0;
}
