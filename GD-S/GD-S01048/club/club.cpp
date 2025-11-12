#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,ans;
struct node
{
	ll a,b,c;
}a[N];
void dfs(ll cnta,ll cntb,ll cntc,ll sum,ll step)
{
	if(cnta>n/2||cntb>n/2||cntc>n/2)
		return;
	if(step>n)
	{
		ans=max(ans,sum);
		return;
	}
	dfs(cnta+1,cntb,cntc,sum+a[step].a,step+1);
	dfs(cnta,cntb+1,cntc,sum+a[step].b,step+1);
	dfs(cnta,cntb,cntc+1,sum+a[step].c,step+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
		ans=0;
		dfs(0,0,0,0,1);
		printf("%lld\n",ans);
	}
	return 0;
}

