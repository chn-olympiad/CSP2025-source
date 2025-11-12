#include<bits/stdc++.h>
using namespace std;
struct u
{
	int n,x,y;
};
int dp[100005][100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,sum=0,bu1=0,bu2=0,bu3=0;
		cin>>n;
		int ans=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>dp[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			u maxn;
			maxn.n=-0x7fffffff;
			for(int i1=1;i1<=n;i1++)
			{
				for(int j1=1;j1<=3;j1++)
				{
					if(maxn.n<=dp[i1][j1])
					{
						maxn.n=dp[i1][j1];
						maxn.x=i1;
						maxn.y=j1;
					}
				}
			}
			sum+=maxn.n;
			int xx=maxn.x;
			int yy=maxn.y;
			for(int k=1;k<=3;k++)
			{
				dp[xx][k]=0;
			}
			if(yy=1) bu1++;
			if(yy=2) bu2++;
			if(yy=3) bu3++;
			if(bu1==ans)
			{
				for(int k=1;k<=n;k++)
				{
					dp[k][1]=0; 
				}
			}
			if(bu2==ans)
			{
				for(int k=1;k<=n;k++)
				{
					dp[k][2]=0;
				}
			}
			if(bu2==ans)
			{
				for(int k=1;k<=n;k++)
				{
					dp[k][2]=0;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
