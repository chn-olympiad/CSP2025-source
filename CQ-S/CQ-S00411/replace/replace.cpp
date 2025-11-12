#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
int n,q,xt[200005],cs[200005];
ll ds1=29,ds2=31;
string s1,s2,t1,t2;
map<pair<ll,ll>,ll> mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		ll sum1=0,sum2=0;
		for(int j=0;j<s1.size();j++)
		{
			sum1=(sum1*ds1+s1[j]-'a'+1)%mod;
			sum2=(sum2*ds2+s2[j]-'a'+1)%mod;
		}
		mp[{sum1,sum2}]++;
	}
	while(q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<'\n';
			continue;
		}
		int xtq=0,xth=0;
		ll ans=0;
		for(;xtq<t1.size();xtq++)
		{
			if(t1[xtq]!=t2[xtq])
			{
				break;
			}
		}
		for(xth=t1.size()-1;xth>0;xth--)
		{
			if(t1[xth]!=t2[xth])
			{
				break;
			}
		}
		for(int i=0;i<=xtq;i++)
		{
			ll sum1=0,sum2=0;
			for(int j=i;j<t1.size();j++)
			{
				sum1=(sum1*ds1+t1[j]-'a'+1)%mod;
				sum2=(sum2*ds2+t2[j]-'a'+1)%mod;
				if(j>=xth)
				{
					ans+=mp[{sum1,sum2}];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
