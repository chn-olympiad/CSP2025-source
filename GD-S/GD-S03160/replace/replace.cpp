#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll unsigned long long
#define eb emplace_back
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,y,x) for(int i=(y);i>=(x);i--)
bool memst;
namespace cyzz
{
	#define N 200005
	#define M 5000005
	int n,q;
	string a[N],b[N];
	string s[N],t[N];
	namespace solve1
	{
		#define base 2333
		ll bas[M];
		void init()
		{
			bas[0]=1;
			rep(i,1,M-5)
				bas[i]=bas[i-1]*base;
		}
		map<pair<ll,ll>,int>mp;
		void getH(string &a,string &b)
		{
			ll ret1=0,ret2=0;
			for(char c:a) ret1=ret1*base+(c-'a'+1);
			for(char c:b) ret2=ret2*base+(c-'a'+1);
			mp[{ret1,ret2}]++;
		}
		ll calc(string &a,string &b)
		{
			int n=a.size();
			int pre=n,suf=-1;
			rep(i,0,n-1) if(a[i]!=b[i]) {pre=i;break;}
			per(i,n-1,0) if(a[i]!=b[i]) {suf=i;break;}
			ll ret=0;
			rep(i,0,min(pre,n-1))
			{
				ll ret1=0,ret2=0;
				rep(j,i,n-1)
				{
					ret1=ret1*base+(a[j]-'a'+1);
					ret2=ret2*base+(b[j]-'a'+1);
					if(j>=suf)
					{
						if(mp.find(make_pair(ret1,ret2))!=mp.end()) 
							ret+=mp[{ret1,ret2}];
					}
				}
			}
			return ret;
		}
		void solve()
		{
			rep(i,1,n) getH(a[i],b[i]);
			rep(i,1,q) cout<<calc(s[i],t[i])<<'\n';
		}
	}
	namespace solve2
	{
		void solve()
		{

		}
	}
	bool check(string &a)
	{
		int cnt=0,flag=1;
		for(char c:a)
		{
			if(c!='a'&&c!='b') flag=0;
			if(c=='b') cnt++;
		}
		return flag&(cnt<=1);
	}
	void MAIN()
	{
		cin>>n>>q;bool flag=1;
		rep(i,1,n) cin>>a[i]>>b[i],flag&=check(a[i])&check(b[i]);
		rep(i,1,q) cin>>s[i]>>t[i],flag&=check(s[i])&check(t[i]);
		// if(flag) solve2::solve();
		solve1::solve();
	}
}bool memed;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cyzz::MAIN();
	debug("%.2lfms %.2lfMB",1.0*clock()/CLOCKS_PER_SEC/1000,
		abs(&memst-&memed)/1024./1024);
}
