#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],x[N]={};
ll n,k;
ll dp[N]={};
set<ll> mp;
map<ll,ll> mp2;
int main(){
	//cout<<(1<<20);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		x[i]=(x[i-1]^a[i]);
		if(x[i]==k) dp[i]++;
		//cout<<"*"<<x[i]<<'*';
	}
	//cout<<endl<<endl;
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i],dp[i-1]);
		if(mp.count(x[i]^k)){
		//	cout<<x[i]<<" "<<(x[i]^k)<<endl;
		//	cout<<i<<" "<<mp2[x[i]^k]<<endl;
			int j=mp2[x[i]^k];
			dp[i]=max(dp[i],dp[j]+1);
		}
		mp.insert(x[i]);
		mp2[x[i]]=i;
	}
//	for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
//	cout<<endl;
	cout<<dp[n]<<endl;
//	cout<<sizeof(mp2)/1024/1024<<" "<<sizeof(mp)/1024/1024<<" "<<sizeof(dp)/1024/1024<<endl;// 
}
