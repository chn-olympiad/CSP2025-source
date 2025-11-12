#include<bits/stdc++.h> 
using namespace std;
const int N=10;
int dp[3][N][N/2];
int s[6][3]{
	{1,3,3},
	{1,2,2},
	{2,1,3},
	{2,3,1},
	{3,1,2},
	{3,2,1}
};
//问题：无法处理几个club同时选一个人 
//原因：dp 
//dp[i][j][k]=max(dp[i][j-1][k],dp[i][j-1][k-1]+a[i][j]) 
//dp[i][j][k]:第i个club选到第j个人已选了k个人的最大满意度 
//1:选 (这次j-1,上次j-1) dp[i][j-1][k]+dp[i-1][j-1][k]+a[i][j]
//2:不选 {max(这次k-1 and 上次k,这次k and 上次k-1)} max(dp[i][j-1][k]+dp[i-1][j][k],dp[i][j][k]+dp[i-1][j-1][k])
//dp[i][j][k]=max(dp[i][j-1][k]+dp[i-1][j-1][k]+a[i][j],max(dp[i][j-1][k]+dp[i-1][j][k],dp[i][j][k]+dp[i-1][j-1][k]))
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		vector<int> a[4];
		a[1].push_back(0);
		a[2].push_back(0);
		a[3].push_back(0);
		
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int aa,b,c;
			cin>>aa>>b>>c;
			a[1].push_back(aa);
			a[2].push_back(b);
			a[3].push_back(c);
		}//dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+a[i][j])
		// 
		int maxn=-1;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n/2&&k<=j;k++){ 
					dp[i][j][k]=max(dp[i][j-1][k-1]+a[i][j],max({dp[i-1][j][k],dp[i][j-1][k]}));
					maxn=max(maxn,dp[i][j][k]);
				}
			}
		}
		cout<<maxn<<"\n";
	}
	return 0;
}
