#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[100005][5],n;
ll dfs(ll k,ll ca,ll cb,ll cc,ll s){
	if(ca>n/2||cb>n/2||cc>n/2)return 0;
	if(k>n)return s;
	return max({
		dfs(k+1,ca+1,cb,cc,s+a[k][1]),
		dfs(k+1,ca,cb+1,cc,s+a[k][2]),
		dfs(k+1,ca,cb,cc+1,s+a[k][3]),
	});
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n<=40){
			cout<<dfs(1,0,0,0,0)<<endl;
		}else{
			cout<<0;
		}
	}
	return 0;
}
