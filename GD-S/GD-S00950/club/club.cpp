#include<bits/stdc++.h>
using namespace std;

const int maxn=200+10;

int n;
int s[maxn][3];
int dp[maxn][maxn][maxn];

void solve(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s[i][0] >> s[i][1] >> s[i][2];
	}
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(i+j+k==0||i+j+k>n)continue;
				if(i>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+s[i+j+k][0]);
				if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+s[i+j+k][1]);
				if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+s[i+j+k][2]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n/2;i++)for(int j=1;j<=n/2;j++)if(i+j>=n/2)ans=max(ans,dp[i][j][n-i-j]);
	cout<<ans<<endl;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
