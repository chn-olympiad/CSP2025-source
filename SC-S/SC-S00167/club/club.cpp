#include<bits/stdc++.h>
using namespace std;
int t;//数据组数
int n;//成员数量
int jiex;//每个社团的人数界限
int ans=0;//最大满意度
int a1[200001],a2[200001],a3[200001];//每个部门的满意度
int my1[200001],my2[200001],my3[200001];
int bmin[200001]={0};
int bmax[200001]={0};
int bvis[200001]={0};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t!=0)
	{
		int vis[200001]={0};//标记每个人是否入团
		scanf("%d",&n);
		jiex=n/2;
		ans=0;
		int rs1=0,rs2=0,rs3=0;//各社团的现有人数
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			my1[i]=a1[i];
			my2[i]=a2[i];
			my3[i]=a3[i];
		}
		int aum=0,bum=0;
		for(int i=1;i<=n;i++)
		{
			if(a2[i]!=0||a3[i]!=0)
			{
				aum++;
			}
			else if(a3[i]!=0)
			{
				bum++;
			}
		}
		if(aum==0)
		{
			sort(my1+1,my1+n+1);
			for(int i=n;i>=1;i--)
			{
				if(rs1<jiex)
				{
					ans+=my1[i];
					rs1++;
				}
			}
		}
		else if(bum==0)
		{
			int bb=1;
			while(bb<=n)
			{
				bmin[bb]=0x3f3f3f3f;
				for(int i=1;i<=n;i++)
				{
					if(bvis[i]==0)
					{
						bmin[bb]=min(bmin[bb],a1[i]);
					}
				}
				for(int i=1;i<=n;i++)
				{
					if(bmin[bb]==a1[i])
					{
						if(a1[i]>=a2[i]&&rs1<jiex)
						{
							bmax[bb]=a1[i];
							rs1++;
						}
						else if(a1[i]<a2[i]&&rs2<jiex)
						{
							bmax[bb]=a2[i];
							rs2++;
						}
						bvis[i]=1;
						bb++;
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				ans+=bmax[i];
			}
		}
		else if(aum!=0&&bum!=0)
		{
			int num=1;
			int h1[200001]={0},h2[200001]={0},h3[200001]={0};
			for(int i=1;i<=n;i++)
			{
				if(a1[i]>a2[i]&&a1[i]>a3[i])
				{
					if(vis[i]==0)
					{
						h1[num]=max(h1[num],a1[i]);
						if(h1[num]==a1[i])
						{
							vis[i]=1;
						}
					}
				}
				else if(a2[i]>a1[i]&&a2[i]>a3[i])
				{
					if(vis[i]==0)
					{
						h2[num]=max(h2[num],a2[i]);
						if(h2[num]==a2[i])
						{
							vis[i]=1;
						}
					}
				}
				else if(a3[i]>a2[i]&&a3[i]>a1[i])
				{
					if(vis[i]==0)
					{
						h3[num]=max(h3[num],a3[i]);
						if(h3[num]==a3[i])
						{
							vis[i]=1;
						}
					}
				}
				num++;
			}
		}
		printf("%d\n",ans);
		t--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}