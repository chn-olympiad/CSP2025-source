#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int dp[n][n];
	for(int i=0;i<n;i++){
		dp[i][i]=a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			dp[i][j]=dp[i][j-1]^a[j];
		}
	}
	int ans=0;
	int s=-1;
	for(int j=0;j<n;j++){
		for(int i=0;i<=j;i++){
			if(i>s&&dp[i][j]==k){
				ans++;
				s=i;
				break;
			}
		} 
	}
	cout<<ans; 
	return 0;
}