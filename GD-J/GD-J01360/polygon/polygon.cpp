#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long ans=0;
int n;
vector<int> a;
bool vis[5010];
void dfs(int step,long long sum,int maxn,int cnt)
{
	if(step==n)
	{
		if(sum>maxn*2&&cnt>2) ans=(ans+1)%MOD;
		return;
	}
	dfs(step+1,sum,maxn,cnt);
	dfs(step+1,(sum+a[step])%MOD,max(maxn,a[step]),cnt+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		a.push_back(x);
	}
	dfs(0,0,-1,0);
	printf("%lld",ans%MOD);
	return 0;
}
