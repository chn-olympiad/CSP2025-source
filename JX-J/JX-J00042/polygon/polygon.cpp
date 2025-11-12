#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long Mod=998244353;
int n;
ll ans;
int a[5005];
void dfs(ll sum,ll x,ll t,ll k){
	if(sum>k){
		ans=(ans+(((ll)pow(2,t-x))%Mod))%Mod;
		return ;
	}
	if(x==t)return ;
	dfs(sum,x+1,t,k);
	dfs(sum+a[x],x+1,t,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(0,1,i,a[i]);
	}
	ans=ans%Mod;
	cout<<ans<<endl;
	return 0;
}
