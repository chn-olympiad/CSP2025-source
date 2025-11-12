#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5;
int dp[N][N],a[N][N],n,k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i][i]);
		if(a[i][i]==k)dp[i][i]=1;
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			a[i][j]=a[i][j-1]^a[j][j];
			if(a[i][j]==k)dp[i][j]=1;
			for(int z=i+1;z<=j;z++){
				dp[i][j]=max(dp[i][j],dp[i][z-1]+dp[z][j]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}