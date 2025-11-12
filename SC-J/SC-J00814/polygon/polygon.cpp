#include <bits/stdc++.h>
using namespace std;
const int K=998244353;

int n;
int a[5005]={};
long long ans=0;
bool cmp(int q,int p)
{
	return q>p;
}
void dfs(int maxn,int gon,int st,int sum)
{
	if(gon==0 and sum>maxn)
		ans=(ans+1)%K;
	else
	{
		for(int i=st+1;i<=n;i++)
			dfs(maxn,gon-1,i,sum+a[i]);
	}
	return;
}

signed int main(void)
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=3;j<=n-i+1;j++)
			dfs(a[i],j-1,i,0);
	}
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}