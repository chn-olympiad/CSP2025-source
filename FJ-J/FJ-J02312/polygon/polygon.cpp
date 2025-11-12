#include<bits/stdc++.h>
#define N 998244353
using namespace std;
int n,a[5005],pd=1;
long long ans,jc[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)pd=0;
	}
	if(pd)
	{
		jc[0]=1;
		for(int i=1;i<=n;i++)
		{
			jc[i]=1ll*(jc[i-1]*i)%N;
		}
		for(int i=3;i<=n;i++)
		{
			ans=(ans+jc[n]/(jc[n-i]%N*jc[i]%N))%N;
		}
		cout<<ans;
	}
	else if(n==3){
		sort(a+1,a+1+n);
		if(a[1]+a[2]>a[3])
		cout<<1;
		else
		cout<<0;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
