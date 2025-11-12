#include<cstdio>
constexpr long long p=998244353;
long long pow(long long a,long long b)
{
	if(a==0)return 0;
	if(a==1)return 1;
	if(b==0)return 0;
	if(b==1)return a;
	if(b==1)return a*a;
	long long ans=pow(a,b>>1);
	return (ans*ans*((b&1)?a:1))%p;
}
long long facted[5005]={1,1,2};
inline long long sub(long long a,long long b)
{
	if(a<b)
	{
		return (a+p-b)%p;
	}
	return (a-b)%p;
}
int n,a[5005],b[5005],maxn=-1;
long long ans=0;
void dfs(int i,int m,int t,int maxa)
{
	if(i<=n)
	{
		dfs(i+1,m,t,maxa);
		dfs(i+1,m+1,t+a[i],maxa<a[i]?a[i]:maxa);
	}
	else
	{
		if(m>=3&&t>(maxa<<1))
		{
			++ans;
			ans%=p;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		++b[a[i]];
		if(maxn<a[i])
		{
			maxn=a[i];
		}
	}
	if(maxn==1)
	{
		printf("%lld",sub(sub(sub(pow(2,n),(n*(n-1)>>1)),n),1));
		return 0;
	}
	dfs(1,0,0,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}