#include <iostream>
#include <algorithm>
using namespace std;

//400 pts
//Can I AK?
const int mod=998244353;
int arr[5005];
int sum[10005];
int qpow(long long x,int b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
		{
			ans*=x;
			ans%=mod;
		}
		x*=x;
		x%=mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		maxn=max(maxn,arr[i]);
	}
	sort(arr+1,arr+n+1);
	int ans=0;
	sum[0]=1;
	for(int i=1;i<=n;i++)
	{
		int now=0;
		for(int j=arr[i]+1;j<=maxn*2-arr[i];j++)
		{
			now+=sum[j];
			now%=mod;
		}
		long long mult=qpow(2,n-i);
		for(int j=maxn*2;j>=maxn*2+1-arr[i];j--)
		{
			now+=sum[j]*mult%mod;
			now%=mod;
		}
		for(int j=maxn*2-arr[i];j>=0;j--)
		{
			sum[j+arr[i]]+=sum[j];
			sum[j+arr[i]]%=mod;
		}
		ans+=now;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
