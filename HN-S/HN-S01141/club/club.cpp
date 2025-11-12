#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f; 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[n+2][5],maxn[5]={0},maxm[5]={0},ans=0,d[5]={0},anss=0,e=0,f[5]={0},l=0;
		bool b[n+2];
		memset(a,-1,sizeof(a)); 
		memset(b,false,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(maxm[1]<a[i][1])	{maxm[1]=a[i][1];maxn[1]=i;} 
			if(maxm[2]<a[i][2])	{maxm[2]=a[i][2];maxn[2]=i;} 
			if(maxm[3]<a[i][3])	{maxm[3]=a[i][3];maxn[3]=i;} 
		}
		if(n==2)	
		{
			for(int i=1;i<=3;i++)
			{
				anss+=a[1][i]; 
				for(int j=1;j<=3;j++)
				{
					if(i!=j)
					{
						anss+=a[2][j];
						ans=max(ans,anss);
						anss-=a[2][j]; 
					} 
				} 
				anss-=a[1][i];
			}
			printf("%d",ans); 
		}
		else
		{
				if(maxm[1]==0||maxm[2]==0||maxm[3]==0)
				{
					for(int q=1;q<=4;q++)
						for(int x=1;x<=4;x++)
							for(int y=1;y<=4;y++)
								for(int z=1;z<=4;z++)
									if(q!=x&&q!=y&&q!=z&&x!=y&&x!=z&&y!=z)
									{
											for(int i=1;i<=3;i++)
											{
												anss+=a[q][i]; 
												d[i]++; 
												for(int j=1;j<=3;j++)
												{
													if(i==j) continue;
													anss+=a[x][j]; 
													d[j]++; 
													for(int k=1;k<=3;k++)
													{
														if(i==k&&j==k) continue;
														anss+=a[y][k];
														d[k]++; 
														if(ans<anss)
														{
															ans=anss;
															for(int p=1;p<=3;p++)
															{
																f[p]=d[p]; 
															} 
														}
														anss-=a[y][k];
														d[k]--; 
													}
													anss-=a[x][j]; 
													d[j]--; 
												} 
												anss-=a[q][i];
												d[i]--; 
											}
											for(int i=1;i<=3;i++)
											{
												if(f[i]<(n/2))
												{
													e=max(e,a[z][i]); 
												}
											}
											ans+=e;
											l=max(l,ans);
									}					
					printf("%d",l);
				} 
				else
				{
					for(int i=1;i<=3;i++)
					{
						anss+=a[1][i]; 
						d[i]++; 
						for(int j=1;j<=3;j++)
						{
							if(i==j) continue;
							anss+=a[2][j]; 
							d[j]++; 
							for(int k=1;k<=3;k++)
							{
								if(i==k&&j==k) continue;
								anss+=a[3][k];
								d[k]++; 
								if(ans<anss)
								{
									ans=anss;
									for(int p=1;p<=3;p++)
									{
										f[p]=d[p]; 
									} 
								}
								anss-=a[3][k];
								d[k]--; 
							}
							anss-=a[2][j]; 
							d[j]--; 
						} 
						anss-=a[1][i];
						d[i]--; 
					}
					for(int i=1;i<=3;i++)
					{
						if(f[i]<(n/2))
						{
							e=max(e,a[4][i]); 
						}
					}
					ans+=e;
					l=max(l,ans);
					printf("%d",l);		
				}
		}
	}
	return 0;
} 
