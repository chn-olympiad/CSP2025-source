#include<bits/stdc++.h> 
using namespace std;
long long n,m,c,r,a[200],t,l=1,i;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		t=a[i];
		else
		{
		if(a[i]>t)
		l++;
	}
	}
	if(l%n==0)
	r=l/n;
	else
	r=l/n+1;
	if(r%2!=0&&l%n!=0)
	{
		c=l%n;
	}
	if(r%2==0&&l%n!=0)
	{
		c=n-l%n+1;
	}
	if(r%2!=0&&l%n==0)
	{
		c=n;
	}
	if(r%2==0&&l%n==0)
	{
		c=1;
	}
	cout<<r<<" "<<c;
	return 0;
}
