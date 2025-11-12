#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=3e6+5;
ll a[N],sum[N];
int dp[N];
map<ll,int>mp;
//int ch[M][2];
//int pos[M]; bool ed[N];
//int srch(int val){
//
//	int p=0;
//	for(){
//		if(ch[p][]){
//			p=ch[p][];
//		}
//		else return -1;
//	}
//	
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll k,n; cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i],sum[i]=sum[i-1]^a[i];
	mp[0]=0;
	for(int i=1;i<=n;++i){
//		cout<<i<<" "<<sum[i]<<' '<<(sum[i]^k)<<'\n';
		if(mp.count(sum[i]^k)){//cout<<"ops"<<i<<"\n";
			int ky=mp[sum[i]^k];
			dp[i]=max(dp[i-1],dp[ky]+1);
		}
		else dp[i]=dp[i-1];
		mp[sum[i]]=i;
	}
	cout<<dp[n];
	return 0;
}