#include<bits/stdc++.h>
#define ll long long
const int N=3e5+10;
const int inf=0x3f3f3f3f;
using namespace std;
int t,n;
int a[N][5];
int ans;
int vis[40][40][40][40]; 
int dp[5][105][105][105];
int flag1,flag[N],num;
void dfs(int now,int x,int y,int z,int sum)
{
	if(vis[now][x][y][z]>=sum)return;
	vis[now][x][y][z]=sum;
	if(now==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(x+1<=n/2)dfs(now+1,x+1,y,z,sum+a[now][1]);
	if(y+1<=n/2)dfs(now+1,x,y+1,z,sum+a[now][2]);
	if(z+1<=n/2)dfs(now+1,x,y,z+1,sum+a[now][3]);
} 
struct node
{
	int num,op;
}b[N];
bool cmp(node xx,node yy)
{
	return xx.num>yy.num;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		num=flag1=0;
		memset(flag,0,sizeof flag);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0 or a[i][3]!=0)flag1=1;
		}
		if(!flag1)
		{
			for(int i=1;i<=n;i++)b[i].num=a[i][1];
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=b[i].num;
			}
			printf("%lld\n",ans);
			continue;
		}
		if(n<=30)
		{
			ans=0;
			memset(vis,-1,sizeof vis);
			dfs(1,0,0,0,0);
			printf("%lld\n",ans);
			continue;
		}
		if(n<=200)
		{
				
			ans=0;
			memset(dp,0,sizeof dp);
			for(int i=1;i<=n;i++)
			{
				memset(dp[(i+1)%2],0,sizeof dp[(i+1)%2]);
				for(int x=0;x<=min(i,n/2);x++)
				{
					for(int y=0;y<=min(i,n/2);y++)
					{
						int z=i-x-y;
						if(z<0)continue;
						if(x+1<=n/2)
						{
							dp[(i+1)%2][x+1][y][z]=max(dp[(i+1)%2][x+1][y][z],dp[i%2][x][y][z]+a[i][1]);
							ans=max(ans,dp[(i+1)%2][x+1][y][z]);
						}
						if(y+1<=n/2)
						{
							dp[(i+1)%2][x][y+1][z]=max(dp[(i+1)%2][x][y+1][z],dp[i%2][x][y][z]+a[i][2]);
							ans=max(ans,dp[(i+1)%2][x][y+1][z]);
						}
						if(z+1<=n/2)
						{
							dp[(i+1)%2][x][y][z+1]=max(dp[(i+1)%2][x][y][z+1],dp[i%2][x][y][z]+a[i][3]);
							ans=max(ans,dp[(i+1)%2][x][y][z+1]);
						}
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			num++;
			b[num]={a[i][1],1};
			num++;
			b[num]={a[i][2],2};
			num++;
			b[num]={a[i][3],3};
		}
		sort(b+1,b+num+1,cmp);
		int xx=0,yy=0,zz=0;
		for(int i=1;i<=num;i++)
		{
			if(flag[i]==0)
			{
				if(b[i].op==1)
				{
					if(xx+1<=n/2)
					{
						flag[i]=1;
						ans+=b[i].num;
					}	
				}
				else if(b[i].op==2)
				{
					if(yy+1<=n/2)
					{
						flag[i]=1;
						ans+=b[i].num;
					}	
					
				}
				else
				{
					if(zz+1<=n/2)
					{
						flag[i]=1;
						ans+=b[i].num;
					}	
					
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
/*
*/ 
