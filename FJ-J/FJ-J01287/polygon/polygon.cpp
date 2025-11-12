#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=5e3+5;
int n,ans,a[N],inv[N],f[N],d;
void dfs(int x,int cnt,int mx,int s,int f) {
	if(x>n) return;
	if(cnt>=3&&mx*2<s) {
		if(f==1) ans++,ans%=mod;  
	}
	dfs(x+1,cnt+1,max(mx,a[x+1]),s+a[x+1],1);
	dfs(x+1,cnt,mx,s,0);
}
inline int Pow(int x,int y) {
	int s=1;
	for(; y; y>>=1) {
		if(y&1) s=s*x%mod;
		x=x*x%mod;
	}
	return s;
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>a[i],d=max(d,a[i]);
	if(d==1) {
		f[0]=1;
		for(int i=1; i<=N+1; ++i) f[i]=f[i-1]*i%mod;
		inv[N]=Pow(f[N],mod-2);
		for(int i=N-1; i>=0; --i) inv[i]=inv[i+1]*(i+1)%mod;
		for(int i=3; i<=n; ++i)
			ans=(ans+f[n]*inv[i]%mod*inv[n-i]%mod)%mod;
		cout<<ans;
		return 0;
	}
	for(int i=1; i<=n-2; ++i)
		dfs(i,1,a[i],a[i],1);
	cout<<ans;
}