#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=510,P=998244353;
char st[N];int a[N],v[N],sum[N],n,m,ans;
void dfs(int x,int k,int sum)
{
//	printf("%d %d %d\n",x,k,sum);
	if(x==n+1)
	{
		if(k>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++)if(!v[i])
	{
		v[i]=1;int kk=(sum<a[i]&&(st[x]-'0'));
		dfs(x+1,kk+k,sum+!kk);
		v[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,st+1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(st[i]=='0');
	if(m==n)
	{
		if(sum[n])puts("0");
		else
		{
			for(int i=1;i<=n;i++)if(a[i]==0)
			{
				puts("0");
				return 0;
			}
			LL ans=1;
			for(int i=1;i<=n;i++)ans=(ans*i%P);
			printf("%lld",ans);
		}
		return 0;
	}
	if(m==1)
	{
		
	}
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}
