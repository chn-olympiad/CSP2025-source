#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
constexpr int N=1e5+5;
int T,n,limit,dp[105][105][105];
struct people{
	int a,b,c;
}p[N];
bool cmp(people x,people y)
{
	return x.a-x.b>y.a-y.b;
}
void baoli()
{
	int res=0;
	for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
			for(int k=0;k<=n/2;k++)
				dp[i][j][k]=-inf;
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=n/2;j>=1;j--)	for(int k=n/2;k>=1;k--)	for(int l=n/2;l>=1;l--)	dp[j][k][l]=max({dp[j][k][l],dp[j-1][k][l]+p[i].a,dp[j][k-1][l]+p[i].b,dp[j][k][l-1]+p[i].c});
		
		for(int j=n/2;j>=1;j--)	for(int k=n/2;k>=1;k--)	dp[j][k][0]=max({dp[j][k][0],dp[j-1][k][0]+p[i].a,dp[j][k-1][0]+p[i].b}); 
		for(int j=n/2;j>=1;j--)	for(int k=n/2;k>=1;k--)	dp[0][j][k]=max({dp[0][j][k],dp[0][j-1][k]+p[i].b,dp[0][j][k-1]+p[i].c}); 
		for(int j=n/2;j>=1;j--)	for(int k=n/2;k>=1;k--)	dp[j][0][k]=max({dp[j][0][k],dp[j-1][0][k]+p[i].a,dp[j][0][k-1]+p[i].c}); 
		
		for(int j=n/2;j>=1;j--)	dp[j][0][0]=max(dp[j-1][0][0]+p[i].a,dp[j][0][0]);
		for(int j=n/2;j>=1;j--)	dp[0][j][0]=max(dp[0][j-1][0]+p[i].b,dp[0][j][0]);
		for(int j=n/2;j>=1;j--)	dp[0][0][j]=max(dp[0][0][j-1]+p[i].c,dp[0][0][j]);
	}
	for(int i=0;i<=n/2;i++)
	{
		for(int j=0;j<=n/2;j++)
		{
			for(int k=0;k<=n/2;k++)
			{
				if(i+j+k==n)	res=max(res,dp[i][j][k]);
			}
		}
	}
	cout<<res<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>T;
	while(T--)
	{	
		bool t=1; 
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].c)	t=0;
		}
		if(t)
		{
			int ans=0;
			sort(p+1,p+n+1,cmp);
			for(int i=1;i<=n/2;i++)	ans+=p[i].a+p[n/2+i].b;
			cout<<ans<<"\n";
		}
		else baoli();
	}
	return 0;
}
//60-70pts
