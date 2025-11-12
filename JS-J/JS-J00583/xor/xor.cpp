#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,a[500002],sum[500002];
vector<long long>dp;
vector<pair<long long,long long> >sk;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld%lld",&n,&k,&a[1]);
	sum[1]=a[1];
	for(long long i=2;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(long long i=1;i<=n;++i){
		if(a[i]==k){
			sk.push_back({i,i});
			dp.push_back(1);
		}
	}
	for(long long i=1;i<n;++i){
		for(long long j=i+1;j<=n;++j){
			if(sum[j]^sum[i-1]==k){
				sk.push_back({i,j});
				dp.push_back(1);
			}
		}
	}
	for(long long i=1;i<sk.size();++i){
		for(long long j=0;j<i;++j){
			if(sk[j].second<sk[i].first){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	printf("%lld",dp[sk.size()-1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}