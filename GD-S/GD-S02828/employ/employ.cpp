#include<cstdio>
#define N 998244353
char s[501]={0};
long long int nums[501]={0},ans=0,n,m,qzh[501]={0};
bool vis[501]={0};
void dfs(long long int k,long long int cnt)
{
	if(k==n)
	{
		ans++,ans%=N;
		return;
	}
	for(long long int i=1;i<=n;i++)
	{
		long long int flag=(s[k]=='1'&&(k-cnt)<nums[i]),sx1=qzh[n]-qzh[k+1];
		if(vis[i]==0&&cnt+flag+sx1>=m)
		{
			vis[i]=1;
			dfs(k+1,cnt+flag);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s);
	for(long long int i=1;i<=n;i++)
	{
		scanf("%lld",nums+i);
	}
	for(long long int i=0;i<n;i++)
	{
		qzh[i+1]+=qzh[i]+s[i]-'0';
	}
	dfs(0,0);
	printf("%lld",ans);
	return 0;
}
