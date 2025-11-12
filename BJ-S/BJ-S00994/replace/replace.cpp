#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
#define mod 1145142023
ll hsh(basic_string<char>s)
{
	ll ans=0;
	for (ll i=0;i<s.size();i++)
	{
		ans=(ans*30+s[i]-'a'+1)%mod;
	}
	return ans;
}
ll n,q,a[200005],b[200005];
basic_string<char>s,t;
map<ll,ll>mp1,mp2;
int main()
{
	faster;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (ll i=1;i<=n;i++)
	{
		cin>>s>>t;
		a[i]=hsh(s);
		b[i]=hsh(t);
		mp1[a[i]]=i;
		mp2[b[i]]=i;
	}
	while (q--)
	{
		cin>>s>>t;
		ll len=s.size(),l=-1,r,cnt=0;
		for (ll i=0;i<len;i++)
		{
			if (s[i]!=t[i])
			{
				if (l==-1)l=i;
				r=i;
			}
		}
		for (ll i=0;i<=l;i++)
		{
			ll hs=hsh(s.substr(i,r-i+1)),ht=hsh(t.substr(i,r-i+1));
			if (mp1[hs]&&mp1[hs]==mp2[ht])cnt++;
			for (ll j=r+1;j<len;j++)
			{
				hs=(hs*30+s[j]-'a'+1)%mod;
				ht=(ht*30+t[j]-'a'+1)%mod;
				if (mp1[hs]&&mp1[hs]==mp2[ht])cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}//25
