#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int N=502,mod=998244353;
int n,m,cnt[N],fac[N],dp[N][N][N];
char s[N];
bool vis[N][N][N];
void add(int&x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int dfs(int x,int y,int z)
{
	int a,b;
	if (x==n)
	{
		if (y>=m&&!z) return 1;
		return 0;
	}
	if (z<0) return 0;
	if (vis[x][y][z]) return dp[x][y][z];
	vis[x][y][z]=1;
	a=x-y;
	b=max(cnt[a+1]-z+1,0);
	if (b) dp[x][y][z]=(long long)dfs(x+1,y+s[x]-'0',z-1)*b%mod;
	add(dp[x][y][z],dfs(x+1,y,z));
	if (b) add(dp[x][y][z],mod-(long long)dfs(x+1,y,z-1)*b%mod);
	return dp[x][y][z];
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,c,ans;
	scanf("%d%d%s",&n,&m,s);
	for (i=0;i<n;i++)
	{
		scanf("%d",&c);
		cnt[c]++;
	}
	for (i=n-1;i>=0;i--) cnt[i]+=cnt[i+1];
	fac[0]=1;
	for (i=1;i<=n;i++) fac[i]=(long long)fac[i-1]*i%mod;
	ans=0;
	for (i=0;i<=n;i++) ans=(ans+(long long)dfs(0,0,i)*fac[n-i]%mod)%mod;
	printf("%d",ans);
	return 0;
}
/*
3 2
101
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
