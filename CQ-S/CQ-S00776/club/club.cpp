#include<bits/stdc++.h>
using namespace std;
int t,n,sat[100005][8],flag[8],answer[100005][8],num[100005],ans,grade=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		ans=0;
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=3;k++)
			{
				cin>>sat[j][k];
				answer[j][k]=0;
				if(k!=1 && sat[j][k]!=0)
				{
					grade=1;
				}
			}
			num[j]=0;
			flag[j]=0;
		}
		if (grade==0)
		{
			for (int i=1;i<=n;i++)
			{
				num[i]=sat[i][1];
			}
			sort(num+1,num+n+1,cmp);
			for (int i=1;i<=n/2;i++)
			{
				ans+=num[i];
			}
		}
		else
		{
			for (int j=1;j<=n;j++)
			{
				int k=2;
				if (sat[j][k]>sat[j][k-1])
				{
					if (sat[j][k]>sat[j][k+1])
					{
						answer[j][k]=sat[j][k];
						flag[k]+=1;
					}
				}
				else if(sat[j][k+1]>sat[j][k-1])
				{
					if (sat[j][k+1]>sat[j][k])
					{
						answer[j][k+1]=sat[j][k+1];
						flag[k+1]+=1;
					}
				}
				else
				{
					answer[j][k-1]=sat[j][k-1];
					flag[k-1]+=1;
				}
			}
			for (int j=1;j<=3;j++)
			{
				if (flag[j]>n/2)
				{
					for (int k=1;k<=n;k++)
					{
						num[k]=answer[k][j];
					}
					cout<<endl;
					sort(num+1,num+n+1,cmp);
					for (int k=1;k<=n/2;k++)
					{
						ans+=num[k];
					}
					ans+=sat[1][3]*(n/2);
				}
				else
				{
					for (int x=1;x<=n;x++)
					{
						for (int y=1;y<=3;y++)
						{
							ans+=answer[x][y];
						}
					}
				}
			}
			ans/=3;
		}
		cout<<ans<<endl;
	}
	return 0;
}
