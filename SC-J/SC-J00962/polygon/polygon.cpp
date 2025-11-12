#include<bits/stdc++.h>
using namespace std;
long long a[5005];
const long long mod=998244353;
long long n,cnt=0;
void dfs(long long p,long long len,long long mx,long long sum) {
	if(len>=3 && sum>mx*2) {
		cnt=(cnt+1)%mod;
	}
	if(p==n) {
		return ;
	}
	for(long long i=p+1; i<=n; i++) {
		dfs(i,len+1,a[i],sum+a[i]);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1; i<=n; i++) {
		dfs(i,1,a[i],a[i]);
	}
	cout<<cnt;
	return 0;
}
