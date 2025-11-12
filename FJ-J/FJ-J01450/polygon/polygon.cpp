#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
void dfs(int dep,int maxn,int s)
{
	if(dep==n+1)
	{
		if(s>2*maxn) ans++;
		return ;
	}
	for(int i=1;i<=2;i++)
	{
		if(i==1) dfs(dep+1,max(maxn,a[dep]),s+a[dep]);
		else dfs(dep+1,maxn,s);
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
} 
