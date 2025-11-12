#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inv(x) (fpow(x,mod-2))
using namespace std;
ll pow29[5000005],pow31[5000005];
ll fpow(ll x,ll y)
{
	ll ans=1,l=x;
	while(y)
	{
		if(y&1) ans=ans*l%mod;
		y>>=1;
		l=l*l%mod; 
	}
	return ans;
}
multiset<pair<ll,pair<ll,char> > >s;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,q;
	scanf("%lld%lld",&n,&q);
	pow29[0]=pow31[0]=1;
	for(ll i=1;i<=5000000;i++)
	{
		pow29[i]=pow29[i-1]*29%mod;
		pow31[i]=pow31[i-1]*31%mod;
	}
	for(ll i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		ll l=s1.size();
		s1=" "+s1,s2=" "+s2;
		ll hs11=0,hs21=0;
		ll hs12=0,hs22=0;
		for(ll j=1;j<=l;j++)
		{
			hs11=(hs11+pow29[j-1]*(s1[j]-'a'+1)%mod)%mod;
			hs12=(hs12+pow31[j-1]*(s1[j]-'a'+1)%mod)%mod;
			hs21=(hs21+pow29[j-1]*(s2[j]-'a'+1)%mod)%mod;
			hs22=(hs22+pow31[j-1]*(s2[j]-'a'+1)%mod)%mod;
		}
		ll h1=(hs11-hs21+mod)%mod,h2=(hs12-hs22+mod)%mod;
		s.insert(make_pair(h1,make_pair(h2,s1[1])));
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		ll l=t1.size();
		t1=" "+t1,t2=" "+t2; 
		ll hs11=0,hs21=0;
		ll hs12=0,hs22=0;
		for(ll j=1;j<=l;j++)
		{
			hs11=(hs11+pow29[j-1]*(t1[j]-'a'+1)%mod)%mod;
			hs12=(hs12+pow31[j-1]*(t1[j]-'a'+1)%mod)%mod;
			hs21=(hs21+pow29[j-1]*(t2[j]-'a'+1)%mod)%mod;
			hs22=(hs22+pow31[j-1]*(t2[j]-'a'+1)%mod)%mod;
		}
		ll h1=(hs11-hs21+mod)%mod,h2=(hs12-hs22+mod)%mod;
		ll ans=0;
		for(ll j=1;j<=l;j++)
		{
			ll s1=h1*inv(pow29[j-1])%mod;
			ll s2=h2*inv(pow31[j-1])%mod;
			ans+=s.count(make_pair(s1,make_pair(s2,t1[j])));
		}
		printf("%lld\n",ans);
	}
}
