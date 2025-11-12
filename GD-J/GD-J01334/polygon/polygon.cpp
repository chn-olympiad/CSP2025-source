//polygon 40
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5007,mod=998244353;
ll n;
ll a[N],cnt;
void dfs(int t,int y,int sum){
	if(t==n+1){
		if(sum>2*y) cnt++;
		cnt%=mod;
		return;
	}
	dfs(t+1,y,sum);
	dfs(t+1,a[t],sum+a[t]);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll ma=0;
	for(int i=1;i<=n;i++) ma=max(ma,a[i]);
	if(ma==1){
		ll sum[N]={0},sm[N]={0};
		ll anss=0;
		for(int i=1;i<=n-2;i++) sum[i]=(sum[i-1]+i)%mod;
		for(int i=1;i<=n-2;i++) sm[i]=(sm[i-1]+sum[i])%mod;
		for(int i=1;i<=n-2;i++) anss=(anss+sm[i])%mod;
		cout<<anss%mod;
		return 0;	
	}
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<cnt%mod;
	return 0;
}
