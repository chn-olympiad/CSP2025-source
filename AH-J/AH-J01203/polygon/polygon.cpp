#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],t[5005],ans;
void dfs(long long k,long long sum,long long s,long long mx){
	if(k==n+1){
		if(sum>=3&&s>mx*2) ans++;
		return;
	}
	dfs(k+1,sum+1,s+a[k],max(mx,a[k]));
	dfs(k+1,sum,s,mx);
}
long long mx;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
		mx=max(mx,a[i]);
	}
	if(mx==1){
		ans=1;
		for(long long i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		} 
		cout<<(ans-n-1-n*(n-1)/2+mod)%mod;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
