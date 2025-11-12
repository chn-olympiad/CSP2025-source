#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,ans;
int main()
{
	freopen("seat.out","r",stdout);
	freopen("seat.in","w",stdin);
	cin>>n>>m>>a[1];
	x=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			ans=n*m-i+1;
			break;
		}
	}
	int cnt=(ans+n-1)/n;
	if(cnt%2==1)
	{
		if(ans%n==0)
		{
			cout<<cnt<<" "<<n;
		}
		else
		{
			cout<<cnt<<" "<<ans%n;
		}
	}
	else
	{
		
		if(ans%n==0)
		{
			cout<<cnt<<" "<<1;
		}
		else
		{
			cout<<cnt<<" "<<n-ans%n+1;
		}
	}
	return 0;
}