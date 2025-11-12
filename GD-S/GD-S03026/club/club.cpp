#include<bits/stdc++.h>
using namespace std;
int n;
int a[100009][4];

//DP1~11
int dp[109][109][109];
void solve_dp(){
	for(int sum = 1;sum<=n;++sum){
		for(int i = 0;i<=n/2;++i){
			for(int j = 0;j<=n/2;++j){
				if(sum-i-j<0) break;
				int k = sum-i-j;
				int mx = 0;
				if(i>0) mx = max(mx,dp[i-1][j][k]+a[sum][1]);
				if(j>0) mx = max(mx,dp[i][j-1][k]+a[sum][2]);
				if(k>0) mx = max(mx,dp[i][j][k-1]+a[sum][3]);
				dp[i][j][k] = mx;
			}
		}
	}
	int ans = 0;
	for(int i = 0;i<=n/2;++i){
		for(int j = 0;j<=n/2;++j){
			int k = n-i-j;
			if(k>n/2) continue;
			ans = max(ans,dp[i][j][k]);
		}
	}
	cout<<ans<<'\n';
}

//special-A

bool cmpA(int x,int y){
	return x>y;
}
void solveA(){
	int b[100009];
	for(int i = 1;i<=n;++i) b[i] = a[i][1];
	sort(b+1,b+n+1,cmpA);
	int ans = 0;
	for(int i = 1;i<=n/2;++i){
		ans+=b[i];
	}
	cout<<ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		cin>>n;
		bool fA = 1,fB = 1;
		for(int i = 1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) fA = 0;
			if(a[i][3]!=0) fB = 0;
		}
		if(n<=200) solve_dp();
		else if(fA) solveA();
		//else solveB();
	}
	fclose(stdin);
	fclose(stdout);
}

