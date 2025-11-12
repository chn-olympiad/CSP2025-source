#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
ll n,a[5005],maxx,nmaxx,sum,ans;
ll fastpow(int a,int n){
	if(n==0)return 1;
	if(n==1)return a%mod;
	ll u=fastpow(a,(n>>1));
	if(n&1)return u*u%mod*a%mod;
	else return u*u%mod;
}
void dfs(int k){
	if(k>n){
		if(sum>maxx*2)ans++,ans%=mod;
		return ;
	}
	int t=maxx;
	sum+=a[k];maxx=max(maxx,a[k]);
	dfs(k+1);
	sum-=a[k];maxx=t;
	dfs(k+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		nmaxx=max(nmaxx,a[i]);
	}
	if(nmaxx<=1){
		ans=fastpow(2,n);
		ans+=mod-1,ans%=mod;
		ans+=mod-n*(n-1)/2,ans%=mod;
		ans+=mod-n,ans%=mod;
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;	
	return 0;
}

