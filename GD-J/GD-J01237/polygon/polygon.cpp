#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const int MOD=998244353;
bool te=true;
int n,mx,sum;
long long ans;
int a[MAXN],b[MAXN];
long long c[MAXN][MAXN];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void dfs(int i,int sum,int mx)
{
	if(i>=3&&sum>mx*2) ans=(ans+1)%MOD;
	if(i>n) return ;
	for(int j=b[i-1]+1;j<=n;j++)
	{
		b[i]=j;
		dfs(i+1,sum+a[j],max(mx,a[j]));
		b[i]=0;
	}
}
void work()
{
	c[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
		}
	}
	long long sum=0;
	for(int i=3;i<=n;i++)
	{
		sum=(sum+c[n][i])%MOD;
	}
	printf("%lld",sum);
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		mx=max(mx,a[i]);
		sum+=a[i];
		if(a[i]!=1)
		{
			te=false;
		}
	}
	if(n==3)
	{
		if(sum>mx*2) printf("1");
		else printf("0");
		return 0;
	}
	if(te)
	{
		work();
		return 0;
	}
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}//5 1 2 3 4 5
