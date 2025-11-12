#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k,a[10000];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0) 
	{
		cout<<0;
		return 0;
	}
	ll sum=0,ans=0;
	if(n<=10&&k<=1) 
	{
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			if(sum==k) ans++,sum=0;
		}
		cout<<ans;
		return 0;
	}
	if(n<=100&&k<=1)
	{
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			if(sum==k) ans++,sum=0;
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 