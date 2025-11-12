#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,a[5050],v[5050],vis[5050],ans,sum,cnt;
LL dfs(LL x,LL y,LL maxn)
{
	if(x==y)
	{
		return (++cnt)%998244353;
	}
	for(int i=1;i<=n;i++)
	{
		if((!vis[i])&&((a[i]+sum)>maxn))
		{
			vis[i]=1;
			sum+=a[i];
			dfs(x,y+1,a[i]>maxn?a[i]:maxn);
			vis[i]=0;
			sum-=a[i];
		}
	}
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=3;i<=n;i++)
	{
		cnt=0;
		ans=(long long)(ans+dfs(i,1,-545554))%998244353;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
}
