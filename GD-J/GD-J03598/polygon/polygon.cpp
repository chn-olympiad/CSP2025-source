#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int mod=998244353;
int n;
int a[5005];
ll ans=0;
void dfs(int i,int sum,int mx,int h,bool flag){
	if (h>=3 && sum>2*mx && flag){
		ans=(ans+1)%mod;
	} 
	if (i==n+1) return;
	dfs(i+1,sum+a[i],max(mx,a[i]),h+1,1);
	dfs(i+1,sum,mx,h,0);
}
ll c(ll n,ll m){
	ll res=1;
	for (int i=m+1;i<=n;i++) res=res*i%mod;
	for (int i=1;i<=n-m;i++) res/=i;
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=0;
	for (int i=1;i<=n;i++){
		mx=max(mx,a[i]);
		cin>>a[i];
	} 
	if (mx==1){
		ll ans2=0;
		for (int i=3;i<=n;i++){
			ans2+=c(n,i);
		}
		cout<<ans2;
		return 0;
	}
	dfs(1,0,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
