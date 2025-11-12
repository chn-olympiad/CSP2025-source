#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=10010;
int n,a[maxn],cnt[maxn];
long long ans=0,dp[maxn];
long long q_pow(int x,int v){
	long long ret=1,ffcnt=x;
	while(v>0){
		if(v%2==1){
			ret*=ffcnt; ret%=mod;
		}
		ffcnt=ffcnt*ffcnt; ffcnt%=mod;
		v/=2;
	} 
	return ret;
}
long long c(int k){
	long long tep=1;
	for(int i=n-k+1;i<=n;i++){
		tep*=i;
		tep%=mod;
	}
	for(int i=1;i<=k;i++){
		tep*=q_pow(i,mod-2);
		tep%=mod;
	//	tep/=i;
	}
	return tep;
}
//dp表示最大值为a[i] 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[n];j>=0;j--){
			int p=j-a[i];
			if(p<0) continue;
			dp[j]+=dp[p];
			dp[j]%=mod;
		}
	}
	long long ret=0;
	for(int i=3;i<=n;i++){
		ret+=c(i);
		ret%=mod;
	}
	for(int i=1;i<=a[n];i++) dp[i]-=cnt[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			if(dp[j]<0) continue;
			ans+=dp[j]; ans%=mod;
		}
	}
	printf("%lld",(ret-ans+mod)%mod);
	return 0;
}
