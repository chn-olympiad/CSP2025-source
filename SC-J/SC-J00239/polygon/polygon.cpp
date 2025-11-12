# include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long s,ans;
int n;
int a[5005];
void qpow(int m){
	s=2;
	ans=1;
	while(m>0){
		if(m&1){
			ans=ans*s%mod;
		}
		s=s*s%mod;
		m>>=1;
	}
}
void dfs(int now,int sum,int maz,int ch){
	if(now==n+1){
		if(ch>=3&&sum>2*maz){
			ans++;
		}
		return;
	}
	dfs(now+1,sum+a[now],max(maz,a[now]),ch+1);
	dfs(now+1,sum,maz,ch);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n<=25){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		dfs(1,0,0,0);
		ans%=mod;
	}else{
		qpow(n);
		ans=(ans+mod-1)%mod;
		ans=(ans+mod-n)%mod;
		ans=(ans+mod-(n*(n-1)/2))%mod;
	}
	cout<<ans;
	return 0;
} 