#include<bits/stdc++.h>
using namespace std;
int n,a[5001],s[5001];
int ans=0;
const int mod=998244353;
void dfs(int cnt,int scnt,int ls,int sum,int maxs)
{
	if(cnt==scnt){
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[s[i]];
		}
		if(sum>2*a[ls])ans=(ans+1)%mod;
		return;
	}
	s[cnt]=ls;
	for(int i=ls+1;i<=n;i++)
	{
		dfs(cnt+1,scnt,i,sum+a[i],a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		dfs(0,i,0,0,0);
	}
	printf("%d",ans);
	return 0;
}
