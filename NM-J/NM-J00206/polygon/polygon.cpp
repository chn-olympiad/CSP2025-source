#include <bits/stdc++.h>
using namespace std;
int x,a[5001],dp[5001][5001],ans,b[10000],o;
int main(){
	scanf("%d",&x);
	for(int i=0;i<x;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+x);
	for(int i=2;i<x;i++){
		int j=0;
		for(int k=i-1;k>j;k--){
			while(a[j]+a[k]<=a[i]){
				j++;
			}
			if(i<j){
				break;
			}
			b[i]+=i-j;
		}
	}
	for(int i=0;i<x;i++){
		int j=0;
		dp[i][i]+=b[i]%998244353;
		for(int k=0;k<i;k++){
			dp[i][k]+=dp[i-1][k]%998244353;
			if(a[k]+a[k]+1>=a[i]){
			dp[i][i]+=dp[i][k]%998244353;}
		}
	}
	printf("%d",dp[x-1][x-1]);
	return 0;
}
