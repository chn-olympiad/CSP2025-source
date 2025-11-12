#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
int n,a[114511],ans;
void dfs(int i,int k,int s,int m){
	if(k==0){
		if(m*2<s) ans=(ans+1)%mod;
		return;
	}
	if(n-i+1<k) return;
	dfs(i+1,k-1,s+a[i],a[i]);
	dfs(i+1,k,s,m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++) dfs(1,i,0,0);
	cout<<ans;
	return 0;
} 
