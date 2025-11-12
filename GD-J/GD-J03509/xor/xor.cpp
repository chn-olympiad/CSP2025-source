#include <bits/stdc++.h>
using namespace std;
unsigned long long n,k,a[500005],b[500005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>0;j--){
			if((b[i]^b[j-1])==k) {
				dp[i]=max(dp[i],dp[j-1]+1);
				//cout<<j<<' '<<i<<' '<<(b[i]^b[j-1])<<' '<<dp[i]<<endl;
				break;
			}
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
