#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	if(x>y)
	{
		return true;
	}
	return false;
}
long long int n,m,flagn,flags,c,r,a[10000001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	flagn=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(flagn==a[i])
		{
			flags=i;
			break;
		}
	}
	if(flags%n!=0)
		c=(flags/n)+1;
	else
		c=flags/n;
	if(c%2!=0)
	{
		if(flags%n==0)
		{
			r=n;
		}
		else
		{
			r=(flags%n); 
		}
	}
	else
	{
		if(flags%n==0)
		{
			r=1;
		}
		else
		{
			r=(flags%n)+1;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
