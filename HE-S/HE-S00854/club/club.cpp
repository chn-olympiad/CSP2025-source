#include<bits/stdc++.h>
using namespace std;
int s[3][101000];//满意程度
int cun[3][101000];//暂时存放小的数 
int hu[3][101000];//进入了哪个部门 
int zan[3][101000];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	int a=0,b=0,c=0;
	int mn=110000;
	int zann=0;
	int cnt=0;
	int sum=0;
	int suma=0,sumb=0,sumc=0;
	int mxa=-110,mxb=-110,mxc=-110;
	scanf("%d",&t);
	
	
	for(int hhh=1;hhh<=t;hhh++)
	{
		scanf("%d",&n);
		
			cnt=n/2;
			sum=0;
			for(int i=1;i<=n;i++)
			{
				mxa=-110;
				for(int j=1;j<=3;j++)
				{
					scanf("%d",&s[j][i]);
					if(s[j][i]>mxa)
					{
						mxa=s[j][i];
						hu[j][i]=mxa;		
					}
				}
				if(hu[1][i]!=0)
				{
					suma+=hu[1][i];
					a++;
				}
				else if(hu[2][i]!=0)
				{
					sumb+=hu[2][i];
					b++;
				}
				else if(hu[3][i]!=0)
				{
					sumc+=hu[3][i];
					c++;
				}
			}
			
			if(a>cnt)
			{
				for(int h=1;h<=a-cnt;h++)
				{
					int mn=110000;
					for(int y=1;y<=n;y++)
					{
						if(mn>hu[1][y])
						{
							mn=hu[1][y];
							zann=y;
							zan[1][1]=hu[1][y];
							zan[2][1]=hu[2][y];
							zan[3][1]=hu[3][y];
						}
					}
					hu[1][zann]=110001;
					if(s[2][zann]>s[3][zann]&&b<cnt)
					{
						sumb+=hu[2][zann];
						b++;
					}
					else
					{
						c++;
						sumc+=hu[3][zann];
					}
					suma-=mn;
				}
				
			}
			
			zann=0;
			
			if(b>cnt)
			{
				for(int h=1;h<=b-cnt;h++)
				{
					int mn=110000;
					for(int y=1;y<=n;y++)
					{
						if(mn>hu[2][y])
						{
							mn=hu[2][y];
							zann=y;
							zan[1][1]=hu[1][y];
							zan[2][1]=hu[2][y];
							zan[3][1]=hu[3][y];
						}
					}
					hu[1][zann]=110001;
					if(s[1][zann]>s[3][zann]&&a<cnt)
					{
						suma+=hu[1][zann];
						b++;
					}
					else
					{
						c++;
						sumc+=hu[3][zann];
					}
					sumb-=mn;
				}
			}
			
			zann=0;
			
			if(c>cnt)
			{
				for(int h=1;h<=c-cnt;h++)
				{
					int mn=110000;
					for(int y=1;y<=n;y++)
					{
						if(mn>hu[3][y])
						{
							mn=hu[3][y];
							zann=y;
							zan[1][1]=hu[1][y];
							zan[2][1]=hu[2][y];
							zan[3][1]=hu[3][y];
						}
					}
					hu[3][zann]=110001;
					if(s[1][zann]>s[2][zann]&&a<cnt)
					{
						suma+=hu[1][zann];
						a++;
					}
					else
					{
						b++;
						sumb+=hu[2][zann];
					}
					sumc-=mn;
				}
			}
			sum+=suma+sumb+sumc;
			printf("%d\n",sum);
			suma=0;
			sumb=0;
			sumc=0;
			sum=0;
		
		
	}
	
	/*
					if(hu[1][i]!=0&&hu[2][i]!=0)
					{
						if(hu[1][i]>hu[2][i])
						{
							hu[1][i]=mxa;
							cun[2][i]=hu[2][i]; 
							hu[2][i]=0;
						}
						else
						{
							hu[2][i]=mxa;
							cun[1][i]=hu[1][i];
							hu[1][i]=0;
						}
					}
					
					if(hu[2][i]!=0&&hu[3][i]!=0)
					{
						if(hu[2][i]>hu[3][i])
						{
							hu[2][i]=mxa;
							hu[3][i]=0;
						}
						else
						{
							hu[3][i]=mxa;
							hu[2][i]=0;
						}
					}
					
					if(hu[1][i]!=0&&hu[3][i]!=0)
					{
						if(hu[1][i]>hu[3][i])
						{
							hu[1][i]=mxa;
							hu[3][i]=0;
						}
						else
						{
							hu[3][i]=mxa;
							hu[1][i]=0;
						}
					}
					*/
	
	
	
	
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(mxa<s[1][i])
			{
				mxa=s[1][i];
			}
			if(mxb<s[2][i])
			{
				mxb=s[2][i];
			}
			if(mxc<s[3][i])
			{
				mxc=s[3][i];
			}
		}
	}
	*/
/*
3 
4 
4 2 1
3 2 4
5 3 4
3 5 1
4 
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/



	fclose(stdin);
	fclose(stdout);
	return 0;
}
