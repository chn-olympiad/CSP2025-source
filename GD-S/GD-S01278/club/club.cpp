#include<bits/stdc++.h>
using namespace std;
int t;
struct node
{
	int b,c,d;
};
node a[100010];
bool cmp(node x,node y)
{
	return x.b>y.b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{ 
		int n;
		cin>>n;
		if(n==2)
		{
			int a[5][5];
			int maxn=-1;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin>>a[i][j];
				}
			}
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i!=j)maxn=max(maxn,a[1][i]+a[2][j]);
				}
			}
			cout<<maxn<<"\n";
			continue;
		}
		else if(n==4)
		{
			int maxn1=-1,a1[15][15];
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin>>a1[i][j];
				}
			}
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					for(int k=1;k<=3;k++)
					{
						for(int l=1;l<=3;l++)
						{
							int b1[5],vis1=0;
							memset(b1,0,sizeof(b1));
				 			b1[i]++,b1[j]++,b1[k]++,b1[l]++;
							for(int r=1;r<=3;r++)
							{
								if(b1[r]>2)
								{
									vis1=1;
								}
							}
							if(vis1==1)continue;
							maxn1=max(maxn1,(a1[1][i]+a1[2][j]+a1[3][k]+a1[4][l]));
						}
					} 
				}
			}
			cout<<maxn1<<"\n";
			continue;
		}
		else if(n==10)
		{
			int maxn2=-1,a2[15][15];
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin>>a2[i][j];
				}
			}
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					for(int k=1;k<=3;k++)
					{
						for(int l=1;l<=3;l++)
						{
							for(int r=1;r<=3;r++)
							{
								for(int q=1;q<=3;q++)
								{
									for(int w=1;w<=3;w++)
									{
										for(int e=1;e<=3;e++)
										{
											for(int y=1;y<=3;y++)
											{
												for(int u=1;u<=3;u++)
												{
													int b2[15],vis2=0;
													memset(b2,0,sizeof(b2));
													b2[i]++,b2[j]++,b2[k]++,b2[l]++;
													b2[r]++,b2[q]++,b2[w]++,b2[e]++;
													b2[y]++,b2[u]++;
													for(int o=1;o<=3;o++)
													{
														if(b2[o]>5)
														{
															vis2=1;
														}
													}
													if(vis2)continue;
													maxn2=max(maxn2,(a2[1][i]+a2[2][j]+a2[3][k]+a2[4][l]+a2[5][r]+a2[6][q]+a2[7][w]+a2[8][e]+a2[9][y]+a2[10][u]));
												}
											}
										}
									}
								}
							}
						}
					} 
				}
			}
			cout<<maxn2<<"\n";
			continue;
		}
		bool vis1=0,vis2=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].b,&a[i].c,&a[i].d);
			if(a[i].c!=0 || a[i].d!=0)
			{
				vis1=1;
			}
			if(a[i].d!=0) 
			{
				vis2=1;
			}
		}
		if(!vis1)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].b;
			}
			cout<<ans;
			continue;
		}
	}
	return 0;
}
/*
上午的初赛感觉还好
?(关于main()不能返回signed这件事) 
（230tps-266tps)(2~1?)
t1 100
t2 100
t3 ~30
t4 ~30
人才CCFt4不给多几个样例; 
我同学说他能冲300tps; 
他说他同学想到t4正解了; 

下午就不那么好了 (25tps~"30tps")(0~3?) 
由于没有复习图论
导致t2连通性和最短路不会写
t3,t4不知所云
(t3搞了个全输出0的代码，靠CCF了) 
t1也不会正解
怎么办？
可以看到打了n<=10暴力
以及性质A
顶多25tps
听说S非零可以参加NOIP
看来我得继续努力了 

虽然其中考临近了
但我回家后还要去打羽毛球
就讲到这吧 

"If give me enough time,I will ak ioi"
"I am just 13 now"
