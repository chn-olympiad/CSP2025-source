#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
const int mod=998244353;
const int maxn=509;
int fac[maxn];
char s[maxn];
int c[maxn];
int n,m;
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')return false;
	}
	return true;
}
int p[maxn];
bool vis[maxn];
int ans;
void dfs(int k)
{
	if(k==n+1)
	{
		int now=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||now>=c[p[i]])
			{
				now++;
			}
		}
		if(n-now>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		p[k]=i;
		vis[i]=true;
		dfs(k+1);
		vis[i]=false;
		p[k]=i;
	}
}
void solve1()
{
	dfs(1);
	printf("%d\n",ans);
}
int f[maxn];
void solve2()
{
	ans=1;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')tot++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i-c[i]<=0)
		{
			cnt++;
			//ans
		}
		ans=1ll*ans*(i-c[i])%mod;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		fac[i]=1ll*fac[i-1]*i%mod;
	}
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	sort(c+1,c+1+n);
	if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||c[i]==0)
			{
				printf("0\n");
				return 0;
			}
		}
		printf("%d\n",fac[n]);
		return 0;
	}
	else if(m==1)
	{
		solve2();
	}
	else
	{
		
		solve1();
	}
	return 0;
}

