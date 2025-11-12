#include <bits/stdc++.h>
using namespace std;
const int MAXN=510,mod=998244353;
int n,m;
char s[MAXN];
int c[MAXN];
int ans,a[MAXN],vis[MAXN];
void dfs(int id,int cnt)
{
	if(cnt>n-m) return;
	if(id==n+1)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1; a[id]=i;
			if(cnt>=c[i]||s[id]=='0') dfs(id+1,cnt+1);
			else dfs(id+1,cnt);
			vis[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m); cin>>s+1;
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	bool fla1=0,fla2=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0') fla1=1;
		if(c[i]==0) fla2=1;
	}
	if(m==n)
	{
		if(fla1||fla2) printf("0");
		else
		{
			ans=1;
			for(int i=1;i<=n;i++)
				ans=1ll*ans*i%mod;
			printf("%d",ans);
		}
		return 0;
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
