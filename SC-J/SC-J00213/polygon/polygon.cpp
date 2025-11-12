#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll ans,n,a[5005],mod=998244353;
void dfs(ll x,ll cnt,ll Max,ll sum){
	if(cnt>=3&&sum>2*Max) ans++;
	for(ll i=x+1;i<=n-(2-cnt,0);i++){
		if(a[i]>Max)
			dfs(i,cnt+1,a[i],sum+a[i]);
		else dfs(i,cnt+1,Max,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1ll*0,1ll*0,1ll*0,1ll*0);
	cout<<ans;
	return 0;
}