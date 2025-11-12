#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,sum[510],c[510],f[510][510],cnt[510],fac[510],p[510];
string s;
int check()
{
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>=c[p[i]]) cnt++;
		else
		{
			if(s[i]=='0') cnt++;
			else ans++;
		}
	}
	return ans>=m;
}
void solve1()
{
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0;
	do
	{
		ans+=check();
	}
	while(next_permutation(p+1,p+n+1));
	cout<<ans;
}
void solve2()
{
	for(int i=n;~i;i--) sum[i]=sum[i+1]+cnt[i];
	int now=0;
	int ret=0;
	int nret=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
//			cout<<"!:"<<sum[i]-now<<'\n';
			ret+=nret*sum[i]%mod*fac[n-now-1]%mod;
			nret*=max(n-sum[i]-now,0ll);
			nret%=mod;
//			cout<<"nret="<<nret<<'\n';
			now++;
			ret%=mod;
		}
//		cout<<"ret="<<ret<<'\n';
	}
	cout<<ret;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i],cnt[c[i]]++;
	if(n<=11) solve1();
	else if(m==1) solve2();
	else cout<<0;
}
