#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,t,dp[N][5],ans,a[N][5],b[5];

void solve(){
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3;j++){
			b[j]++;
			if (b[j]<=n/2){
				dp[i][j]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i][j];
				cout<<dp[i][j]<<endl;
			}
		}
	}
	cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<"\n";
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--){
		solve();
	}
	return 0;
} 
