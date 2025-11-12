#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10,M=2e5+10,base=131,mod=1e9+7,mod2=998244353;
int n,q,inv[N];
unordered_map<int,int> mp;
vector<pair<string,string>> s[M];
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
int qpow2(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=1ll*res*a%mod2;
		a=1ll*a*a%mod2,b>>=1;
	}
	return res;
}
int hs(string s)
{
	int res=0;
	for(char c:s)res=(1ll*res*base+c)%mod;
	return res;
}
int hs2(string s)
{
	int res=0;
	for(char c:s)res=(1ll*res*base+c)%mod2;
	return res;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int inv=qpow(base,mod-2);
	int inv2=qpow2(base,mod2-2);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	int cnt=0;
	for(int i=1; i<=n; i++)
	{
		string a,b;
		int x;
		cin>>a>>b;
		int p=(hs(b)-hs(a)+mod)%mod;
		if(!mp.count(p))mp[p]=++cnt,x=cnt;
		else x=mp[p];
		s[x].emplace_back(a,b);
	}
	for(int t=1; t<=q; t++)
	{
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<"0\n";
			continue;
		}
		int p=(hs(b)-hs(a)+mod)%mod,r=(hs2(b)-hs2(a)+mod2)%mod2,ans=0;
		for(int i=0; i<a.size(); i++)
		{
			if(mp.count(p))
			{
				int x=mp[p];
				for(auto y:s[x])
				{
					int k=(hs2(y.second)-hs2(y.first)+mod2)%mod2;
					if(a.find(y.first)!=-1&&b.find(y.second)!=-1&&k==r)ans++;
				}
			}
			p=1ll*p*inv%mod,r=1ll*r*inv2%mod2;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
