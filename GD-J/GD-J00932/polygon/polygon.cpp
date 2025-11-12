#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,a[10000],b[10100];
void dfs(ll k,ll p,ll c,ll r,ll h){
	if(r>n+1) return;
	if(p>k){
		if(h>2*c){
		   ans++;
		}
		ans%=998244353;
		return;
	}
	dfs(k,p+1,max(c,a[r]),r+1,h+a[r]);
	dfs(k,p,c,r+1,h);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(i,1,0,1,0);
	}
	cout<<ans;
	return 0;
} 
