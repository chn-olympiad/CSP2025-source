#include<cstdio>
using namespace std;
const long long Mod=998244353;
const int N=5e2+10;
int n,m,cnt,tans,c[N],val[N],vis[N];
long long ans;
char s[N];
int dfs(int step)
{
	if(step>=n+1)
	{
		tans=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[val[i]] || s[i]=='0')
			{
				cnt++;
			}		
			else if(s[i]=='1')
			{
				tans++;
			}
		}
		if(tans>=m)
		{
			ans++;
			ans%=Mod;
		}
		return 0;	
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			val[step]=i;
			dfs(step+1);
			vis[i]=0;
			val[step]=0;
		}
	}
	return 0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
