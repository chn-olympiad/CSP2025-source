
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int n,cnt;
int ans;
int a[N],b[N],c[N],v[N];
int aa,bb,cc;
int dp[N][4];
void solve() {

	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>dp[i][1]>>dp[i][2]>>dp[i][3];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(aa>=n/2){
				dp[i][j]+=max(dp[i-1][2],dp[i-1][3]);
			}else if(bb>=n/2){
				dp[i][j]+=max(dp[i-1][1],dp[i-1][3]);
			}else if(cc>=n/2){
				dp[i][j]+=max(dp[i-1][1],dp[i-1][2]);
			}else{
				dp[i][j]+=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
			}
			
			if(dp[i][j]==dp[i-1][1]){
				aa++;
			}else
			if(dp[i][j]==dp[i-1][2]){
				bb++;
			}else
			if(dp[i][j]==dp[i-1][3]){
				cc++;
			}
			ans=max(dp[i][j],ans);
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=0;

		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		solve();
		cout<<ans<<endl;
	}

	return 0;
}


/*


*/



