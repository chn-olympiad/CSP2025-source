#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,k,a[N];
namespace sixty{
	ll dp[N],s[N],mx[N],ma;
	void solve(){
		for(int i=1;i<=n;i++) s[i]=s[i-1] xor a[i];
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				if((s[i] xor s[j]) != k) continue; 
				dp[i]=max(dp[i],mx[j]+1);
			}mx[i]=max(mx[i-1],dp[i]);
		}
		for(int i=1;i<=n;i++) ma=max(ma,dp[i]);
		cout<<ma;
	}
}
namespace forty{
	ll dp[N],s[N],mx[N],ma;
	map<ll,ll>mp;
	void solve(){
		for(int i=1;i<=n;i++) s[i]=s[i-1] xor a[i], mp[s[i]]=-1;
		mp[0]=0;
		for(int i=1;i<=n;i++){
			ll t=(s[i] xor k);
			if(mp[t]==-1){mp[s[i]]=i;mx[i]=mx[i-1];continue;}
			dp[i]=mx[mp[t]]+1;
			mp[s[i]]=i, mx[i]=max(mx[i-1],dp[i]);
		}
		for(int i=1;i<=n;i++) ma=max(ma,dp[i]);
		cout<<ma;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=1000) sixty::solve();
	else forty::solve();
	return 0;
}
/*
nlogn解法
map+数学+贪心法 O(nlogn) 可得100分 
O(n^2)可得60分 
*/
