#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],f=0,ans=0,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==f)
		{
			f=n*m-i+1;
		}
	}
	if(f%n==0) 
	{
		sum=f/n;
		if(sum%2==1)
		{
			ans=n;
		}
		else
		{
			ans=1;
		}
	}
	else
	{
		sum=f/n+1;
		if(sum%2==1)
		{
			ans=f%n; 
		}
		else
		{
			ans=n-f%n+1;
		}
	}
	cout<<sum<<" "<<ans;
}