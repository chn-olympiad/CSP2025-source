#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();long long x=0,g=1;
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') g=-1,c=getchar();
	while(c>='0' && c<='9'){
		x=(x*10)+c-'0';
		c=getchar();
	}
	return x*g;
}
const long long mod=998244353;
long long n,a[5005],ans;
void dfs(long long now,long long sum,long long maxn,long long tot){
	if(now>n){
		if(tot<3) return;
		if(sum>2*maxn) ans++;
		ans%=mod;
		return;
	}
	dfs(now+1,sum+a[now],a[now],tot+1);
	dfs(now+1,sum,maxn,tot);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(long long i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	if(a[1]+a[2]>a[n]){
		ans=1;
		for(long long i=1;i<=n;i++){
			ans=ans*2%mod;
		}
		cout<<(ans+mod*2-n-(n-1)*n/2-1)%mod<<"\n";
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans%mod;
	return 0;
}