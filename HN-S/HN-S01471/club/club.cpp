#include<bits/stdc++.h>
using namespace std;
const int N = 6e5+5;
int n;
int t;
//struct n{
//	int x,y,z;
//}a[100010];
int dp[N][N][N];
int a[N][5];
bool cmp(int x,int y){
	return x>y;
}
int ans[100010];
int sum[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int l = 1;
	while(t--){
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		
		for(int i = 1;i<=n;i++){
			for(int j = 0;j<n/2;j++){
				for(int k = 0;k<n/2;k++){
					dp[i][j][k] = max(dp[i-1][j][k-1]+a[i][1],dp[i][j][k]);
					dp[i][j][k] = max(dp[i-1][j-1][k]+a[i][2],dp[i][j][k]);
					dp[i][j][k] = max(dp[i-1][j][k]+a[i][3],dp[i][j][k]);
				}
			}
		}
		for(int i = 1;i<=n/2;i++){
			for(int j = 1;j<=n/2;j++){
				sum[l] = dp[1][i][j]+dp[2][i][j]+dp[3][i][j];
			}
		}
		l++;
	}
	for(int i = 1;i<=l;i++){
		cout<<sum[i]<<endl;
	}
	return 0;
} 
