#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a[5005];
bool flag[5005];
ll ans;
const ll mod = 998244353;
void dfs(ll sum,int maxn,int pos){
	if(sum>maxn*2){
		ans++;
		ans%=mod;
	}
	if(pos!=n){
		for(int i=pos+1;i<=n;i++){
			dfs(sum+a[i],max(maxn,a[i]),i);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],a[i],i);
	}
	cout<<ans%mod;
	return 0;
}
