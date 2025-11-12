#include<bits/stdc++.h>
using namespace std;
struct pp{
	int sz[5];
	}e[205];

int t,n;
int dp[105][105][105];
bool cmp(pp x,pp y){
	return x.sz[1]>y.sz[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0,bj1=0,g=0;
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			e[i].sz[1]=a,e[i].sz[2]=b,e[i].sz[3]=c;
			if(b!=0||c!=0){
			bj1=1;
			}
	//		if(c!=0)
		//	{
		//		g=1;
	//			}
		}
		if(bj1==0)
		{
			sort(e+1,e+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=e[i].sz[1];
			printf("%d\n",ans);
			continue;
		}
/*		if(g==0)
		{
			struct nd{
				int sh,sn;
				}zz[400005];
			for(int i=1;i<=n;i++)
			{
				zz[i].sh=e[i].sz[1],zz[i].sn=i;
				zz[i+1].sh=e[i].sz[2],zz[i].sn=i;
				}
			bool cmp1(nd x,nd y)
			{
				return x.sh>y.sh;
				}
			sort(zz+1,zz+2*n+1,cmp1);
			
			}*/
		dp[1][0][0]=e[1].sz[1];
		dp[0][1][0]=e[1].sz[2];
		dp[0][0][1]=e[1].sz[3];
		for(int i=2;i<=n;i++)
		{
			int st=min(i,n/2);
			for(int x=0;x<=st;x++)
			{
				for(int y=0;y<=min(st,i-x);y++)
				{
					if(i-x-y>n/2)
						continue;
					if(x>0)
						dp[x][y][i-x-y]=max(dp[x-1][y][i-x-y]+e[i].sz[1],dp[x][y][i-x-y]);
					if(y>0)
						dp[x][y][i-x-y]=max(dp[x][y-1][i-x-y]+e[i].sz[2],dp[x][y][i-x-y]);
					if(n-x-y>0)
						dp[x][y][i-x-y]=max(dp[x][y][i-x-y-1]+e[i].sz[3],dp[x][y][i-x-y]);
					if(dp[x][y][i-x-y]>ans)
					{
						ans=dp[x][y][i-x-y];
				//		printf(" %d %d %d %d\n",x,y,i-x-y,ans);
						}
					//ans=max(ans,dp[x][y][i-x-y]);
				}
			}
		}
	//	for(int i=0;i<=n;i++)
		//{
		//	for(int j=0;j<=n;j++)
		//	{
		//		for(int z=0;z<=n;z++){
		//			printf("%d ",dp[i][j][z]);
		//		}
		//		printf("\n");
		//	}
		//	printf("\n");
		//}
		printf("%d\n",ans);
	
	}
	return 0;
}
/*
 * //447450
417649
473417
443896
484387
* 
* 447450
417649
473417
453145
484387
*/
