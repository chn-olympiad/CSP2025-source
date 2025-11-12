#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+10,mod=998244353;
int n,a[N];
ll ans;
ll dfs(int l,int r,int k){
	ll res=(a[l]>k);
	if(l!=r){
		res=(res+dfs(l+1,r,k-a[l]))%mod;
		res=(res+dfs(l+1,r,k))%mod;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)ans=(ans+dfs(1,i-1,a[i]))%mod;
	cout<<ans;
	return 0;
} 
