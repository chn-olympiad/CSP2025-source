#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
bool used[5005];
const long long mod = 998244353;
long long ans;
void dfs(int f)
{
	if(f == n+1)
	{
		int sum = 0,maxi = 0,cnt = 0;
		for(int i=1;i<=n;++i) sum += used[i]*a[i],maxi = used[i] ? i:maxi,cnt += used[i];
		if(sum > 2*a[maxi] && cnt >= 3) ++ans;
		return;
	}
	used[f] = true;
	dfs(f+1);
	used[f] = false;
	dfs(f+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(used,0,sizeof used);
	memset(a,0,sizeof a);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	if(n == 3)
	{
		int maxn = max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3] > 2*maxn)
		{
			printf("1");
			return 0;
		}
		else
		{
			printf("0");
			return 0;
		}
	}
	sort(a+1,a+n+1);
	dfs(1);
	printf("%lld",ans%mod);
	return 0;
}
