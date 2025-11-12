#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
const int MOD=998244353;
int n,a[N],ans;
void dfs(int l,int cnt,int num){
	if(num>=3&&cnt>2*a[l]){
		ans=(ans+1)%MOD;
	}
	for(int i=l+1;i<=n;++i){
		dfs(i,cnt+a[i],++num);
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-2;++i){
		dfs(i,a[i],1);
	}
	cout<<ans%MOD;
	return 0;
}