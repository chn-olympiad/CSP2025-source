#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	long long a[5]={0};
	for(int z=0;z<t;z++)
	{
		int man[3][10005];
		cin>>n;
		for(int w=0;w<n;w++)
		{
			for(int i=0;i<3;i++)
			{
				cin>>man[i][w];
			}
		}
		int club[100005];
		int club1=0;
		int club2=0;
		int club3=0;
		int ans[3]={0};
		for(int j=0;j<n;j++)
		{
			if(man[0][j]>=man[1][j]&&man[0][j]>=man[2][j])
			{
				ans[0]+=man[0][j];
				club1++;
				club[j]=1;
			}
			else if(man[1][j]>=man[0][j]&&man[1][j]>=man[2][j])
			{
				ans[1]+=man[1][j];
				club2++;
				club[j]=2;
			}
			else if(man[2][j]>=man[0][j]&&man[2][j]>=man[1][j])
			{
				ans[2]+=man[2][j];
				club3++;
				club[j]=3;
			}
		}
		if(club1<=n/2&&club2<=n/2&&club3<=n/2)
		{
			a[z]=ans[0]+ans[1]+ans[2];
		}
		else
		{
			while(club1>n/2||club2>n/2||club3>=n/2)
			{
				if(club1>n/2)
				{
					int min1=0;
					int number=0;
					bool f=true;
					for(int m1=0;m1<n;m1++)
					{
						if(club[m1]==1&&f==true)
						{
							min1=man[0][m1];
							f=false;
							number=m1;
						}
						else if(club[m1]==1&&f==false)
						{
							if(min1>man[0][m1])
							{
								continue;
							}
							else
							{
								min1=man[0][m1];
								number=m1;
							}
						}
					}
					if(ans[0]-min1+man[1][number]>ans[0]-min1+man[2][number])
					{
						club1--;
						club2++;
						ans[0]-=min1;
						ans[1]+=man[1][number];
						club[number]=2;
					}
					else
					{
						club1--;
						club3++;
						ans[0]-=min1;
						ans[2]+=man[2][number];
						club[number]=3;
					}
				}
				else if(club2>n/2)
				{
					int min2=0;
					int number=0;
					bool f=true;
					for(int m2=0;m2<n;m2++)
					{
						if(club[m2]==2&&f==true)
						{
							min2=man[1][m2];
							f=false;
							number=m2;
						}
						else if(club[m2]==2&&f==false)
						{
							if(min2>man[0][m2])
							{
								continue;
							}
							else
							{
								min2=man[0][m2];
								number=m2;
							}
						}
					}
					if(ans[1]-min2+man[0][number]>ans[1]-min2+man[2][number])
					{
						club2--;
						club1++;
						ans[1]-=min2;
						ans[0]+=man[0][number];
						club[number]=1;
					}
					else
					{
						club2--;
						club3++;
						ans[1]-=min2;
						ans[2]+=man[2][number];
						club[number]=3;
					}
				}
				else if(club3>n/2)
				{
					int min3=0;
					int number=0;
					bool f=true;
					for(int m3=0;m3<n;m3++)
					{
						if(club[m3]==3&&f==true)
						{
							min3=man[2][m3];
							f=false;
							number=m3;
						}
						else if(club[m3]==3&&f==false)
						{
							if(min3>man[2][m3])
							{
								continue;
							}
							else
							{
								min3=man[2][m3];
								number=m3;
							}
						}
					}
					if(ans[2]-min3+man[0][number]>ans[2]-min3+man[1][number])
					{
						club3--;
						club1++;
						ans[2]-=min3;
						ans[0]+=man[0][number];
						club[number]=1;
					}
					else
					{
						club3--;
						club2++;
						ans[2]-=min3;
						ans[1]+=man[1][number];
						club[number]=2;
					}
				}
			}
			a[z]=ans[0]+ans[1]+ans[2];
		}
	}
	for(int s=0;s<t;s++)
	{
		cout<<a[s]<<endl;
	}
	return 0;
}
