#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,l[5002],ml = -1;
bool t[5002];
ll ans = 0,mod = 998244353;
ll qpow(int x,int y){
	ll as = 1;
	while(y){
		if(y&1)as = as*x%mod;
		x = x*x%mod;
		y>>=1;
	}
	return as%mod;
}
void dfs(int u,int sum){
	if(u==n+1){
		if(sum<3)return ;
		int sm = 0,mx = -1;
		for(int i=1;i<=n;i++){
			if(t[i]==1){
				sm+=l[i];
				mx = max(mx,l[i]);
			}
		}
		if(sm>2*mx)ans++;
		ans = ans%mod;
		return ;
	}
	t[u] = 1;
	dfs(u+1,sum+1);
	t[u] = 0;
	dfs(u+1,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		ml = max(ml,l[i]);
	}
	if(ml==1){
		ll zn = qpow(2,n);
		ll w = (1+n+n*(n-1)/2)%mod;
		cout<<zn-w;
		return 0;
	}
	dfs(1,0);
	cout<<ans%mod;
	return 0;
}


