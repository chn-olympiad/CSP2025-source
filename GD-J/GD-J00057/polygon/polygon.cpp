#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans=0;
void dfs(long long k,long long s,long long maxx,long long num){
	if(k>n){
		if(s>=3 && num>maxx*2) ans=(ans+1)%mod;
		return;
	}
	dfs(k+1,s,maxx,num);
	dfs(k+1,s+1,max(maxx,a[k]),num+a[k]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
