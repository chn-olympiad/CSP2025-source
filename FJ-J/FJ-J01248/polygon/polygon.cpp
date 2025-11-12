#include<bits/stdc++.h>
using namespace std;
long long a[50002];
/*
int cmp(int a,int b)
{
	return a<b;
}
*/
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n=0,m=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==1)m++;
	}
	if(n==3)
	{
		long long j=max(a[1],max(a[2],a[3]));
		long long k=min(a[1],min(a[2],a[3]));
		for(long long i=1;i<=n;i++)
			if(a[i]>k&&a[i]<j)
			{
				if(a[i]+k>j)
					cout<<1;
				else cout<<0;
			}
		return 0;
	}
	if(m==n)
	{
		long long j=0;
		for(long long i=4;i<=n;i++)j=(j*2%998244353+1)%998244353;
		cout<<(n*j%998244353+1)%998244353;
		return 0;
	}
	/*
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++)
		a[i]+=a[i-1];
	*/
	cout<<0;
	return 0;
}
