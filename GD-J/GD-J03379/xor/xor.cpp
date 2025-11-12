#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll k,sum[N],maxn[N];
unordered_map<ll,int> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=2;i<=n+1;i++)
	{
		ll x;
		scanf("%lld",&x);
		sum[i]=sum[i-1]^x;
	}
	for(int i=1;i<=n+1;i++)
	{
		int val=mp[sum[i]^k];
		if(val!=0) maxn[i]=max(maxn[i-1],maxn[val]+1);
		else maxn[i]=maxn[i-1];
		mp[sum[i]]=i;
	}
	printf("%lld",maxn[n+1]);
	return 0;
}
