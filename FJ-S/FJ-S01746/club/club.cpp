#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
struct jl{
	int myd[5];
};
jl d[100005];
ll ans=0;
int shu[5];
int n;
void dfs(int now,ll sum)
{
	if(now>n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(shu[i]+1<=n/2)
		{
			shu[i]++;
			dfs(now+1,sum+d[now].myd[i]);
			shu[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		shu[1]=0;shu[2]=0;shu[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&d[i].myd[1],&d[i].myd[2],&d[i].myd[3]);
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}