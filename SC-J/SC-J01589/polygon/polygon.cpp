#include<bits/stdc++.h>
using namespace std;
const long long N=5e3+10;
const long long mod=998244353;
long long n,a[N];
long long ans;
void dfs(long long d,long long sum,long long maxn,long long g){
	if(d==n+1){
		if(sum>maxn*2&&g>=3){
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(d+1,sum,maxn,g);
	dfs(d+1,sum+a[d],max(maxn,a[d]),g+1);
}
long long fast_pow(long long a,long long b){
	long long ans=1;
	while(b){
		if(b&1){
			ans*=a;
			ans%=mod;
		}
		a=a*a;
		a%mod;
		b>>=1;
	}
	return ans;
}
long long C(long long a,long long b){
	long long ans=1;
	for(long long i=b;i>b-a;i--){
		ans=ans*i%mod;
	}
	for(int i=1;i<=a;i++){
		ans=ans*fast_pow(i,mod-2)%mod; 
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	long long maxa=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxa=max(maxa,a[i]);
	}
	if(n<=20){
		dfs(1,0,0,0);
		printf("%lld",ans);
	}
	else if(maxa==1){
		for(long long i=3;i<=n;i++){
			ans=(ans+C(i,n))%mod;
		}
		printf("%lld",ans);
	}
	else{
		dfs(1,0,0,0);
		printf("%lld",ans);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}