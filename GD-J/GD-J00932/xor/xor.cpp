#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[900],ans,b[900];
void dfs(ll c,ll p,ll t,ll x,ll r){
	if(p>n){
		ans=max(t,ans);
		return;
	} 
	if(x==-1&&!r){
		for(int i=c;i<=n;i++){
	    	dfs(i,i,t,-1,1);
		} 
	}  	
	else if(x==-1&&r) x=a[p];
	else x^=a[p];
	if(x==k){
		dfs(p+1,p+1,t+1,-1,0);
	}
	dfs(c,p+1,t,x,r);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1,0,-1,0);
	cout<<ans;
	return 0;
} 
