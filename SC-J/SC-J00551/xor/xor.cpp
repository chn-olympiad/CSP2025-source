#include<bits/stdc++.h>//need long long
using namespace std;
using ll=long long;
map<int,int> mp;
const int N=5e5+5;
int n,k,a[N],pre[N],mch[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=a[i]^pre[i-1];
	}
	for(int i=0;i<=n;i++){
		if(mp.find(k^pre[i])!=mp.end()){
			mch[i]=mp[k^pre[i]];
		}
		else mch[i]=-1;
		mp[pre[i]]=i;
//		cout<<mch[i]<<' ';
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(mch[i]!=-1){
			dp[i]=max(dp[i],dp[mch[i]]+1);
		}
//		cout<<dp[i]<<" ";
	}
	cout<<dp[n];
	return 0;
}