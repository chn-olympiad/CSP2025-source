#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10, mod=998244353;
ll n,a[N],ans;
namespace forty{
	void dfs(ll x, ll sum, ll ma){
		if(x==n+1){
			if(sum>2*ma) ans++, ans%=mod;
			return;
		}
		dfs(x+1,sum+a[x],max(ma,a[x]));
		dfs(x+1,sum,ma);
	}
	void solve(){
		dfs(1,0,0);
		cout<<ans%mod;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20) forty::solve();
	return 0;
}
