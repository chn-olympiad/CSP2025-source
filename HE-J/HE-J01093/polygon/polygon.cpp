#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1],lile=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int lil=a[i];
				a[i]=a[j];
				a[j]=lil;
			}
		}
	}
	int chang[n+1][n+1]={0};
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==1){
				chang[i][j]=a[j]+chang[i][j-1];
			}else{
				chang[i][j]=chang[1][j]-chang[1][i-1];
			}
		}
	}
	int dp[n+1][n+1]={0};//到哪一个数字 用几个数字 
	for(int i=3;i<=n;i++){
		for(int j=3;j<=i;j++){
			if(chang[i-j+1][i]>a[n]*2){
				dp[i][j]=max(dp[i-1][j]+1,dp[i][j-1]+1);
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[n][n];
	return 0;
}
