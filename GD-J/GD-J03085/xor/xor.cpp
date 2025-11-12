#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000005],b[1000005],s[1000005],last[1<<22],dp[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	s[1]=a[1];
	memset(last,-1,sizeof(last));
	last[0]=0;
	last[s[1]]=1;
	if(s[1]==k)b[1]=0;
	else b[1]=-1;
	for(long long i=2;i<=n;i++){
		s[i]=s[i-1]^a[i];
		if(last[k^s[i]]>=0){
			b[i]=last[k^s[i]];
		}else{
			b[i]=-1;
		}
		last[s[i]]=i;
	}
	for(long long i=1;i<=n;i++){
		if(b[i]>=0){
			dp[i]=dp[b[i]]+1;
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	printf("%lld",dp[n]);
	return 0;
}
