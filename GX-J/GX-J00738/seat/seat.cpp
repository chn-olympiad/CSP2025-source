#include<bits/stdc++.h>
using namespace std;
long long a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,z,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	z=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==z) 
		{
			z=i;
			break;
		}
	}
	if(z%n==0)
	{
		y=z/n;
		if(z/n%2==0)
		{
			x=z%n+1;
		}
		else 
		{
			x=n;
		}
	}
	else
	{
		y=z/n+1;
		if((z/n+1)%2==0)
		{
			x=n-z%n+1;
		}
		else
		{
			x=z%n;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
