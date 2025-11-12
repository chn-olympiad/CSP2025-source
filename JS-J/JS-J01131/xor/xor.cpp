#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXM=4e6+5;
long long n,K;
long long a[MAXN],pre[MAXN];
long long dp[MAXN];
long long maxn[MAXM];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&K);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pre[i]=(pre[i-1]^a[i]);
	}
	memset(maxn,-0x3f,sizeof(maxn));
	maxn[0]=0;
	for(int i=1;i<=n;i++){
		long long x=(pre[i]^K);
		dp[i]=max(dp[i-1],maxn[x]+1);
		maxn[pre[i]]=max(maxn[pre[i]],dp[i]);
	}
	cout<<dp[n];
	return 0;
}