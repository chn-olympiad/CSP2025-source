#include<cstdio>
#include<algorithm>
using namespace std;
const long long maxn=1e6,mod=998244353;
struct Node{long long val,id;} s[maxn],tmp[maxn];
long long n,m,ans;
long long vis[maxn],a[maxn];
void dfs(int x)
{
	if(x>n)
	{
		for(int i=1;i<=n;i++)
			tmp[i]=s[i];
		sort(s+1,s+n+1,[](Node p,Node q){return p.id<q.id;});
		int cnt=0,res=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=s[i].val||!a[i])cnt++;
			else res++;
		}
		if(res>=m)ans++;
		for(int i=1;i<=n;i++)
			s[i]=tmp[i];
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]++;
			s[x].id=i;
			dfs(x+1);
			vis[i]--;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%1lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&s[i].val);
	if(n>10)
	{
		long long cnt=0,res=1;
		for(int i=1;i<=n;i++)
			if(!s[i].val)cnt++;
		if(n-cnt>=m)
		{
			for(long long i=1;i<=n;i++)
				res=res*i%mod;
			printf("%lld",res);
		}
		else
		{
			printf("0");
		}
		return 0;
	}
	dfs(1);
	printf("%lld",ans%mod);
	return 0;
}
