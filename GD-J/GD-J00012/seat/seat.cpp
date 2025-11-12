#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y)
{
	return x>y; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int b=a[1],p;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			p=i;
			break;
		}
	}
	int x=ceil(1.0*p/n);
	if(x%2==1)
	{
		cout<<ceil(1.0*p/n)<<" ";
		if(p%n==0)
			cout<<n;
		else
			cout<<p%n;
	}
	else
	{
		cout<<ceil(1.0*p/n)<<" ";
		if(p%n==0)
			cout<<1;
		else
			cout<<n-p%n+1;
	}
	
			
}
