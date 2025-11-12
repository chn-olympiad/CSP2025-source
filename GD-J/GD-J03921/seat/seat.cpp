#include<bits/stdc++.h>
using namespace std;
long s[11][11],a[121],ar,n,m,r,c,sum=0;
bool cmp(long a,long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ar=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(long i=1;i<=n*m;i++)
	{
		if(a[i]==ar)
		{
			sum++;
			break;
		}
		else
		{
			sum++;
		}
	}
	if(sum%n==0)
	{
		c=sum/n;
	}
	else if(sum%n!=0)
	{
		c=sum/n+1;
	}
	if(sum%n==0)
	{
		if(c%2==0)
		{
			r=1;
		}
		else if(c%2!=0)
		{
			r=n;
		}
	}
	else if(sum%n!=0)
	{
		if(c%2==0)
		{
			r=n-(sum%n)+1;
		}
		else if(c%2!=0)
		{
			r=sum%n;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
