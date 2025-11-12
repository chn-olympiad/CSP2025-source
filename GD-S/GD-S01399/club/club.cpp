#include <bits/stdc++.h>
using namespace std;
int a[1000][5],c[5];
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,maxn=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		if(n==2)
		{
			for(int j=1;j<=3;j++)
			{
				for(int k=1;k<=3;k++)
				{
					if(k!=j)
					{
						maxn=max(maxn,a[1][j]+a[2][k]);
					}
				}
			}
			cout<<maxn<<endl;
			maxn=0;
		}
		else if(n==4)
		{
			for(int j=1;j<=3;j++)
			{
				for(int k=1;k<=3;k++)
				{
					for(int l=1;l<=3;l++)
					{
						if(l!=j||l!=k)
						{
							for(int m=1;m<=3;m++)
							{
								if((m!=j&&m!=k)||(m!=j&&m!=l)||(m!=k&&m!=l))
								{
									maxn=max(maxn,a[1][j]+a[2][k]+a[3][l]+a[4][m]);
								}
							}
						}
					}
				}
			}
			cout<<maxn<<endl;
			maxn=0;
		}
		else if(n==10)
		{
			for(int j=1;j<=3;j++)
			{
				for(int k=1;k<=3;k++)
				{
					for(int l=1;l<=3;l++)
					{
						for(int m=1;m<=3;m++)
						{
							for(int o=1;o<=3;o++)
							{
								for(int p=1;p<=3;p++)
								{
									for(int q=1;q<=3;q++)
									{
										for(int r=1;r<=3;r++)
										{
											for(int s=1;s<=3;s++)
											{
												for(int t=1;t<=3;t++)
												{
													maxn=max(maxn,a[1][j]+a[2][k]+a[3][l]+a[4][m]+a[5][o]+a[6][p]+a[7][q]+a[8][r]+a[9][s]+a[10][t]);
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
			cout<<maxn<<endl;
			maxn=0;
		}
		else if(n==100000)
		{
			int b[100005];
			for(int j=1;j<=n;j++)
			{
				b[j]=a[j][1];
			}
			sort(b+1,b+n+1);
			for(int j=n/2+1;j<=n;j++)
			{
				maxn+=b[j];
			}
			cout<<maxn<<endl;
			maxn=0;
		}
	}
	return 0;
}
