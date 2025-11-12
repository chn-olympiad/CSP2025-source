#include<bits/stdc++.h>
using namespace std;
struct FSI
{
	template<typename T>
	FSI& operator >> (T &res)
	{
		res=0;T f=1;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
		while(isdigit(ch)){res=res*10+(ch-'0');ch=getchar();}
		res*=f;
		return *this;
	}
}scan;
const int mod=998244353;
int ans;
int n,m,c[510];
int vis[510],a[510];
char s[510];
bool check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>=c[a[i]]||s[i]=='0') cnt++;
		if(n-cnt<m) return 0;
	}
	return 1;
}
void dfs(int k)
{
	if(k==n+1)
	{
		if(check()) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		a[k]=i;
		dfs(k+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scan>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scan>>c[i];
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
