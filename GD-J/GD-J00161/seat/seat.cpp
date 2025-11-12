#include<bits/stdc++.h>
using namespace std;
long long n,sum,m,a[1000005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+2,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[1]>=a[i])
		{
			sum=m*n-i+1;
			break;
		}
	}
	int x=sum/n;
	if(sum%n==0)
	{
		cout<<x<<" ";
		if(x%2==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n;
		}
		return 0;
		
	}
	else
	{
		cout<<x+1<<" ";
		x+=1;
	}
	if(x%2==0)
	{
		cout<<n-sum%n+1;
	}
	else
	{ 
		cout<<sum%n;
	}
	return 0;
}
