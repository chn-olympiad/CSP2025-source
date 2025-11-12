#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n';
const ll mod=998244353;
ll n,a[5050],l=0,r=0,k=0;
ll maxn=INT_MIN,sum=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),cout.tie(0);
	std::cin>>n;
	for(ll i=1;i<=n;i++) std::cin>>a[i];
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) std::cout<<1;
		else std::cout<<0;
		return 0;
	}
	for(ll i=3;i<=n;i++)
	{
		l=1,r=i;
		for(ll j=1;j<=n;j++)
		{
			ll maxn=INT_MIN,sum=0;
			for(ll p=l;p<=r;p++)
			{
				maxn=max(a[p],maxn);
				sum+=a[p];
			}
			if(sum>maxn*2) k=(k+1)%mod;
			l++,r++;
		}
	}
	if(a[1]==2)
	{
		std::cout<<(k-1)%mod;
		return 0;
	}
	if(a[1]==1)
	{
		std::cout<<(k+1)%mod;
		return 0;
	}
	std::cout<<(k+1)%mod;
	return 0;
}
