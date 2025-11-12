#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+5,MAXA=256;
int n,k,sum[N];
int dp[N][MAXA];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		sum[i]=(sum[i-1]^x);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int tmp=(sum[j-1]^sum[i]);
			dp[i][tmp]=max(dp[i][tmp],dp[j-1][tmp]+1);
		}
		for(int j=1;j<256;j++)dp[i][j]=max(dp[i][j],dp[i-1][j]);
	}
	cout<<dp[n][k];
	return 0;
}