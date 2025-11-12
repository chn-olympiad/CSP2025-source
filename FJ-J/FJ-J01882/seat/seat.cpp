#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[102],sum=1,sum1=0,sum2=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++)
	{
		if(a[1]<=a[i])
		{
			sum++;
		}
	}
	sum1=sum/n;
	if(sum1%2==0&&sum%n==0)
	{
		cout<<sum1<<' '<<1;
	}
	if (sum1%2!=0&&sum%n!=0)
	{
		sum2=sum%n;
		cout<<sum1+1<<' '<<n-sum2+1;
	}
	if (sum1%2==0&&sum%n!=0)
	{
		sum2=sum%n;
		cout<<sum1+1<<' '<<sum2;
	}
	if(sum1%2!=0&&sum%n==0)
	{
		cout<<sum1<<' '<<n;
	}
	return 0;
}
