#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
int n,k;
ll a[N],s[N],dp[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) s[i] = s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=1;j<=i;j++){
			if((s[i]^s[j-1])==k){
				dp[i] = max(dp[i],dp[j-1]+1);
			}
		}
	}printf("%lld",dp[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
