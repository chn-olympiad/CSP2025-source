#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5100,p=998244353;
ll a[N];
struct nd{ll l,b[N];nd(){l=1;memset(b,0,sizeof b);};};
void add(nd &s)
{
	ll l=s.l;s.b[1]++;
	for(ll i=1;i<=l;i++)if(s.b[i]==2)s.b[i]=0,s.b[i+1]++;
	if(s.b[l+1]==1)l++;
	if(s.b[l+1]==2)s.b[++l]=0,s.b[++l]=1;
	s.l=l;
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(a,0,sizeof a);
	ll n;scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	ll ans=0;nd s;
	for(nd s;s.l<=n;a)
	{
		ll mx=0,v=0;
		for(ll i=1;i<=n;i++)if(s.b[i]==1)
			mx=max(mx,a[i]),v+=a[i];
		if(v>mx*2)ans=(ans+1)%p;
		add(s);
	}
	printf("%lld\n",ans);
	return 0;
}
