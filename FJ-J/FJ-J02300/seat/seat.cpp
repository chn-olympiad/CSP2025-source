#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int num=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(a[i]>=a[j])
			swap(a[i],a[j]);
		}
	}
	int sum=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num)
		{
			sum=i;
		}
	}
	if(sum%n==0)
	{
		int cnt=sum/n;
		cout<<sum/n<<" ";
		if(cnt%2==0)
		{
			cout<<"1";
		}
		else
		{
			cout<<n;
		}
	}
	if(sum%n!=0)
	{
		int cnt=(sum-sum%n)/n+1;
		cout<<cnt<<" ";
		if(cnt%2==0)
		{
			cout<<m-sum%m+1;
		}
		else
		{
			cout<<sum%m;
		}
	}
	return 0;
}
