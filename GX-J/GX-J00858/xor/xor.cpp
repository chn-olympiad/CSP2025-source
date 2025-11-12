#include<bits/stdc++.h>
using namespace std;
int a[100005],d[100005];
int ans=0;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//if(a[i]==k) dp[i][i]++;
		d[i]=d[i-1]^a[i];
		//cout<<d[i]<<endl;
	}
	int dp[n+5][n+5]={0};
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if((d[j]^d[i-1])==k) dp[i][j]=1;
			if(i==j&&a[i]==k) dp[i][j]=1;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int m=i;m<j;++m){
				dp[i][j]=max(dp[i][j],dp[i][m]+dp[m+1][j]);
			}
		}
	}
	/*for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<dp[1][n]<<endl;
	return 0;
}
