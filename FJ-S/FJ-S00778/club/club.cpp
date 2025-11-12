#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=200+10,M=1e5+10;
int t;
int n;
int a[M][4];
int dp[N][N/2][N/2][N/2];
int dp1[N][N/2][N/2];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		int b=1;
		for (int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if (a[i][2]!=0 or a[i][3]!=0) {
				b=0;
			}
		}
		if (b) {
			int p[M],ans=0;
			for (int i=1; i<=n; i++) {
				p[i]=a[i][1];
			}
			sort(p+1,p+n+1);
			for (int i=n; i>n/2; i--) {
				ans+=p[i];
			}
			cout<<ans<<endl;
		} else if (n<200) {
			memset(dp,0,sizeof(dp));
			for (int i=1; i<=n; i++) {
				for (int j=0; j<=n/2; j++) {
					for (int k=0; k<=n/2; k++) {
						for (int w=0; w<=n/2; w++) {
							if (j>=1) {
								dp[i][j][k][w]=max(dp[i][j][k][w],dp[i-1][j-1][k][w]+a[i][1]);
							}
							if (k>=1) {
								dp[i][j][k][w]=max(dp[i][j][k][w],dp[i-1][j][k-1][w]+a[i][2]);
							}
							if (w>=1) {
								dp[i][j][k][w]=max(dp[i][j][k][w],dp[i-1][j][k][w-1]+a[i][3]);
							}
						}
					}
				}
			}
			cout<<dp[n][n/2][n/2][n/2]<<endl;
		} else {
			memset(dp1,0,sizeof(dp1));
			for (int i=1; i<=n; i++) {
				for (int j=0; j<=n/2; j++) {
					for (int k=0; k<=n/2; k++) {
						if (j>=1) {
							dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j-1][k]+a[i][1]);
						}
						if (k>=1) {
							dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j][k-1]+a[i][2]);
						}
					}
				}
			}
			cout<<dp1[n][n/2][n/2]<<endl;
		}
	}
	return 0;
}
