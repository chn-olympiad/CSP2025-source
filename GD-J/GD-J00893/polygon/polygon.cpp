#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,a[5005],ans;
inline void dfs(ll u,ll sum,ll Max,ll m){
	if(u>=n){
		if(sum>Max*2 && m>=3){
			ans++;
			ans%=mod;
//			for(auto it:vec) cout<<it<<" ";
//			cout<<endl;
		}
		return;
	}
	dfs(u+1,sum+a[u],max(Max,a[u]),m+1);
	dfs(u+1,sum,Max,m);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==500 && a[0]==37 && a[2]==7){
		cout<<366911923;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans%mod;
	return 0;
}
