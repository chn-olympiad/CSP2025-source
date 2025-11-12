#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e3+3,mod=998244353;
int n,l[MAXN],jc[MAXN],cnt[MAXN],pre[MAXN];
long long ans=0;
void initjc(){
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=(1LL*jc[i-1]*i)%mod;
	}
}
int qpow(int a,int b){
	int ret=1;
	for(int x=a;b;x=(1LL*x*x)%mod,b>>=1){
		if(b&1)ret=(1LL*ret*x)%mod;
	}
	return ret;
}
int get_sum(){
	int ret=0;
	for(int i=3;i<=n;i++){
		ret=(ret+1LL*jc[n]*qpow(jc[n-i],mod-2)%mod*qpow(jc[i],mod-2)%mod)%mod;
	}
	return ret;
}
void dfs(int now,int sum,int ml,int cnt){
	if(sum>ml*2 && cnt>=3){
		ans=(ans+1)%mod;
		int x=now;
	}
	for(int i=1;i<now;i++){
		dfs(i,sum+l[i],ml,cnt+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxl=0;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		cnt[l[i]]++;
		maxl=max(maxl,l[i]);
	}
	initjc();
	if(maxl==1){
		cout<<get_sum();
	}
	for(int i=1;i<=maxl;i++)pre[i]=pre[i-1]+cnt[i];
	sort(l+1,l+n+1);
	for(int i=1;i<=n;i++){
		dfs(i,l[i],l[i],1);
	}
	cout<<ans;
	return 0;
}
