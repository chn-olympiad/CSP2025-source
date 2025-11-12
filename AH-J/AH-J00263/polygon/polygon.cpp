#include<bits/stdc++.h>
using namespace std;
int a[5000];
int sum(int x)
{
	long long sumz=1,sumy=1;
	for(int i=1;i<=x;i++) sumz*=2;
	sumz--;
	sumz-=x;
	for(int i=2;i<x;i++) sumy+=i;
	sumz-=sumy;
	return sumz;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(n<=3)
	{
		int pd=a[1]+a[2]+a[3];
		int pdd=pd-maxn;
		if(pdd>maxn)
		{
			cout<<1<<endl;
		}
		else cout<<0<<endl;
		return 0;
	}
	if(maxn==1)
	{
		long long ans=0;
		ans=sum(n);
		cout<<ans%998244353;
	return 0;
	}
}
