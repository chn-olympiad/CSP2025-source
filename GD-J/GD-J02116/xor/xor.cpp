#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],s[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			if(dp[j]<dp[i-1])break;
			dp[i]=max(dp[i],dp[j]+((s[i]^s[j])==k));
		}
	}
	printf("%d",dp[n]);
	return 0;
} 
