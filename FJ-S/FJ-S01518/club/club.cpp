#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e5+10; 
int t,n,ans,k[N][4];
int dfs(int step,int a,int b,int c,int tsum)
{
	if(step==n+1)
	{
		ans=max(ans,tsum);
		return 0;
	}
	if(a<n/2) dfs(step+1,a+1,b,c,tsum+k[step][1]);
	if(b<n/2) dfs(step+1,a,b+1,c,tsum+k[step][2]);
	if(c<n/2) dfs(step+1,a,b,c+1,tsum+k[step][3]);
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		memset(k,0,sizeof(k));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&k[i][j]);	
			}	
		}	
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
