#include<bits/stdc++.h>
using namespace std;
const int MAXN=500010;
int n,k,maxn;
int a[MAXN];
void dfs(int cur,int cnt,int anr,int gs)
{
	if(cur>n)
	{
		maxn=max(maxn,cnt);
		return;
	}
	if(cnt<maxn&&cnt+n-cur<maxn)
		return;
	if(anr==k)
		dfs(cur+1,cnt+1,a[cur+1],1);
	else
	{
		dfs(cur+1,cnt,a[cur+1] xor anr,gs+1);
		if(gs==1)
			dfs(cur+1,cnt,a[cur+1],1);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	dfs(1,0,a[1],1);
	printf("%d",maxn);
	return 0;
}

