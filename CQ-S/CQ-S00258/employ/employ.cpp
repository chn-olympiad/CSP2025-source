#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,bj[N],mx[N],ans,id[N],f[1<<18][19];
string s;
void dfs(int x)
{
	if(x>n)
	{
		int nw=0;
		for(int i=1;i<=n;i++) if(mx[id[i]]<=nw||!bj[i]) nw++;
		if(n-nw>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++) if(!id[i]) id[i]=x,dfs(x+1),id[i]=0;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) bj[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>mx[i];
	if(n<=10){dfs(1);cout<<ans;return 0;}
	if(n<=18)
	{
		f[0][0]=1;
		for(int i=0;i<(1<<n);i++)
		{
			int nm=0;for(int j=0;j<n;j++) if(i&(1<<j)) nm++;
			for(int k=0;k<=n;k++)
			{
				if(!f[i][k]) continue;
				for(int j=0;j<n;j++)
				{
					if(i&(1<<j)) continue;
					int nw=i|(1<<j);
					if(bj[nm+1]&&mx[j+1]>k) (f[nw][k]+=f[i][k])%=mod;
					else (f[nw][k+1]+=f[i][k])%=mod;
				}
			}
		}
		for(int k=0;k<=n-m;k++) ans+=f[(1<<n)-1][k];cout<<ans;return 0;
	}
	if(n==m)
	{
		for(int i=1;i<=n;i++) if(!mx[i]){cout<<0;return 0;}
		for(int i=1;i<=n;i++) if(!bj[i]){cout<<0;return 0;}
		int nw=1;for(int i=1;i<=n;i++) nw=nw*i%mod;cout<<nw<<'\n';return 0;
	}
	cout<<0;return 0;
	return 0;
}
