#include<bits/stdc++.h>

using namespace std;

#define LL long long

const int N=2e4+7;
const LL mod=998244353;

LL n,m,cnt,ans,sum,a,b;
LL A[N],dp[N];

LL fpow(LL x,LL y){
	LL fans=1,fbas=x%mod;
	while(y){
		if(y&1){
			fans*=fbas;
			fans%=mod;
		}
		fbas*=fbas;
		fbas%=mod;
		y>>=1;
	}
	return fans;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	ans=fpow(2,n);
	cnt=(1+n+n*(n-1)/2)%mod;
	sort(A+1,A+n+1);
	dp[0]++;dp[A[1]]++;dp[A[2]]++;dp[A[1]+A[2]]++;
	sum=0;ans-=cnt;ans=(ans+mod)%mod;
	for(int i=3;i<=n;i++){
		sum=0;
		for(int j=0;j<=A[i];j++){
			sum+=dp[j];
		}
		sum=(sum-i+mod)%mod;
		for(int j=A[n];j>=A[i];j--){
			dp[j]+=dp[j-A[i]];
		}
		ans=(ans-sum+mod)%mod;
	}
	cout<<ans<<endl;
	
	return 0;
}
