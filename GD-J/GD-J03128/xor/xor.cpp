#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=0;
ll a[500005];
ll k,r=0;
map<ll,ll> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	mp[0]=1;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		r=r^a[i];
		//printf("%lld %lld\n",r,k^r);
		if(mp[k^r]){/*printf("%lld\n",i),*/ans++,r=0,mp.clear(),mp[0]=1;continue;}
		mp[r]=i;
	}
	printf("%lld",ans);
	
	return 0;
}
