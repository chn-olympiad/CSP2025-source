#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans,maxb,maxc,a[100001],b[100001],c[100001],dp[201][201][201];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	//~ t=1;
	while(t--)
	{
		cin>>n;
		maxb=0;
		maxc=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			maxb=max(maxb,b[i]);
			maxc=max(maxc,c[i]);
		}
		ans=0;
		if(n<=200)
		{
			for(int i=0;i<=200;i++)
				for(int j=0;j<=200;j++)
					for(int k=0;k<=200;k++)
						dp[i][j][k]=0;
			dp[1][0][0]=a[1];
			dp[0][1][0]=b[1];
			dp[0][0][1]=c[1];
			for(int i=2;i<=n;i++)
			{
				for(int j=n/2;j>=0;j--)
				{
					for(int k=n/2;k>=0;k--)
					{
						int l=i-j-k;
						//~ cerr<<'$'<<i<<' '<<j<<' '<<k<<' '<<l<<'\n';
						if(l>n/2)
							continue;
						if(l<0)
							continue;
						if(j>=1)
							dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i]);
						if(k>=1)
							dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+b[i]);
						if(l>=1)
							dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+c[i]);
						//~ cerr<<'#'<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<dp[j][k][l]<<'\n';
						ans=max(ans,dp[j][k][l]);
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		if(maxb==0&&maxc==0)
		{
			sort(a+1,a+n+1,less<long long>());
			for(int i=1;i<=n/2;i++)
				ans+=a[i];
			cout<<ans<<'\n';
			continue;
		}
		cout<<0<<'\n';
	}
	return 0;
}
