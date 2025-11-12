#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll M=505,mod=998244353;
ll n,m,c[M],ans,jie[M];
string s;
bool f[M];
void dfs(ll k,ll ac,ll wa)
{
	if(k==n+1)
	{
		if(ac>=m) ans=(ans+1)%mod;
		return;
	}
	if(ac>=m)
	{
		ans=(ans+jie[n-k+1])%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			if(wa>=c[i])
			{
				dfs(k+1,ac,wa+1);
			}
			else
			{
				if(s[k-1]=='1')
				{
					dfs(k+1,ac+1,wa);
				}
				else dfs(k+1,ac,wa+1);
			}
			f[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	jie[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		jie[i]=jie[i-1]*i%mod;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

