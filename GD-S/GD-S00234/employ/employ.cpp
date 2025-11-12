#include<bits/stdc++.h>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _antirep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;

const int N=5e2+5,mod=998244353;

int n,m,ans;
char s[N];
int c[N],f[N];
bool vis[N];

void dfs(int cur,int now)
{
	if(n-now<m) return ; 
	if(cur>n)
	{ 
		if(n-now>=m) ans=(ans+1)%mod;
		return ;
	}
	_rep(i,1,n)
	{
		if(!vis[i])
		{
			f[cur]=i;vis[i]=1; 
			if(s[cur]=='0') dfs(cur+1,now+1);
			else 
			{
				if(now<c[i]) dfs(cur+1,now);
				else dfs(cur+1,now+1);
			} 
			f[cur]=0;vis[i]=0;
		}
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>(s+1);
	_rep(i,1,n) cin>>c[i];
	
	dfs(1,0);
	
	cout<<ans<<"\n";
	return 0;
}
