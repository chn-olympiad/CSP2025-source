#include<bits/stdc++.h>
using namespace std;
long long ans,n,a[1000005],ok[100],b,MOD=998244353;
void dfs(long long pos,long long maxx,long long zhi){
	if(pos>n){
		if(zhi>maxx*2)ans++;
		ans%=MOD;
		return;
	}
	ok[pos]=1;
	dfs(pos+1,max(maxx,a[pos]),zhi+a[pos]);
	ok[pos]=0;
	dfs(pos+1,maxx,zhi);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b=max(b,a[i]);
	}
	if(n<=20){
		dfs(1,0,0);
		printf("%lld",ans%MOD);
		return 0;
	}
	if(b==1){
		ans=1;
		for(long long i=1;i<=n;i++){
			ans*=2;
			ans%=MOD;
		}
		ans=ans+MOD-1;
		ans%=MOD;
		ans=ans+MOD-n;
		ans%=MOD;
		ans=ans+MOD-(n*(n-1)/2);
		ans%=MOD;
		printf("%lld",ans%MOD);
	}
	return 0;
}
