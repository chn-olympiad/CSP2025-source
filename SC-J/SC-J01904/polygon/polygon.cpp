#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll mod=998244353;
ll n,a[5005],ans,s[5];
//bool vis[5005];
void dfs(ll x,ll sum,ll step,ll limt,ll mx){
	if(step>limt){
		if(sum>2*mx){
			ans++;
			ans%=mod;
		}
		return;
	}
	if(x>n) return;
	dfs(x+1,sum+a[x],step+1,limt,max(mx,a[x]));
	dfs(x+1,sum,step,limt,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=3;i<=n;++i){
		dfs(1,0,1,i,0);
	}
	cout<<ans;
	return 0;
}