#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+10,MOD=998244353;
ll n,a[N],ans[N],cnt;
void dfs(ll cur,ll pre,ll sum,ll maxn){
	for(ll i=pre+1;i<=n;i++){
		ans[cur]=i;
		if(cur>=3&&sum+a[i]>2*max(maxn,a[i])){
			cnt++;
			cnt%=MOD;
		}
		dfs(cur+1,i,sum+a[i],max(maxn,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<cnt;
	return 0;
}
