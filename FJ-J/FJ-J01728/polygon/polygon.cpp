#include<cstdio>
#include<vector>
#include<algorithm> 
using namespace std;
typedef long long LL;
const int N=5e3+10;
const LL Mod=998244353;
int n,a[N],val[N];
long long ans;
int dfs(int step,int tsum,int gs,int maxn)
{
	if(step==n+1) 
	{
		if(tsum>2*maxn && gs>=3)
		{
			ans++;
			ans%=Mod;
		}
		return 0;
	}
	val[gs+1]=a[step];
	dfs(step+1,tsum+a[step],gs+1,a[step]); 
	val[gs+1]=0;
	dfs(step+1,tsum,gs,maxn);
	return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}
