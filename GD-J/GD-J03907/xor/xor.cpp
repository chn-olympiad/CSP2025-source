#include <bits/stdc++.h>
using namespace std;
int n,m,k,s,t,a[500005],f[2005][2005],dp[2005][2005];
bool op[2005][2005];


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >>k;
	for(int i =1;i<=n;i++){
		cin >> a[i];
		f[i][i] = a[i];
		if(f[i][i] == k){
		dp[i][i] = 1;
		op[i][i] = 1;s++;}
	}
	
	for(int len = 2;len<=n;len++){//×Ü³¤Îªlen 
		for(int i = 1;i+len-1<=n;i++){
		f[i][i+len-1] = f[i][i+len-2] ^ f[i+len-1][i+len-1]; 
		if(f[i][i+len-1] == k){
		
		op[i][i+len-1] = 1;
		s++;}
	}
	}
	for(int len = 2;len<=n;len++){
		for(int i =1;i+len-1<=n;i++){
			dp[i][i+len-1] = max(dp[i][i+len-2]+dp[i+len-1][i+len-1],dp[i+1][i+len-1] + dp[i][i]);
			dp[i][i+len-1]=max(1 & op[i][i+len-1],dp[i][i+len-1]);	
		}
	}
	cout << dp[1][n];
	
	
	return 0;
}
