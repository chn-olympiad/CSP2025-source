#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5003,mod=998244353;
int n,a[N];
ll ans,inv[N];
void dfs(int step,int s,int maxn){
	if(step==n+1){
		if(s>maxn*2)	ans++;
		return ;
	}
	dfs(step+1,s+a[step],max(maxn,a[step]));
	dfs(step+1,s,maxn);
	return ;
}
ll ksm(ll b,ll p){
	ll ans=1;
	while(p){
		if(p&1)	ans=ans*b%mod;
		b=b*b%mod;
		p>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)	f=0;
	}
	if((!f)||n<=27){
		dfs(1,0,0);
	}else{
		for(int i=1;i<=n;i++)	inv[i]=ksm(i,mod-2);
		for(int i=3;i<=n;i++){
			ll tmp=1;
			for(int j=i+1;j<=n;j++)	tmp=tmp*j%mod;
			for(int j=1;j<=n-i;j++)	tmp=tmp*inv[j]%mod;
			ans+=tmp;
		}
	}
	cout<<ans;
	return 0;
}