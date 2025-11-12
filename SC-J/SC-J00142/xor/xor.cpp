#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=6e5+55,M=2e6+15;
ll f[N],sum[N],last[M];
bool dis[M]; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,a;
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		sum[i]=sum[i-1]^a;
//		cout<<sum[i]<<" ";
	}
	for(ll i=1;i<=n;i++)
	{
		if(sum[i]==k) f[i]=1;
		f[i]=max(f[i],f[i-1]);
		if(dis[k^sum[i]])
		{
			f[i]=max(f[i],last[k^sum[i]]+1);
		}
		last[sum[i]]=max(last[sum[i]],f[i]);
		dis[sum[i]]=1;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ans=max(ans,f[i]);
	}
	printf("%lld\n",ans);
	return 0;
} 
/*
4 0
2 1 0 3
%%%xiangxiyu tql%%
%%%xiongzhifei tql%%
%%%xuxuanhao tql%%%
 */