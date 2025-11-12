#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N],dp[N][N];//dp[l][r]表示从l到r的区间内有dp[l][r]个区间的异或和为k 
bool checkIsK(int L,int R){
	int sum=a[L];
	for(int l=L+1;l<=R;l++){
		sum=sum^a[l];
	}
	if(sum==k){
		return true;
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(dp,-0x3f,sizeof dp);
	dp[1][1]=a[1];
	for(int len=1;len<=n;len++){
		for(int l=len;l+len<=n;l++){
			int r=l+len;
			if(checkIsK(l,r-1)){
				dp[l][r]=max(dp[l][r],dp[l][r-1]+1);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}
