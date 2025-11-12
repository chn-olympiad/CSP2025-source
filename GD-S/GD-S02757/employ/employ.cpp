#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=505,mod=998244353;
ll n,m,s[N],c[N],p[N],ans=0;
bool bo[N];
void dfs(ll x)
{
	if (x==n)
	{
		ll sum=0,cnt=0;
		for(ll i=1;i<=n;i++)
		{
			if (cnt>=c[p[i]])
			{
				cnt++;
				continue;
			}
			if (s[i]==0)
			{
				cnt++;
			}
			else
			{
				sum++;
			}
		}
		if (sum>=m)
		{
//			for(ll i=1;i<=n;i++)
//			{
//				printf("%lld ",p[i]);
//			}
//			printf("\n");
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(ll i=1;i<=n;i++)
	{
		if (!bo[i])
		{
			p[x+1]=i;
			bo[i]=true;
			dfs(x+1);
			bo[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++)
	{
		scanf("%1lld",&s[i]);
	}
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
	}
	dfs(0);
	printf("%lld",ans);
	return 0;
}
