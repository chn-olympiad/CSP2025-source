#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	bool ia=1,ib=1;
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1)
			ia=0;
		if(a[i]>1)
			ib=0;
	}
	if(ia)
	{
		printf("%lld",n/2);
		return 0;
	}
	if(ib)
	{
		ll ans=0,cnt=0;
		if(k==0)
		{
			for(ll i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
					if(cnt)
					{
						ans+=cnt/2;
						cnt=0;
					}
				}
				else
					cnt++;
			}
		}
		else if(k==1)
		{
			for(ll i=1;i<=n;i++)
				if(a[i]==1)
					ans++;
		}
		ans+=cnt/2;
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
/*
0_fen_qiu_tiao 
*/
