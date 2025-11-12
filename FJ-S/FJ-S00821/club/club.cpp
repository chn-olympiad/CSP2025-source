#include<bits/stdc++.h>
using namespace std;
int a[100001][4],maxn,ans,n,t=0;
int f[100001];int c[4];
int solve(int i)
{
	if(i==n)
	{
		ans=max(t,ans);
	}
	for(int j=1;j<=3;j++)
	{
		if(c[j]==maxn)continue;
		c[j]++;
		t=a[i][j]+solve(i+1);
		c[j]--;
	}
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		
		maxn=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
			}			
		}
		if(n==2)
		{
			for(int i=1;i<=2;i++)
			for(int j=1;j<=3;j++)
			for(int k=1;k<=3,k!=j;k++)
			ans=max(ans,a[i][j]+a[i][k]);
			printf("%d\n",ans);
		}
	}
	return 0 ;
}
