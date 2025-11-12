#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],b[N];
long long dp[205][105][105];
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		int p=0;
		cin>>n;
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) 
		{
			cin>>a[i][j];
			if((j==2||j==3)&&a[i][j]==0) p++;
		}
		if(p==2*n)
		{
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+1+n);
			long long S=0;
			for(int i=n;i>n/2;i--) S+=b[i];
			cout<<S<<"\n";
			continue;
		}
		dp[1][1][0]=a[1][1];
		dp[1][0][1]=a[1][2];
		dp[1][0][0]=a[1][3];
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=min(n/2,i);j++)
			{
				for(int k=0;k<=min(i-j,n/2);k++)
				{
				//	if(i==10&&j==3) cout<<k<<endl;
					int l=i-j-k;
					if(l>n/2) continue;
					if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					if(l>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
					//cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[i][j][k][l]<<endl;
					if(i==n) ans=max(ans,dp[i][j][k]);
				}
			}
		}
		memset(dp,0,sizeof(dp));
		cout<<ans<<"\n";
	}
}
