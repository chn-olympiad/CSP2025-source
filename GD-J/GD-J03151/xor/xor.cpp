#include<bits/stdc++.h>
#define N 5001
using namespace std;
long long n,k,t[N],a[N][N];
long long dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		for(int j=1;j<=i;j++){
			a[j][i]=a[j][i-1]^t[i];
		}
	}
	if(t[1]==k)dp[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=i;j>=1;j--){
			dp[i]=max(dp[i],dp[i-j]+(a[i-j+1][i]==k));
		}
	}
	cout<<dp[n];
	return 0;
}
/*
 1 2 3  4  5

 5 7 15 15 15
 - 6 14 15 15
 - - 8  15 15
 - - -  7  15
*/
