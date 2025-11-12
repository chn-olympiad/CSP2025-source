//GZ-S00344 贵阳市第一中学 甘梓辰
#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[105][105][105],n,m,c[105],t[105],sum[105];
char v[105];
const int mod=998244353;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>(v+1);
	for(int i=1;i<=n;i++){
		cin>>c[i];
		t[c[i]]++;
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+t[i];
	}
	for(int i=1;i<=n;i++){
		if(v[i]=='0'){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++){
					for(int l=0;l<=i;l++){
						if(k+t[j+1]){
							dp[i+1][j+1][k-1+t[j+1]][l]=(dp[i+1][j+1][k-1+t[j+1]][l]+k*dp[i][j][k][l])%mod;
							if(k>1&&(l-t[j+1])>0){
								dp[i+1][j+1][k-2][l-t[j+1]-1]=(dp[i+1][j+1][k-2][l-t[j+1]-1]-k*dp[i][j][k][l]+k*mod)%mod;
							}
						}
						dp[i+1][j+1][k+t[j+1]][l]=(dp[i+1][j+1][k+t[j+1]][l]+dp[i][j][k][l])%mod;
						if(k&&l-sum[j+1]>=0){
							dp[i+1][j+1][k-1][l-sum[j]]=(dp[i+1][j+1][k-1][l-sum[j]]-dp[i][j][k][l]+mod)%mod;
						}
					}
				}
			} 
		}else{
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++){
					for(int l=0;l<=i;l++){
					}
				}
			} 
		}
	}
	return 0;
}

