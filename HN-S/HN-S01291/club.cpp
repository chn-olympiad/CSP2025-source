#include <iostream>
#include <cstdio>
#include <algorithm>
//#include <queue>
#define int long long
using namespace std;

int n;
int a[100005][5];
int b[100005];
int dp[205][105][105];
//struct node{
//	int a,b;
//	bool operator<(const node &x) const{
//		return a-b<x.a-x.b;
//	}
//};
//struct node2{
//	int a,b;
//	bool operator<(const node &x) const{
//		return b-a<x.b-x.a;
//	}
//};
void solveA(){
	for(int i = 1;i<=n;i++){
		b[i] = a[i][1];
	} 
	sort(b+1,b+1+n,greater<int>()  );
	int ans = 0;
	for(int i = 1;i<=n/2;i++){
		ans+=b[i];
	} 
	cout<<ans<<endl;
}
void solution(){
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<=min(i,n/2);j++){
			for(int k = 0;k<=min(i,n/2);k++){
				dp[i][j][k] = 0;
			}
		}
	}
	cin>>n;
	bool flag = true;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=3;j++){
			cin>>a[i][j];
		} 
		if(a[i][2]!=0||a[i][3]!=0) flag = false;
	} 
	if(flag){
		solveA();
		return ;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=min(i,n/2);j++){
			for(int k = 0;k<=min(i,n/2);k++){
				if(i-j-k>n/2) continue;
				if(i-j-k>=1)
					dp[i][j][k] = dp[i-1][j][k]+a[i][3]; 
				if(j>=1){
					dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
				}
				if(k>=1){
					dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i<=min(n,n/2);i++){
		for(int j = 0;j<=min(n,n/2);j++){
			if(n-i-j>n/2) continue;
			ans = max(ans,dp[n][i][j]);
//			cout<<i<<' '<<j<<' '<<ans<<endl;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _;
	cin>>_;
	while(_--){
		solution();
	} 
	return 0;
}

