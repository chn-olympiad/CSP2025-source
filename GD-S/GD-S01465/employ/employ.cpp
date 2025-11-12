#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[510];
int c[510];
int mark[510];
long long ret=0;
void dfs(int dep,int cnt)
{
	for (int i=1;i<=n;i++)
	{
		if (mark[i]==0)
		{
			mark[i]=1;
			if (s[dep-1]=='1' && dep-cnt-1<c[i])
			{
				if (cnt+1==m)
				{
					long long sum=1;
					for (int j=2;j<=n-dep;j++)
					{
						sum=(sum*j)%998244353;
					}
					ret=(ret+sum)%998244353;
					mark[i]=0;
					return ;
				}
				dfs(dep+1,cnt+1);
			}
			else
			{
				dfs(dep+1,cnt);
			}
			mark[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	memset(mark,0,sizeof(mark));
	dfs(1,0);
	printf("%lld",ret);
	return 0;
}
