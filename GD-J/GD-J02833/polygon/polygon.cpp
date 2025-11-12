#include<bits/stdc++.h>
using namespace std;
long long n,a[10000100],ans,b[100009],mod=998244353;
long long dfs(long long v,long long x,long long l){
	if (v==l+1){
		long long mx=0,sum=0;
		for (long long i=1; i<=l; i++){
			sum+=b[i];
			mx=max(mx,b[i]);
		}
		if (sum>mx*2) return 1;
		else return 0;
	}
	int sum=0;
	for (long long i=x; i<=n; i++){
		b[v]=a[i];
		sum+=dfs(v+1,i+1,l);
	}
	return sum%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (long long i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (long long i=1; i<=n; i++){
		ans+=dfs(1,1,i)%mod;
	}
	cout << ans%mod;
	return 0;
}
