
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;

int T,n,dp[maxn][4],member[maxn][4],cnt[maxn][4][4];
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		memset(dp,0,sizeof(dp));
		memset(member,0,sizeof(member));

		memset(cnt,0,sizeof(cnt));
		cin>>n;
		if(n==2)
		{
			int a[4],b[4];
			cin>>a[1]>>a[2]>>a[3]>>b[1]>>b[2]>>b[3];
			int ans=0;
			for(int i=1;i<=3;++i)
			for(int j=1;j<=3;++j)
			{
				if(i==j)continue;
				else
				ans=max(ans,a[i]+b[j]);
				
			}
			cout<<ans<<endl;
		}
		else
		{
		
		int limit=n/2;
		for(int i=1; i<=n; ++i)
			cin>>member[i][1]>>member[i][2]>>member[i][3];
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=3; ++j) {
				for(int k=1; k<=3; ++k) {
					if(cnt[i-1][k][j]<limit) {
						if(dp[i][j]<member[i][j]+dp[i-1][k]){
						
						dp[i][j]=member[i][j]+dp[i-1][k];
						cnt[i][j][1]=cnt[i-1][k][1];
						cnt[i][j][2]=cnt[i-1][k][2];
						cnt[i][j][3]=cnt[i-1][k][3];
						cnt[i][j][j]++;
						
						}
					}
				}
			}
		}
		int ans=0;
		


		for(int i=1; i<=3; ++i)
			ans=max(ans,dp[n][i]);
		cout<<ans<<'\n';
}
	}
//	cout<<endl;
///	for(int i=1;i<=n;++i)
//	{
//		cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<endl;
//	}
//		cout<<endl;



	return 0;
}

