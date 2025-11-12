#include<bits/stdc++.h>
using namespace std;
const int MO=998244353;
int n,sum;
int l[5010];
void dfs(int cur,int h,int maxn,int cnt)
{
	if(cur>n)
		return;
	if(cnt>=3&&h>2*maxn)
		sum=(sum+1)%MO;
	dfs(cur+1,h+l[cur+1],max(maxn,l[cur+1]),cnt+1);
	if(cnt==1)
		dfs(cur+1,l[cur+1],l[cur+1],1);
	else
		dfs(cur+1,h,maxn,cnt);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",l+i);
	dfs(1,l[1],l[1],1);
	printf("%d",sum%MO);
	return 0;
}

