#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5000+10,MOD=998244353;
ll n,a[N],dp[N],ans,maxn,dis;
void dfs(ll i,ll sum){
	if(i==dis)return ;
	if(sum+a[i]>a[dis]){
		ans++;
		ans%=MOD;
	}
	dfs(i+1,sum+a[i]);
	dfs(i+1,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>maxn*2)cout<<1;
		return 0;
	}
	if(maxn==1){
		for(ll i=3;i<=n;i++){
			ll ansa=1;
			if(i!=n){
				for(ll j=1;j<=i;j++){
					ansa*=(n-j+1);
					ansa/=j;
					ansa%=MOD;
				}
			}
			ans+=ansa;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=n;i>=1;i--){
		dis=i;
		dfs(1,0);
	}
	cout<<ans;
	return 0;
}
