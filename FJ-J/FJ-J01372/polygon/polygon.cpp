#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans;
void dfs(long long x,long long sum,long long maxx,long long cnt)
{
	if(n-x+1+cnt<3)
		return;
	if(x>n)
	{
		if(maxx*2<sum)
		{
			ans++;
			ans=ans%998244353;
		}
		return;
	}
	long long maxn=max(maxx,a[x+1]);
	dfs(1+x,sum+a[x+1],maxn,cnt+1);
	dfs(x+1,sum,maxx,cnt);
}
int main()
{
	/*freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);*/
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(0,0,0,0);
	printf("%d",ans/2);
	return 0;
}
