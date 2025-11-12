#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=998244353;
int n,a[5005],s[5005],inv[5005],f[5005],b[5005],tot,ans[5005],num;
bool flag=1;

int c(int x){
	return s[n]*inv[x]%mod*inv[n-x]%mod;
}

int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

void dfs(int u,int step){
	f[u]=1;
	b[++tot]=a[u];
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		dfs(i,step+1);
	}
	if(step>=3){
		int res=0,maxn=0;
		for(int i=1;i<=tot;i++) res+=b[i],maxn=max(maxn,b[i]);
		if(res>2*maxn) ans[step]=(ans[step]+1)%mod;
	}
	tot--,f[u]=0;
	return;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	s[0]=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i]=s[i-1]*i%mod;
		inv[i]=qpow(s[i],mod-2);
		if(a[i]!=1) flag=0;
	}
	inv[0]=1;
	if(flag){
		int sum=0;
		for(int i=3;i<=n;i++) sum=(sum+c(i))%mod;
		cout << sum;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1]) cout << 1;
		else cout << 0;
		return 0;
	}
	dfs(0,0);
	for(int i=3;i<=n;i++) num=(num+ans[i]*inv[i]%mod)%mod;
	cout << num;
	return 0;
}
