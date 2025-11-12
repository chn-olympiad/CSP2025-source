#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N][4],cnt[4],ans;
void dfs(int dep,int sum)
{
	if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2) 
		return;
	if(dep>=n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		cnt[i]++;
		dfs(dep+1,sum+a[dep+1][i]);
		cnt[i]--;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(cnt,0,sizeof cnt);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}
