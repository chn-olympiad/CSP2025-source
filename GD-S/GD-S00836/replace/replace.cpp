#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int> 
using namespace std;
const int maxn=1e6+10,mod=1e9+7;
int n,q,l,suml,h0,h1,ans;
string s0,s1;
int ll[maxn],rr[maxn],kk[maxn],cnt[maxn];
unordered_map<int,int> mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s0>>s1,h0=h1=0,l=s0.size(),suml+=l;
		for(int j=0;j<l;j++) h0=(h0*131+(s0[j]-'a'+1))%mod,h1=(h1*131+(s1[j]-'a'+1))%mod;
		mp[h0*mod+h1]++;
		int p0=0,p1=0;
		for(int j=0;j<l;j++)
		{
			if(s0[j]=='b') p0=j;
			if(s1[j]=='b') p1=j;
		}
		ll[i]=min(p0,p1)-1,rr[i]=n-max(p0,p1),kk[i]=p1-p0;
//		cnt[p1-p0+(int)2e5]++;
	}
	if(suml>=1e6)
	{
		for(int i=1;i<=q;i++)
		{
			cin>>s0>>s1,l=s0.size();
			int p0=0,p1=0;
			for(int j=0;j<l;j++)
			{
				if(s0[j]=='b') p0=j;
				if(s1[j]=='b') p1=j;
			}
			for(int j=1;j<=n;j++)
				if(min(p0,p1)-1>=ll[j]&&n-max(p0,p1)>=rr[j]&&kk[j]==p1-p0) ans++;
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s0>>s1,l=s0.size(),ans=0;
		for(int j=0;j<l;j++)
		{
			h0=h1=0;
			for(int k=j;k<l;k++)
			{
				h0=(h0*131+(s0[k]-'a'+1))%mod,h1=(h1*131+(s1[k]-'a'+1))%mod;
				if(k==l-1||s0[k+1]==s1[k+1]) ans+=mp[h0*mod+h1];
			}
			if(s0[j]!=s1[j]) break;
		}
		cout<<ans<<endl;
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
