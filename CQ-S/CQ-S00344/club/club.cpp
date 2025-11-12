#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","W",stdout);
	int sum=0,x=0,y=0,l1=0,l2=0,l3,o,p,q,m,z;
	cin>>t;
	cin>>n;
	if(n==2)
	{
	    cin>>a>>b>>c;
	    cin>>o>>p>>q;
	}	
	if(a>b)
	{
		x=a;
	}
	else x=b;
	if(c>x)
	{
		x=c;
	}
    if(x==a&&b>c)
	{
		m=b;
	}
	if(x==a&&b<c)
	{
		m=c;
	}
	if(x==b&&a>c)
	{
		m=a;
	}
	if(x==b&&a<c)
	{
		m=c;
	}
	if(x==c&&b>a)
	{
		m=b;
	}
	if(x==c&&b<a)
	{
		m=a;
	}
	cout<<m<<endl;
	if(o>p)
	{
		y=o;
	}
	else y=p; 
	if(q>y)
    {
    	y=q;
}
    if(y==o&&p>q||y==q&&p>o)
	{
		z=p;
	}
	if(y==o&&p<q||y==p&&o<q)
	{
		z=q;
	}
	if(y==p&&o>q||y==q&&p<o)
	{
		z=o;
	}
	cout<<z<<endl;
	if(x>y&&x==a&&y==o||x>y&&x==b&&y==p||x>y&&x==c&&y==q||x<y&&x==a&&y==o||x<y&&x==b&&y==p||x<y&&x==c&&y==q)
	{
		l1=x+z;
		l2=y+m;
		if(l1>l2)
		sum=l1;
		else sum=l2;
	}
	else sum=x+y;
	cout<<sum;
	return 0;
}
