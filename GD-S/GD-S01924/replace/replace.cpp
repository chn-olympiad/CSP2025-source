#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
using namespace std;
const int B=233,mod=993244853,N=5000010;
int n,q,hs1[N],hs2[N],pw[N];
string s1,s2;
map<pii,int> mp;
int hsh1(int l,int r)
{
	if(l>r) return 0;
	return (hs1[r]-1ll*hs1[l-1]*pw[r-l+1]%mod+mod)%mod;
}
int hsh2(int l,int r)
{
	if(l>r) return 0;
	return (hs2[r]-1ll*hs2[l-1]*pw[r-l+1]%mod+mod)%mod;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		int hs1=0,hs2=0;
		for(int j=0;j<s1.size();j++)
		{
			hs1=(1ll*hs1*B+s1[j])%mod;
			hs2=(1ll*hs2*B+s2[j])%mod;
		}
		mp[mkp(hs1,hs2)]++;
	}
	while(q--)
	{
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			cout<<"0\n";
			continue;
		}
		pw[0]=1;
		for(int i=1;i<=s1.size();i++)
		{
			hs1[i]=(1ll*hs1[i-1]*B+s1[i-1])%mod;
			hs2[i]=(1ll*hs2[i-1]*B+s2[i-1])%mod;
			pw[i]=1ll*pw[i-1]*B%mod;
		}
		int ans=0;
		for(int i=1;i<=s1.size();i++)
		{
			for(int j=i;j<=s1.size();j++)
			{
				if(hsh1(1,i-1)==hsh2(1,i-1)&&hsh1(j+1,n)==hsh2(j+1,n))
				{
					ans+=mp[mkp(hsh1(i,j),hsh2(i,j))];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
