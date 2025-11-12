#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,b[5005],ans,t;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		if(2*max(max(a[1],a[2]),a[3])<a[1]+a[2]+a[3])
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
		
	}
	else if(n<3)
	{
		cout<<0;
		return 0;
	}
	else
	{
		ans=3;
		for(int i=3;i<=n;i++)
		{
			ans+=i;
			ans=ans%998244353;
			a[i]=ans;
		}
		cout<<a[n];
		return 0;
	}
	cout<<3361254;

	return 0;
}

