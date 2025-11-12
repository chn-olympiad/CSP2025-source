# include <bits/stdc++.h>
using namespace std;
int n,k,last=1;
int a[500005];
int dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=a[i]^a[i-1];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[last-1];
		for(int j=i;j>=last;j--){
			if((a[i]^a[j-1])==k){
				dp[i]++;
				last=i+1;
				break;
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
} 