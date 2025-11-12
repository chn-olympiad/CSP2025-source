#include<bits/stdc++.h>
using namespace std;
int n,t,im,jm,km;
int dp[299][299][299];
int L,ans[5],cnt;
struct wu{
	int w1,w2,w3;
};
bool cmp(struct wu wa,struct wu wb)
{
	return wa.w1>wb.w1;
}
int main()
{
	struct wu w[100002];
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(cnt=0;cnt<t;cnt++)
	{
		L=0;
	cin>>n;
	if(n<=200)
	{
		memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		cin>>w[i].w1>>w[i].w2>>w[i].w3;
	}
	for(int l=0;l<n;l++)
	{
		for(int i=n/2;i>=0;i--)
		{		
			for(int j=n/2;j>=0;j--)
			{
				for(int k=n-i-j;k>=0;k--)
				{
					if(i==0)im=0;
					else im=dp[i-1][j][k]+w[l].w1;
					if(j==0)jm=0;
					else jm=dp[i][j-1][k]+w[l].w2;
					if(k==0)km=0;
					else km=dp[i][j][k-1]+w[l].w3;
					dp[i][j][k]=max(dp[i][j][k],max(max(im,jm),km));
					//3cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
				}
				L=max(L,dp[i][j][n-i-j]);
			}
		}
	}
		ans[cnt]=L;
	}
	else {
		sort(w,w+n,cmp);
		for(int i=0;i<=n/2;i++)L+=w[i].w1;
	}
	}
	for(int i=0;i<t-1;i++)cout<<ans[i]<<endl;
	cout<<ans[t-1];
	return 0;
}

