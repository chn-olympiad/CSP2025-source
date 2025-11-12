#include <bits/stdc++.h>
using namespace std;
const int N=205;
int t;
int n;
int ma=0;
int a[N][4];
int dp[205][205][205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof(dp));
		ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int s1=min(n/2,i);s1>=0;s1--){
				for(int s2=min(n/2,i-s1);s2>=0;s2--){
					int s3=i-s1-s2;
					if(s3>n/2){
						continue;
					}
					if(s1>0)
						dp[s1][s2][s3]=max(dp[s1][s2][s3],dp[s1-1][s2][s3]+a[i][1]);
					if(s2>0)
						dp[s1][s2][s3]=max(dp[s1][s2][s3],dp[s1][s2-1][s3]+a[i][2]);
					if(s3>0)
						dp[s1][s2][s3]=max(dp[s1][s2][s3],dp[s1][s2][s3-1]+a[i][3]);
				}
			}
		}
		for(int s1=0;s1<=n/2;s1++){
			for(int s2=0;s2<=n/2&&s1+s2<=n;s2++){
				int s3=n-s1-s2;
				if(s3>n/2){
					continue;
				}
				ma=max(ma,dp[s1][s2][s3]);
			}
		}
		cout<<ma<<endl;
	}
	return 0;
}
