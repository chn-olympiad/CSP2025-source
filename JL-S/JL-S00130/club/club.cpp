#include <bits/stdc++.h>
using namespace std;
long long a[100005][5],dp[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++) {
			int maxa=-1,mina=2e4+5;
			for (int j=1;j<=3;j++) {
				cin>>a[i][j];
				if (maxa<a[i][j]) {
					a[i][0]=j;
					maxa=a[i][j];
				}
				if (mina>a[i][j]) {
					a[i][4]=j;
					mina=a[i][j];
				}
			}
		}
		memset(dp,-1,sizeof(dp));
		int idx=a[n][0];
		dp[n]=a[n][idx];
		int x=0,y=0,z=0;
		if (idx==1) x++;
		else if (idx==2) y++;
		else z++;
		for (int i=n-1;i>=1;i--) {
			if (a[i][0]==1) {
				if (x+1<=n/2) dp[i]=dp[i+1]+a[i][1],x++;
				else {
					int idx=6-a[i][0]-a[i][4];
					if (idx==2) {
						if (y+1<=n/2) dp[i]=dp[i+1]+a[i][2],y++;
						else dp[i]=dp[i+1]+a[i][3],z++;
					}
					else {
						if (z+1<=n/2) dp[i]=dp[i+1]+a[i][3],z++;
						else dp[i]=dp[i+1]+a[i][2],y++;
					}
				}
			}
			else if (a[i][0]==2) {
				if (y+1<=n/2) dp[i]=dp[i+1]+a[i][2],y++;
				else {
					int idx=6-a[i][0]-a[i][4];
					if (idx==1) {
						if (x+1<=n/2) dp[i]=dp[i+1]+a[i][1],x++;
						else dp[i]=dp[i+1]+a[i][3],z++;
					}
					else {
						if (z+1<=n/2) dp[i]=dp[i+1]+a[i][3],z++;
						else dp[i]=dp[i+1]+a[i][1],x++;
					}
				}
			}
			else {
				if (z+1<=n/2) dp[i]=dp[i+1]+a[i][3],z++;
				else {
					int idx=6-a[i][0]-a[i][4];
					if (idx==1) {
						if (x+1<=n/2) dp[i]=dp[i+1]+a[i][1],x++;
						else dp[i]=dp[i+1]+a[i][2],y++;
					}
					else {
						if (y+1<=n/2) dp[i]=dp[i+1]+a[i][2],y++;
						else dp[i]=dp[i+1]+a[i][1],x++;
					}
				}
			}
			cout<<dp[i]<<' ';
		}
		cout<<dp[1]<<'\n';
	}
	return 0;
}
