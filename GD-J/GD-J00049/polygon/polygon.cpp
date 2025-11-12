#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=998244353; 
ll n, a[1010], ans;
void dfs(ll step, ll tot, ll mx, ll sum, ll cnt){
	if(cnt==tot){
		if(sum>mx*2){
			ans++;
			ans=ans%MOD;
		}
		return ;
	}
	if(step>n){
		return ;
	}
	dfs(step+1, tot, max(mx, a[step]), sum+a[step], cnt+1);
	dfs(step+1, tot, mx, sum, cnt);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=3; i<=n; i++){
		dfs(1, i, 0, 0, 0);
	}
	cout<<ans%MOD;
	return 0;
}
