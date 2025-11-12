#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,k,a[maxn],sum[maxn],dp[maxn][maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				dp[i][j]=1;
			}
		}
	}
	for(int len=2;len<=n;len++){
		for(int le=1;le+len-1<=n;le++){
			int ri=le+len-1;
			for(int mid=le;mid<=ri-1;mid++){
				dp[le][ri]=max(dp[le][ri],dp[le][mid]+dp[mid+1][ri]);
			}
		}
	}
	printf("%d",dp[1][n]);
	return 0;
}