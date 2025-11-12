#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n;
long long a[5005];
long long c[5005];
long long vis[5005];
long long cnt;
void dfs(long long x,long long y,long long z){
	if(x>n){
		return;
	}
	for(long long i=z;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(x+1,y+a[i],i);
			vis[i]=0;
		}
	}
	if(y>2*a[z]){
//		cout<<x<<' '<<y<<' '<<a[z]<<'\n';
		cnt=(cnt+1)%mod;
	}
}
long long C(long long n,long long m){
	if(c[n]!=-1){
		return c[n];
	}
	long long ans=1;
	for(long long i=1;i<=n;i++){
		ans=(ans*(m-i+1))%mod;
	}
	for(long long i=1;i<=n;i++){
		ans=(ans/i)%mod;
	}
	c[n]=ans;
	return ans%mod;
}
void solve(){
	for(long long i=3;i<n;i++){
//		cout<<C(min(i,n-i),n)<<' ';
		cnt=(cnt+C(min(i,n-i),n))%mod;
	}
	cout<<cnt+1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long mx=-1e9;
	for(long long i=1;i<=n;i++){
		c[i]=-1;
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		solve();
	}else{
		sort(a+1,a+1+n);
		dfs(0,0,1);
		cout<<cnt;
	}
	return 0;
}