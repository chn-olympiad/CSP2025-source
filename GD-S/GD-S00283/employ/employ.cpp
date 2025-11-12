#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,t[N],c[N],ans;
string s;
bool vis[N];
int read()
{
	int w=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') w=(w<<3)+(w<<1)+c-'0',c=getchar();
	return w*f;
}
void dfs(int dep,int sum,int cnt)
{
	if(dep==n+1)
	{
		if(sum>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	  if(!vis[i])
	  {
	  	vis[i]=1;
	  	if(s[dep]=='1'&&cnt<c[i]) dfs(dep+1,sum+1,0);
	  	else dfs(dep+1,sum,cnt+1);
	  	vis[i]=0;
	  }
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>s;s=" "+s;
	for(int i=1;i<=n;i++) c[i]=read();
	dfs(1,0,0);
	printf("%lld",ans);
}
