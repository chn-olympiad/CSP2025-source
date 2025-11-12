#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,Mod=998244353,inf=1e9+10;
int n,m,f[N],p[N],nw[N],ans;
char s[N];
bool st[N];
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1) res*=x,res%=Mod;
		x*=x,x%=Mod,y>>=1;
	}
	return res;
}
void dfs(int d)
{
	if(d==n)
	{
		for(int i=1;i<=n;i++) nw[i]=f[p[i]];
		int cnt=0;
		for(int i=1;i<=n;i++) if(s[i]==1&&nw[i]>(i-cnt-1)) cnt++;
//		for(int i=1;i<=n;i++) cout<<nw[i]<<' ';
//		cout<<'\n'<<cnt<<'\n'; 
		if(cnt>=m) ans++;
	}
	else for(int i=1;i<=n;i++) if(!st[i]) p[d+1]=i,st[i]=1,dfs(d+1),st[i]=0;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>(s+1);
	bool flag=1;
	for(int i=1;i<=n;i++) cin>>f[i];
	for(int i=1;i<=n;i++) s[i]-='0',flag&=s[i];
	if(m==n)
	{
		for(int i=1;i<=n;i++) if(!s[i]||!f[i]) 
		{
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++) ans*=i,ans%=Mod;
		cout<<ans;
		return 0;
	}
	else if(n<=18) dfs(0);
	cout<<ans;
	return 0;
}