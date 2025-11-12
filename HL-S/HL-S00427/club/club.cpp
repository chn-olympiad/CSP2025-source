#include <iostream>
using namespace std;

int a[210][4];
int dp[202][102][102][102];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T1;
	cin>>T1;
	//cout<<111;
	for (int tt=1;tt<=T1;tt++) {
		//cout<<tt<<endl; 
		int n;
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int maxbn=n/2;
		for (int i=1;i<=n;i++) {
			for (int j1=0;j1<=maxbn;j1++) {
				for (int j2=0;j2<=maxbn;j2++) {
					for (int j3=0;j3<=maxbn;j3++) {
						dp[i][j1][j2][j3]=dp[i-1][j1][j2][j3];
						if (j1!=0) dp[i][j1][j2][j3]=max(dp[i][j1][j2][j3],dp[i-1][j1-1][j2][j3]+a[i][1]);
						if (j2!=0) dp[i][j1][j2][j3]=max(dp[i][j1][j2][j3],dp[i-1][j1][j2-1][j3]+a[i][2]);
						if (j3!=0) dp[i][j1][j2][j3]=max(dp[i][j1][j2][j3],dp[i-1][j1][j2][j3-1]+a[i][3]);
					}
				}
			}
		}
		cout<<dp[n][maxbn][maxbn][maxbn]<<endl;
	}
	return 0;
}
