#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define M 2000005
using namespace std;
ll n,k,a[N],cnt,s[M],dp[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	cnt=0;
	memset(s,-1,sizeof(s));
	s[0]=0;
	for(int i=1;i<=n;i++){
		cnt^=a[i];
		ll op=s[k^cnt];
//		cout<<cnt<<" "<<op<<" "<<dp[op]<<endl;
		if(op>=0) dp[i]=dp[op]+1+dp[i-1];
		else dp[i]=dp[i-1];
		s[cnt]=i;
	}
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	printf("%lld",ans);
	return 0;
}
