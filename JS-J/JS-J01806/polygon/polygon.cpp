#include<bits/stdc++.h>
using namespace std;
int n,a[5005],m;
long long sum,ans;
void dfs(int idx)
{
	if(idx==m)
	{
		if(sum>a[m]) ans++;
		return;
	}
	sum+=a[idx];
	dfs(idx+1);
	sum-=a[idx];
	dfs(idx+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n+1);
	for(int i=3;i<=n;i++)
	{
		m=i;
		dfs(1);
	}
	printf("%lld",ans%998244353);
	return 0;
}
