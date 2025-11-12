#include<bits/stdc++.h> 
using namespace std;
const int MAX=5e5+5;
long long n,k;
long long a[MAX];
long long dp[MAX];
long long temp[MAX];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		temp[i]=a[i];
		dp[i]=dp[i-1];
		if(temp[i]==k) dp[i]=dp[i-1]+1;
		for(int j=i-1;j>=1;j--){
			temp[j]=(temp[j+1] xor a[j]);
			if(temp[j]==k) dp[i]=max(dp[i],dp[j-1]+1);
		}
	}
	printf("%lld",dp[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
