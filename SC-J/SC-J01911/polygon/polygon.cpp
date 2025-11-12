#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
ll ans=0;ll n;
vector<int> a(5005);
void dfs(ll maxn,ll sum,ll i){
	if(i==n+1){
		if(sum>2*maxn){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	dfs(maxn,sum,i+1);
	maxn=max(maxn,ll(a[i]));sum+=a[i];
	dfs(maxn,sum,i+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,1);
	cout<<ans;
	return 0;
}