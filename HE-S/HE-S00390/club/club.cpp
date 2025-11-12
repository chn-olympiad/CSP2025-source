#include<bits/stdc++.h>
using namespace std;
const int maxn=205;

void run(){
	int n;
	cin>>n;
	int a[maxn][4];
	for(int i=1;i<=n;++i){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	int dp[maxn][maxn][maxn]={};//dp[i][j][k]
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j){
			for(int k=0;k<=i-j;++k){
				if(j>0){
//					cout<<'j';
					dp[i][j][k]=max(dp[i-1][j-1][k]+a[i][1],dp[i][j][k]);
				}
				if(k>0){
//					cout<<'k';
					dp[i][j][k]=max(dp[i-1][j][k-1]+a[i][2],dp[i][j][k]);
				}
				if(i-j-k>0){
//					cout<<'l';
					dp[i][j][k]=max(dp[i-1][j][k]+a[i][3],dp[i][j][k]);
				}
//				cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
				if(i==n && j<=n/2 && k<=n/2 && i-j-k<=n/2) ans=max(ans,dp[i][j][k]);
			}
		} 
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(~--t){
		run();
	}
}
