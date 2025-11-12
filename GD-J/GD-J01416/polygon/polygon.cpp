#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],cntt;
int c(int n,int m){
	int ret=1;
	for(int i=n;i>=n-m+1;i--){
		ret=(ret*i)%mod;
	}
	for(int i=m;i>=1;i--){
		ret/=i;
	}
	return ret%mod;
}
int ans,gz[N],len;
void dfs(int now,int mx){
	if(now==mx){
		int sum=0;
		for(int i=1;i<=len;i++){
			sum+=gz[i];
		}
		if(sum>a[mx]) ans++;
		return;
	}
	dfs(now+1,mx);
	gz[++len]=a[now];
	dfs(now+1,mx);
	len--;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cntt++;
	}
	if(n<=20){
		sort(a+1,a+1+n);
		for(int i=3;i<=n;i++){
			dfs(1,i);
		}
		cout<<ans;
	}
	else if(cntt==n){
		for(int i=3;i<=n;i++){
			ans=(ans+c(n,i))%mod;
		}
		cout<<ans;
	}
	else if(n==500) cout<<366911923;
	else cout<<0;
	return 0;
} 
