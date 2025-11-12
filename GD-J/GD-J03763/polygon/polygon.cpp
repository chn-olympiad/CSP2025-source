#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[5010];
int maxx;
long long sum,ans;
long long mod=998244353;
bool flag=1;
long long C(int x,int y)
{
	long long j=1,sum=1;
	for(long long i=x;i>=x-y+1;i--)
	{
		if(j>y)
			sum=(sum*i)%mod;
		else
			sum=sum*i;
		while(j<=y&&sum%j==0)
			sum=sum/j,j++;
		if(j>y)
			sum=sum%mod;
//		cout<<sum<<'\n';
	}
	while(j<=y)
		sum=sum/j,j++;
//	cout<<'#'<<sum<<'\n';
	return sum%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			flag=0;
	}
	if(flag)
	{
		for(int i=3;i<n;i++)
			ans=(ans+C(n,min(n-i,i)))%mod;
		cout<<(ans+1)%mod;
		return 0;
	}
	for(long long i=0;i<=(1<<n)-1;i++)
	{
		sum=maxx=0;
		for(int j=1;j<=n;j++)
			if((i>>(j-1))&1)
				sum+=a[j],maxx=max(maxx,a[j]);
		ans=(ans+(sum>maxx*2))%mod;
	}
	cout<<ans;
	return 0;
}
