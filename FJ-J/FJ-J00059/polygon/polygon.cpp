#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
const int mod=998244353;
long long ans;
long long cal(int m)
{
	long long re=1;
	for(int x=m+1;x<=n;x++){
		re%=mod;
		if(n!=m)
		{
			if(x%(n-m)==0)
			re*=(x/(n-m));
		}
		else re*=x;
	}
	return re;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flagA=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)flagA=0;
	}
	if(n<3)cout<<0;
	else if(n==3)
	{
		sort(a+1,a+4);
		if(a[1]+a[2]+a[3]>a[3]*2)cout<<1;
		else cout<<0;
	}
	else{
		if(flagA)
		{
			for(int m=3;m<=n;m++)
			{
				ans+=cal(m);
				ans%=mod;
			}
			cout<<ans;
		}
		else cout<<0;
	}
	return 0;
}

