#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const ll MOD=998244353;
ll n,m,c[505],fact[505],pos[505],L,ans;
char s[505];
bool b[505];
void dfs(ll d,ll cnt,ll sum)
{
	if(cnt==m)
	{
		ans=(ans+fact[n-(d-1)])%MOD;
		return;
	}
	sum+=pos[d]-pos[d-1]-1;
	for(ll i=1;i<=n;i++)
		if(!b[i])
		{
			b[i]=true;
			bool giveup=(sum>=c[i]);
			if(giveup&&L-d+1<=m-cnt)
			{
				b[i]=false;
				continue;
			}
			dfs(d+1,cnt+!giveup,sum+giveup);
			b[i]=false;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
	sort(c+1,c+n+1);
	fact[0]=1;
	for(ll i=1;i<=n;i++) fact[i]=fact[i-1]*i%MOD;
	for(ll i=1;i<=n;i++)
		if(s[i]=='1') pos[++L]=i;
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
