#include <bits/stdc++.h>
#define ll long long
#define debug(x) cerr<<#x<<':'<<x<<endl
using namespace std;
ll a[100005][3],dp[3][2][100005];
int t,n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		ll val=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int cnt=0;cnt<=i;cnt++){
				if(i-cnt<=(n>>1)&&i!=cnt){
					dp[0][i%2][cnt]=max(dp[0][(i-1)%2][cnt]+a[i][1],dp[0][(i-1)%2][cnt]+a[i][2]);
					dp[1][i%2][cnt]=max(dp[1][(i-1)%2][cnt]+a[i][0],dp[1][(i-1)%2][cnt]+a[i][2]);
					dp[2][i%2][cnt]=max(dp[2][(i-1)%2][cnt]+a[i][0],dp[2][(i-1)%2][cnt]+a[i][1]);
				}
				if(cnt<=(n>>1)&&cnt>0){
					dp[0][i%2][cnt]=max(dp[0][(i-1)%2][cnt-1]+a[i][0],dp[0][i%2][cnt]);
					dp[1][i%2][cnt]=max(dp[1][(i-1)%2][cnt-1]+a[i][1],dp[1][i%2][cnt]);
					dp[2][i%2][cnt]=max(dp[2][(i-1)%2][cnt-1]+a[i][2],dp[2][i%2][cnt]);
				} 
			}
		}
		for(int x=0;x<3;x++){
			for(int i=0;i<=n;i++){
				val=max(val,dp[x][n%2][i]);
			}
		}
		cout<<val<<endl;
	}
}

