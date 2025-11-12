#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=998244353;
ll n,a[5005],q[5005],cnt;
ll shu(ll a,ll b)
{
	ll tt=1;
	for(int i=a;i>a-b;i--) tt=tt*i;
	for(int i=2;i<=b;i++) tt=tt/i;
	tt=tt*b%N;
	return tt;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
	
	for(int i=3;i<=n;i++)
	{
		ll t=0;
		for(int j=1;j<i;j++)
		{
			t+=a[j];
			if(t>a[i]) q[i]=i;
		}
	}
	for(int i=n;i>=3;i--)
	{
		
		ll t=i-q[i]-1;
		for(int j=1;j<=t;j++)
		{
			cnt=cnt+shu(q[i],j);
			cnt%=N;
		}
		//for(int j=i-1;i>=)
	}
	printf("%lld",cnt);
	
	return 0;
}

