#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],s,mi[5005]={1};
void dfs(long long t,long long p,long long r){
	if(p==r) return;
	if(t>a[p]){
		s=(s+mi[p-r-1])%998244353;
		return;
	}
	dfs(t+a[r+1],p,r+1);
	dfs(t,p,r+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) mi[i]=2*mi[i-1]%998244353;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if(a[n]==1){
		printf("%lld",mi[n]-n*(n+1)/2-1);
		return 0;
	}else{
		for(int i=3;i<=n;i++) dfs(0,i,0);
		printf("%lld",s);
	}
	return 0;
}
