#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll ans;
ll mod=998244353;
int a[5005];
void dfs(ll pos,ll x,ll sum,int mx){
	if(pos==n+1){
		if(x>=3&&sum>2*mx){
			ans++;
		}
		return ;
	}

	dfs(pos+1,x+1,sum+a[pos],max(mx,a[pos]));
	dfs(pos+1,x,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans%mod;
	return 0;
}