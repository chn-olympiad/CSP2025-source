#include<bits/stdc++.h>
using namespace std;
int t,n,a[10005][5],sum,n2,she,ans;
bool b[10005][5];
int cun[5];//存放是否超出边界 
void dfs(int x,int sum)
{
	if(x>n)//到达边界 
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		
		if(a[x][1]>a[x][2]) 
		{
				if(cun[1]>=n2)//存放已满
				{
					b[x][2]=1;
					dfs(x+1,sum+a[x][2]);
				}
				else
				{
					cun[1]++;
					dfs(x+1,sum+a[x][1]);	
				}
			}
		else
		{
			if(cun[2]>=n2)//存放已满
			{
				dfs(x+1,sum+a[x][1]);
			}
			else
			{
				cun[1]++;
				dfs(x+1,sum+a[x][2]);	
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				a[i][j]=0;
		scanf("%d",&n);
		n2=n/2;
		if(n<=200)//三没有数据的 
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=3;j++)
					scanf("%d",&a[i][j]);//输入完成
			dfs(1,0);
			printf("%d\n",ans);
		}
		else
		{
			if(a[1][2]==0&&a[1][3]==0)//遍历只有社团一有数据的 
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=3;j++)
					{
						scanf("%d",&she);
						ans=ans+she;
					}	
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
