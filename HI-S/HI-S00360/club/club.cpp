#include <bits/stdc++.h>
using namespace std;
long long t,n,a[100009][5],maxn,clu[5],rem[203][203][203],p[100009],zer2,zer3;
void dfs(long long x,long long y,long long poi)
{
	if(x==n+1)
	{
		maxn=max(maxn,poi);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		clu[i]++;
		if(clu[i]<=n/2 && poi+a[x][i]>=rem[clu[1]][clu[2]][clu[3]])
		{
			rem[clu[1]][clu[2]][clu[3]]=poi+a[x][i];
			dfs(x+1,i,poi+a[x][i]);
		}
		clu[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		zer3=0,zer2=0,maxn=0,clu[1]=0,clu[2]=0,clu[3]=0;
		for(int i=0;i<=105;i++) for(int j=0;j<=105;j++) for(int k=0;k<=105;k++) rem[i][j][k]=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]==0) zer2++;
			if(a[i][3]==0) zer3++;
		}
		if(zer2==n)
		{
			for(int i=1;i<=n;i++) p[i]=a[i][1];
			sort(p+1,p+n+1);
			for(int i=n;i>n/2;i--) maxn+=p[i];
		}
		else dfs(1,1,0);
		printf("%lld\n",maxn);
	}
	return 0;
}
