#include<bits/stdc++.h>
using namespace std;
#define __MY_TEST__ 1
const int N=2e5+5,bse=131,mod=998244353;
int n,q;
string s[3][N],t[3];
int len[N],lcp[N],lcs[N];
int cnt[N],tvec;
map<pair<int,int>,pair<int,int> >mp;
int ch[10000005][26],tot,pos[10000005];
vector<int>vec[N];
int insert(int pos,int u)
{
	if(!ch[pos][u]) ch[pos][u]=++tot;
	return ch[pos][u];
}
signed main()
{
#if __MY_TEST__
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[1][i]>>s[2][i];
		len[i]=s[1][i].size();
		while(lcp[i]<len[i]&&s[1][i][lcp[i]]==s[2][i][lcp[i]]) lcp[i]++;
		while(lcs[i]<len[i]&&s[1][i][len[i]-1-lcs[i]]==s[2][i][len[i]-1-lcs[i]]) lcs[i]++;
		if(lcp[i]==len[i]) continue;
		int hsh1=0,hsh2=0;
		for(int j=lcp[i];j<=len[i]-lcs[i]-1;j++)
		{
			hsh1=(1ll*hsh1*131+s[1][i][j]-'a'+1)%mod;
			hsh2=(1ll*hsh2*131+s[2][i][j]-'a'+1)%mod;
		}
		if(!mp.count(make_pair(hsh1,hsh2)))
		{
			int rt1=++tot,rt2=++tot;
			mp[make_pair(hsh1,hsh2)]=make_pair(rt1,rt2);
		}
		auto rt=mp[make_pair(hsh1,hsh2)];
		int rtp=rt.first,rts=rt.second;
		for(int j=lcp[i]-1;j>=0;j--) rtp=insert(rtp,s[1][i][j]-'a');
		if(!pos[rtp]) pos[rtp]=++tvec;
		vec[pos[rtp]].push_back(i);
		for(int j=len[i]-lcs[i];j<len[i];j++) rts=insert(rts,s[1][i][j]-'a');
		if(!pos[rts]) pos[rts]=++tvec;
		vec[pos[rts]].push_back(i);
		//cerr<<lcp[i]<<' '<<lcs[i]<<' '<<hsh1<<' '<<hsh2<<' '<<rtp<<' '<<rts<<'\n';
	}
	while(q--)
	{
		cin>>t[1]>>t[2];
		int Lcs=0,Lcp=0,Len=t[1].size();
		while(Lcp<Len&&t[1][Lcp]==t[2][Lcp]) Lcp++;
		while(Lcs<Len&&t[1][Len-1-Lcs]==t[2][Len-1-Lcs]) Lcs++;
		int hsh1=0,hsh2=0;
		for(int j=Lcp;j<=Len-Lcs-1;j++)
		{
			hsh1=(1ll*hsh1*131+t[1][j]-'a'+1)%mod;
			hsh2=(1ll*hsh2*131+t[2][j]-'a'+1)%mod;
		}
		if(!mp.count(make_pair(hsh1,hsh2)))
		{
			cout<<0<<'\n';
			continue;
		}
		auto rt=mp[make_pair(hsh1,hsh2)];
		int rtp=rt.first,rts=rt.second,ans=0;
		if(pos[rtp]) for(auto x:vec[pos[rtp]]) cnt[x]++;
		for(int i=Lcp-1;i>=0;i--)
		{
			if(!ch[rtp][t[1][i]-'a']) break;
			rtp=ch[rtp][t[1][i]-'a'];
			if(pos[rtp]) for(auto x:vec[pos[rtp]]) cnt[x]++;
		}
		if(pos[rts]) for(auto x:vec[pos[rts]]) ans+=cnt[x];
		for(int i=Len-Lcs;i<=n;i++)
		{
			if(!ch[rts][t[1][i]-'a']) break;
			rts=ch[rts][t[1][i]-'a'];
			if(pos[rts]) for(auto x:vec[pos[rts]]) ans+=cnt[x];
		}
		cout<<ans<<'\n';
		rtp=rt.first;
		if(pos[rtp]) for(auto x:vec[pos[rtp]]) cnt[x]=0;
		for(int i=Lcp-1;i>=0;i--)
		{
			if(!ch[rtp][t[1][i]-'a']) break;
			rtp=ch[rtp][t[1][i]-'a'];
			if(pos[rtp]) for(auto x:vec[pos[rtp]]) cnt[x]=0;
		}
	}
}

