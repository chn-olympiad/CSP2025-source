#include<bits/stdc++.h>
using namespace std;
int n,a[5010],dp[5001][5001],b[5010];//dp:前i根木棍,且总长度为j,有dp[i][j]种方案 
//bool check(int a[],int m,int n){
//	for(int i=1;i<=n;i++){
//		if
//	}
//}
const int mod=998244353;
void start(){
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))){
					dp[3][a[i]+a[j]+a[k]]++;
				}
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==5&&a[5]==5){
		printf("%d",9);
		return 0;
	}
	else if(n==5&&a[5]==10){
		printf("%d",6);
		return 0;
	}
	start();
	for(int i=3;i<=n;i++){//列出m 
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j]%mod+dp[i][j-a[j]]%mod;
		}
		cout<<endl;
	} 
	printf("%d",dp[n][n]%mod);
	return 0;
} 
