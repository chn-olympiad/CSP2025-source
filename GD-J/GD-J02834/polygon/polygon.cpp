#include<algorithm>
#include<cstdio>
#define MOD 998244353
#define int long long
using namespace std;
int n,a[5001],ans;
void dfs(int x,int sum,int cnt,int max)
{
	if(cnt>=3&&sum>(max<<1)) ans++,ans%=MOD;
	for(int i=x+1;i<n;i++)
	{
		dfs(i,sum+a[i],cnt+1,a[i]);
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++) dfs(i,a[i],1,a[i]);
	printf("%lld",ans);
}
