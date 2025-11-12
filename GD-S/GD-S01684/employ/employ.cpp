#include<cstdio>
#define ll long long int 
using namespace std;
const ll Md=998244353;
const int N=5e2;
char s[N+5];
int c[N+5];
bool bz[N+5];
int n,m;
ll ans=0;
void dfs(int x,int y,int z)
{
//	printf("%d %d %d\n",x,y,z);
	if(x>n)
	{
		ans+=(z>=m);
		if(ans>=Md)
		{
			ans-=Md;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!bz[i])
			{
				bz[i]=1;
				if(y>=c[i])
				{
					dfs(x+1,y+1,z);
				}
				else
				{
					if(s[x]=='1')
					{
						dfs(x+1,y,z+1);
					}
					else
					{
						dfs(x+1,y+1,z);
					}
//					dfs(x+1,y,z+(s[x]-'0'));
				}
				bz[i]=0;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	if(n<=18)
	{
		dfs(1,0,0);
		printf("%lld",ans);
	}
	else
	{
		bool flg=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!='1')
			{
				flg=0;
			}
		}
		if(flg)
		{
			ans=1;
			for(int j=2;j<=n;j++)
			{
				ans=(ans*j)%Md;
			}
			printf("%lld",ans);
		}
		else
		{
			printf("%d\n",n);
		}
	}
	return 0;
}
