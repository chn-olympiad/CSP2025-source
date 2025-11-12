#include <bits/stdc++.h>
using namespace std;
const long long N=5010,M=998244353;
long long a[N],dp[N][N],dpl[N][N];
bool cmp(long long x,long long y){
	return x>y;
}
int Q(long long x){
	if(x<=0) return 1;
	return (Q(x-1)*2)%M;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++){
		for(long long j=a[1];j>=a[i];j--){
			dp[i][j]=dpl[i-1][j-a[i]]+1;
			dpl[i][j]=dp[i][j]+dpl[i-1][j];
			dpl[i][j]%=M;
		}
	}
	for(long long i=1;i<=n;i++){
		ans+=Q(n-i)-(dpl[n][a[i]]-dpl[i][a[i]]+1);
		ans%=M;
	}
	cout<<ans;
	return 0;
}