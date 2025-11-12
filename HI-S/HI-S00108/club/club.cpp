#include<bits/stdc++.h>
using namespace std;
struct rec
{
	int num,id;
}a[100010][5];
int f[100010][2];
int vis[5];
int vis1[5];
bool cmp(rec x,rec y)
{
	return x.num>y.num;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		memset(vis,0,sizeof(vis));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j].num);
				a[i][j].id=j;
			}
			sort(a[i]+1,a[i]+4,cmp);
		}
		f[1][1]=a[1][1].num;
		vis[a[1][1].id]=1;
		for(int i=2;i<=n;i++)
		{
			if(vis[a[i][1].id]==n/2)
			{
				if(vis[a[i][2].id]==n/2)
				{
					int flag=0;
					for(int j=1;j<i;j++)
					{
						for(int k=1;k<=3;k++)
						{
							if(a[j][k].id==a[i][2].id && k<3)
							{
								flag=1;
								f[i][1]=max(f[i-1][0],f[i-1][1])-a[j][k].num+a[j][k+1].num+a[i][2].num;
								f[i][0]=max(f[i-1][1],f[i-1][0])+a[i][3].num;
								vis[a[j][k-1].id]++;
								break;
							}
						}
						if(flag)
						{
							break;
						}
					}
					if(!flag)
					{
						f[i][1]=f[i][0]=max(f[i-1][1],f[i-1][0])+a[i][3].num;
					}
				}
				else
				{
					int flag=0;
					for(int j=1;j<i;j++)
					{
						for(int k=1;k<=3;k++)
						{
							if(a[j][k].id==a[i][1].id && k<3)
							{
								flag=1;
								f[i][1]=max(f[i-1][0],f[i-1][1])-a[j][k].num+a[j][k+1].num+a[i][1].num;
								f[i][0]=max(f[i-1][1],f[i-1][0])+a[i][2].num;
								vis[a[j][k-1].id]++;
								break;
							}
						}
						if(flag)
						{
							break;
						}
					}
					if(!flag)
					{
						f[i][1]=f[i][0]=max(f[i-1][1],f[i-1][0])+a[i][2].num;
					}
				}
			}
			else
			{
				f[i][1]=f[i][0]=max(f[i-1][0],f[i-1][1])+a[i][1].num;
				vis[a[i][1].id]++;
//				printf("%d\n",max(f[i][1],f[i][0]));
			}
		}
		printf("%d\n",max(f[n][0],f[n][1]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//f[i]表示前i个人选择部门时的满意度最大值
//ans=f[n]
