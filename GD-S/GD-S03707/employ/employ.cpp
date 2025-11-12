#include<cstdio>
#define ll long long
using namespace std;
const int N=505;
const ll Mod=998244353;
int n,m,c[N],wz[N];
bool bz[N];
char s[N];
ll ans,f[2][N][N],qz[N][N];
void dfs(int x,int num)
{
	if(m-num>n-x+1) return; 
	if(num>=m)
	{
		ll tmp=1;
		for(int i=x;i<=n;i++)
			tmp=(ll)tmp*(i-x+1)%Mod;
		ans=(ans+tmp)%Mod;
//		printf("\n");
//		for(int i=1;i<=x;i++)
//			printf("%d ",wz[i]);
//		printf("\n");
		return ;
	}
	if(x>n)
	{
		if(num>=m)
		{
			ans++;
		}
//		printf("%d\n",num);
//		for(int i=1;i<=n;i++)
//			printf("%d ",wz[i]);
//		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(bz[i]) continue;
		bz[i]=1;
		wz[x]=i;
		if((x-1-num)>=c[i]) dfs(x+1,num);
		else
		{
			if(s[x]=='0') dfs(x+1,num);
			else dfs(x+1,num+1);
		}
		bz[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(n<=18)
	{
		dfs(1,0);
		printf("%lld",ans);
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			int nw=i%2;
			if(s[1]=='1'&&c[i]) f[nw][1][1]=1;
			else f[nw][1][0]=1;
			for(int j=2;j<=i;j++)
			{
				for(int k=0;k<=j;k++)
				{
					if(j-1-(k-1)<c[i]&&s[j]=='1')
					{
						if(k) f[nw][j][k]=qz[j-1][k-1];
						else f[nw][j][k]=0;
					}
					else f[nw][j][k]=qz[j-1][k];
//					printf("%d %d %d %d\n",i,j,k,f[nw][j][k]);
				}
			}
			for(int j=1;j<=i;j++)
			{
				for(int k=0;k<=j;k++)
					qz[j][k]=(qz[j][k]+f[nw][j][k])%Mod;
			}
		}
		int zt=n%2;
		for(int i=m;i<=n;i++)
			ans=(ans+f[zt][n][i])%Mod;
		printf("%lld",ans);
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++)
		ans=(ll)ans*i%Mod;
	printf("%lld",ans);
	return 0;
}
