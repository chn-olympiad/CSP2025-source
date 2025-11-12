#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[6000000],cnt,n,l=1;
void dfs(ll sum,ll mx,ll i,ll c) {
	if(sum>mx*2&&c>=3) {
		cnt=cnt%998244353+1;
		cnt%=998244353;
	}
	if(i>n){
		return;
	}
	dfs(sum+a[i],max(mx,a[i]),i+1,c+1);
	dfs(sum,mx,i+1,c);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(0,0,1,0);
	if(cnt==0)cout<<0;
	else if(cnt==1)cout<<1;	
	else cout<<cnt-2;
	return 0;
}
