#include<bits/stdc++.h>

namespace LHY
{

using namespace std;

#define rep(i,s,t) for(int i=s;i<=t;++i)
#define per(i,t,s) for(int i=t;i>=s;--i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mtp make_tuple
#define fi first
#define se second
#define debug cerr<<"now is:"<<__FUNCTION__<<" on line "<<__LINE__<<'\n'

using LL = long long;
using LD = long double;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;
using vi = vector<int>;

const int N=510,mod=998244353;

int n,m;

string s;

int c[N],val[N];

namespace Solve1
{
	int dp[1<<19][21];
	
	/*
	S out of i 
	*/
	
	void add(int& x,int y)
	{
		x=(x+y>=mod?x+y-mod:x+y);
	}
	
	void solve()
	{
		rep(i,0,n-1) cin>>c[i];	
		
		s=" "+s;
		
		rep(i,1,n)
		{
			if(s[i]=='0') val[i]=0;
			else val[i]=1;
		}
		
		dp[0][0]=1;
		
		rep(S,1,(1<<n)-1)
		{
			rep(k,0,n)
			{
				rep(i,0,n-1)
				{
					if(S&(1<<i))
					{
						int d=0;
						
						if(val[__builtin_popcount(S)]==0) d=1;
						if(k>=c[i]) d=1;
						add(dp[S][k+d],dp[S-(1<<i)][k]);
					}
				}
			}
//			rep(i,0,n)
//			{
//				cerr<<S<<' '<<i<<' '<<dp[S][i]<<'\n';
//			}
		}
		
		int ans=0;
		
		rep(i,0,n-m)
		{
			add(ans,dp[(1<<n)-1][i]);
		}
		
		cout<<ans<<'\n';
	}
}

void solve_all()
{
	cin>>n>>m>>s;
	
	if(n<=18)
	{
		Solve1::solve();
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(false),cin.tie(nullptr);
	
	solve_all();
	
	return 0;
}

}

int main()
{
	return LHY::main();
}
