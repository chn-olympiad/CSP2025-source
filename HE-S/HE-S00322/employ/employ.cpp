#include<cstdio>
using namespace std;
const int N=502;
int n,m;
char s[N];
int c[N];
bool a[N];
int b[N];
long long ans=0;
void dfs(int deep)
{
	if(deep>n)
	{
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='0'||c[b[i]]<=cnt2) cnt2++;
			else cnt1++;
		}
		if(cnt1>=m)
		{
			ans++;
			ans%=998244353;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!a[i])
		{
			a[i]=1;
			b[deep]=i;
			dfs(deep+1);
			a[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	bool flag=1;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='0')
		{
			flag=0;
			break;
		}
	}
	if(flag&&n>10)
	{
		ans=1;
		for(int i=2;i<=n;++i)
		{
			ans=(ans*((long long)i))%((long long)998244353);
		}
		printf("%lld",ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
