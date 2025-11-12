#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,y,x) for(int i=(y);i>=(x);i--)
bool memst;
namespace cyzz
{
	#define N 505
	#define mod 998244353
	inline void Add(int &x,int y){x+=y;(x>=mod)&&(x-=mod);}
	int n,m,a[N],c[N];
	namespace solve1
	{
		int f[1<<18][20];
		void solve()
		{
			f[0][0]=1;
			rep(s,0,(1<<n)-2)
			{
				int x=__builtin_popcount(s);
				rep(i,0,x) if(f[s][i])
				{
					rep(j,0,n-1) if(!(s>>j&1))
					{
						int flag=a[x]&(x-i<c[j]);
						Add(f[s|(1<<j)][i+flag],f[s][i]);
					}
				}
			}
			int ans=0;
			rep(i,m,n) Add(ans,f[(1<<n)-1][i]);
			cout<<ans;
		}
	}
	namespace solve2
	{
		int f[N][N],suf[N];
		void solve()
		{
			int cnt=0;rep(i,0,n-1) cnt+=!a[i];
			per(i,n,1) suf[i]=suf[i+1]+a[i-1];
			sort(c,c+n);f[n+1][0]=1;
			per(i,n,1) rep(j,0,min(cnt,n-i+1))
			{
				if(j) Add(f[i][j],1ll*f[i+1][j-1]*(cnt-j+1)%mod);
				if(suf[c[i-1]+1]-(n-i-j)>=0) Add(f[i][j],1ll*f[i+1][j]*(suf[c[i-1]+1]-(n-i-j))%mod);
			}
			int ans=1;
			rep(i,1,n) ans=1ll*ans*i%mod;
			Add(ans,mod-f[1][cnt]);
			cout<<ans;
		}
	}
	namespace solve3
	{
		void solve()
		{
			int flag=1;
			rep(i,0,n-1) flag&=(a[i]&(!!c[i]));
			if(flag)
			{
				int ans=1;
				rep(i,1,n) ans=1ll*ans*i%mod;
				printf("%d",ans);
			}
			else printf("0");
		}
	}
	void MAIN()
	{
		cin>>n>>m;
		string s;cin>>s;
		rep(i,0,n-1) a[i]=s[i]-'0';
		rep(i,0,n-1) cin>>c[i];
		if(m==1) solve2::solve();
		else if(m==n) solve3::solve();
		else solve1::solve();
	}
}bool memed;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cyzz::MAIN();
	debug("%.2lfms %.2lfMB",1.0*clock()/CLOCKS_PER_SEC/1000,
		abs(&memst-&memed)/1024./1024);
}
