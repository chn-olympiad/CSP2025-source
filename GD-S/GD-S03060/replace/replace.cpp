#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e6+5,p=61,mod=998244353;
unordered_map<ll,int>flg[N];
set<int>st;
ll pw[N];
void solve()
{
	pw[0]=1;
	for(int i=1;i<N;i++)pw[i]=(pw[i-1]*p)%mod;
	int n,q;
	cin>>n>>q;
	string s,t;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>t;
		ll hsh1=0,hsh2=0;
		for(char c:s)hsh1=(hsh1*p+c-'a'+1)%mod;
		for(char c:t)hsh2=(hsh2*p+c-'a'+1)%mod;
		flg[s.size()][hsh1<<31|hsh2]++,st.insert(s.size());
	}
	for(;q;q--)
	{
		cin>>s>>t;
		int n=s.size();
		s=' '+s,t=' '+t;
		int l=0,r;
		for(int i=1;i<=n;i++)
			if(s[i]!=t[i])l=(l==0?i:l),r=i;
		int ans=0;
		for(int len:st)
		{
			if(len>n)break;
			ll hsh1=0,hsh2=0;
			for(int i=1;i<=len;i++)
			{
				hsh1=(hsh1*p+s[i]-'a'+1)%mod;
				hsh2=(hsh2*p+t[i]-'a'+1)%mod;
			}
			if(1<=l&&len>=r)ans+=flg[len][hsh1<<31|hsh2];
			for(int i=len+1;i<=n;i++)
			{
				hsh1=(hsh1*p-pw[len]*(s[i-len]-'a'+1)%mod+s[i]-'a'+1+mod)%mod;
				hsh2=(hsh2*p-pw[len]*(t[i-len]-'a'+1)%mod+t[i]-'a'+1+mod)%mod;
				if(i-len+1<=l&&i>=r)ans+=flg[len][hsh1<<31|hsh2];
			}
		}
		cout<<ans<<'\n';
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
	for(;T;T--)solve();
	return 0;
}
