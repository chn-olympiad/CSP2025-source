#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,a[500010];
int pre[500010];
int dp[1010][1010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		pre[i] = pre[i-1] ^ a[i];
	}
	int ma = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if((pre[j] ^ pre[i-1]) == k){
				dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][i-1] + 1);
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
			ma = max(dp[i][j],ma);
		}
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

