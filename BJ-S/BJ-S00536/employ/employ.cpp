#include<bits/stdc++.h>
using namespace std;

#define LL long long
const LL mod=998244353;
const int N=505;

int n,m;
bool a[N];
int one[N],sum;
int c[N];
char s[N];

LL fct[N];
void init()
{
	fct[0]=1;
	for (int i=1;i<=n;i++)
	{
		fct[i]=fct[i-1]*i%mod;
	}
}
LL ans;
bool chs[N];
int p[N];
void dfs(int x)
{
	if (x>sum)
	{
		int zero=0;
		for (int i=1;i<=sum;i++)
		{
			zero+=one[i]-one[i-1]-1;
			if (zero>=p[i])
				zero++;
			// printf("%d ",p[i]);
		}
		ans+=(n-zero>=m);
		// printf("->zero:%d\n",zero);
		return;
	}
	// printf("dfs(%d)\n",x);
	for (int i=1;i<=n;i++)
	{
		if (!chs[i])
		{
			// printf("	chs:%d\n",i);
			p[x]=c[i];
			chs[i]=1;
			dfs(x+1);
			chs[i]=0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1);
	for (int i=1;i<=n;i++)
	{
		a[i]=s[i]-'0';
		if (a[i]) one[++sum]=i;
	}
	if (m>sum)
	{
		printf("0");
		return 0;
	}
	init();
	if (m==n)
	{
		if (c[1]==0)
		{
			printf("0");
			return 0;
		}
		printf("%lld",fct[n]);
		return 0;
	}
	if (sum<=10)
	{
		ans=0;
		dfs(1);
		printf("%lld",ans*fct[n-sum]%mod);
		return 0;
	}
	if (m==1)
	{
		ans=1;
		for (int i=1;i<=sum;i++)
		{
			int tmp=upper_bound(c+1,c+n+1,one[i]-1)-c;
			tmp--;
			if (!tmp)
			{
				printf("%lld",fct[n]);
				return 0;
			}
			ans=ans*(tmp-i+1)%mod;
			// printf("one[%d]=%d,tmp=%d\n",i,one[i],tmp);
		}
		printf("%lld",(fct[n]-ans*fct[n-sum]%mod+mod)%mod);
		return 0;
	}
	return 0;
}