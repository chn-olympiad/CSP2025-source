#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v;
	int b[3];
};
int n,t;
int a[145141][4];
node dp[100004][4];
int ts[100861];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		bool kl=0;
		memset(ts,0,n);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			
		cin>>dp[i][0].v>>dp[i][1].v>>dp[i][2].v;
		if(dp[i][1].v!=0||dp[i][2].v!=0)kl++;
		ts[i]=dp[i][0].v;
		}
		if(!kl)
		{
			int summ=0;
			sort(ts+1,ts+1+n,cmp);
			for(int i=1;i<=n/2;i++)summ+=ts[i];
			cout<<summ<<endl;
			continue;
		}
	//	dp[0][0].b[0]=dp[0][0].b[1]=dp[0][0].b[2]=dp[0][1].b[0]=dp[0][1].b[1]=dp[0][1].b[2]=dp[0][2].b[0]=dp[0][2].b[1]=dp[0][2].b[2]=1;
		for(int i=1;i<=n;i++)dp[i][0].b[0]=dp[i][0].b[1]=dp[i][0].b[2]=dp[i][1].b[0]=dp[i][1].b[1]=dp[i][1].b[2]=dp[i][2].b[0]=dp[i][2].b[1]=dp[i][2].b[2]=0;
		for(int i=0;i<=n;i++)dp[i][0].b[0]=dp[i][1].b[1]=dp[i][2].b[2]=1;		
	//	dp[1][0].b[0]=dp[1][0].b[1]=dp[1][0].b[2]=dp[1][1].b[0]=dp[1][1].b[1]=dp[1][1].b[2]=dp[1][2].b[0]=dp[1][2].b[1]=dp[1][2].b[2]=1;

		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				 int p=0,p1=0;
					if(dp[i-1][0].v>=dp[i-1][1].v&&dp[i-1][0].v>=dp[i-1][2].v)
					{
						p=0;
					}
					else if(dp[i-1][1].v>=dp[i-1][0].v&&dp[i-1][1].v>=dp[i-1][2].v)
					{
						p=1;
					}
					else
					p=2;
					p1=(p+1)%3;
					for(int l=0;l<3;l++)
					{
						if(l!=p&&dp[i-1][l].v>=dp[i-1][p1].v)
						p1=l;
					}
					int p2=(2*p1+p*2)%3;
					int temp=p,tem=p1;
					if((dp[i-1][j].b[p]+dp[i][j].b[p])>n/2)p=p1,p1=temp;
					if((dp[i-1][j].b[p]+dp[i][j].b[p])>n/2)p=p2,p2=tem;
					dp[i][j].v+=dp[i-1][p].v;
					dp[i][j].b[p]+=dp[i-1][j].b[p];
					dp[i][j].b[p1]=dp[i-1][j].b[p1],dp[i][j].b[p2]=dp[i-1][j].b[p2];
				//	cout<<i<<" "<<j<<" "<<dp[i][j].v<<" "<<dp[i][j].b[p]<<" "<<p<<endl;		
			}
		}
		cout<<max(max(dp[n][0].v,dp[n][1].v),dp[n][2].v)<<endl;
	}
	return 0;
}
//////////tuiyilenashuoshatiaole
