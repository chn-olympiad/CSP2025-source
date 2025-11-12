#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
const int mod=998244353;
int a[N],f[N][N];
int qpow(int a,int b) {
	int res=1;
	while(b) {
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1; 
	}
	return res;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxv=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxv=max(maxv,a[i]);
	sort(a+1,a+1+n);
	f[0][0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=maxv;j++) {
			if(j<a[i]) f[i][j]=(f[i][j]+f[i-1][j])%mod;
			else f[i][j]=(f[i][j]+f[i-1][j]+f[i-1][j-a[i]])%mod;
		}
	}
	for(int i=1;i<=n;i++) {
		int res=0;
		for(int j=0;j<=a[i];j++) res=(res+f[i-1][j])%mod;
		ans=((ans+qpow(2,i-1))%mod-res+mod)%mod;
	}
	cout<<ans%mod;
}
// I AK CSP-J
// I finally get 400pts in CSP-J contest 
// Can I also win in the CSP-S afternoon again?
