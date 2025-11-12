#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i(a);i<=(b);++i)
#define req(i,a,b) for(int i(a);i>=(b);--i)
// #define sort stable_sort
using namespace std;
constexpr int bas1=682739,mod1=998'244'853,bas2=1145141,mod2=1'000'000'009;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n,q; cin>>n>>q;
	vector<array<string,2>> a(n+1);
	if(n<=1000)
	{
		vector<int> pw1(1000001,1),pw2(1000001,1);
		rep(i,1,1000000) pw1[i]=pw1[i-1]*bas1%mod1,pw2[i]=pw2[i-1]*bas2%mod2;
		vector<array<vector<int>,2>> ha1(n+1),ha2(n+1);
		vector<array<int,2>> sz(n+1);
		rep(i,1,n)
		{
			cin>>a[i][0]>>a[i][1];
			sz[i][0]=a[i][0].size(),sz[i][1]=a[i][1].size();
			a[i][0]=' '+a[i][0],a[i][1]=' '+a[i][1];
			ha1[i][0].resize(a[i][0].size());
			ha2[i][0].resize(a[i][0].size());
			rep(j,1,(int)a[i][0].size()-1)
			{
				ha1[i][0][j]=(ha1[i][0][j-1]*bas1+a[i][0][j])%mod1;
				ha2[i][0][j]=(ha2[i][0][j-1]*bas2+a[i][0][j])%mod2;
			}
			ha1[i][1].resize(a[i][1].size());
			ha2[i][1].resize(a[i][1].size());
			rep(j,1,(int)a[i][1].size()-1)
			{
				ha1[i][1][j]=(ha1[i][1][j-1]*bas1+a[i][1][j])%mod1;
				ha2[i][1][j]=(ha2[i][1][j-1]*bas2+a[i][1][j])%mod2;
			}
		}
		auto query=[&](int i,int t,int l,int r,int tp)->int
		{
			if(tp==1) return (ha1[i][t][r]-ha1[i][t][l-1]*pw1[r-l+1]%mod1+mod1)%mod1;
			return (ha2[i][t][r]-ha2[i][t][l-1]*pw2[r-l+1]%mod2+mod2)%mod2;
		};
		while(q--)
		{
			string s,t; cin>>s>>t;
			int m=s.size(); s=' '+s,t=' '+t;
			vector<int> ha1s(m+1),ha2s(m+1),ha1t(m+1),ha2t(m+1);
			rep(i,1,m) ha1s[i]=(ha1s[i-1]*bas1+s[i])%mod1,ha2s[i]=(ha2s[i-1]*bas2+s[i])%mod2;
			rep(i,1,m) ha1t[i]=(ha1t[i-1]*bas1+t[i])%mod1,ha2t[i]=(ha2t[i-1]*bas2+t[i])%mod2;
			auto querys=[&](int l,int r,int tp)->int
			{
				if(tp==1) return (ha1s[r]-ha1s[l-1]*pw1[r-l+1]%mod1+mod1)%mod1;
				return (ha2s[r]-ha2s[l-1]*pw2[r-l+1]%mod2+mod2)%mod2;
			};
			auto queryt=[&](int l,int r,int tp)->int
			{
				if(tp==1) return (ha1t[r]-ha1t[l-1]*pw1[r-l+1]%mod1+mod1)%mod1;
				return (ha2t[r]-ha2t[l-1]*pw2[r-l+1]%mod2+mod2)%mod2;
			};
			int ans=0;
			rep(i,1,m)
			{
				rep(j,1,n)
				{
					if(i+sz[j][0]-1>m)continue;
					int l=i,r=i+sz[j][0]-1;
					if(querys(l,r,1)!=query(j,0,1,sz[j][0],1)||
							querys(l,r,2)!=query(j,0,1,sz[j][0],2)) continue;
					int p1=querys(1,l-1,1);
					int p2=query(j,1,1,sz[j][1],1);
					int p3=querys(r+1,m,1);
					int p=p1*pw1[m-l+1]%mod1+p2*pw1[m-r]%mod1+p3; p%=mod1;
					int p11=querys(1,l-1,2);
					int p21=query(j,1,1,sz[j][1],2);
					int p31=querys(r+1,m,2);
					int P=p11*pw2[m-l+1]%mod2+p21*pw2[m-r]%mod2+p31; P%=mod2;
					if(p==queryt(1,m,1)&&P==queryt(1,m,2))++ans;
				}
			}
			cout<<ans<<'\n';
		}exit(0);
	}
	vector<vector<pair<int,int>>> anss(2000001);
	rep(i,1,n)
	{
		cin>>a[i][0]>>a[i][1],a[i][0]=' '+a[i][0],a[i][1]=' '+a[i][1];
		int pos1=0,sz=a[i][0].size(),pos2=0;
		rep(j,1,sz)if(a[i][0][j]=='b')pos1=j;
		rep(j,1,sz)if(a[i][1][j]=='b')pos2=j;
		anss[pos2-pos1+1000000].emplace_back(min(pos1,pos2)-1,sz-max(pos1,pos2));
	}
	while(q--)
	{
		string s,t;cin>>s>>t;
		int pos1=0,sz=s.size(),pos2=0;
		rep(j,1,sz)if(s[j]=='b')pos1=j;
		rep(j,1,sz)if(t[j]=='b')pos2=j;
		auto &all=anss[pos2-pos1+1000000];
		int FR=min(pos1,pos2)-1,BK=sz-max(pos1,pos2);
		int ans=0;
		for(auto [fr,bk]:all)ans+=fr<=FR&&bk<=BK;
		cout<<ans<<'\n';
	}
	return 0;
}
