#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[4][200005],c[200005],maxx;
priority_queue<int>q;
void dfs(int x,int ans)
{
	if(x==n+1)
	{
		maxx=max(maxx,ans);
		return;
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			if(c[i]<n/2)
			{
				c[i]++;
				dfs(x+1,ans+a[i][x]);
				c[i]--;
			}
		}
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		bool bz=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[1][i],&a[2][i],&a[3][i]);
			q.push(a[1][i]);
			if(a[2][i]!=0)
			{
				bz=0;
			}
		}
		if(bz)
		{
			int ans=0,t=0;
			while(q.size()!=0)
			{
				ans+=q.top();
				t++;
				if(t==n/2) break;
				q.pop();
			}
			printf("%lld\n",ans);
			while(q.size()) q.pop();
		}
		maxx=0;
		dfs(1,0);
		printf("%lld\n",maxx);
	}
}
