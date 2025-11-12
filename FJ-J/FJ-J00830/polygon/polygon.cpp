#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010];
long long sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=2)
	{
		cout<<0;
	}
	else if(n==3)
	{
		if((a[1]+a[2])>a[3])
			cout<<1;
		else
			cout<<0;
	}
	else
	{
		long long sum=1,l;
		long long a=n+(n*(n-1))/2+1;
		a%=998244353;
		for(int i=1;i<=n;i++)
		{
			sum*=2;
			sum%=998244353;
		}
		cout<<sum<<endl;
		if(sum>=a)
			cout<<sum-a;
		else
			cout<<998244353+sum-a;
		
	}
	return 0;
}

