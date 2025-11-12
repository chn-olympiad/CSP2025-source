#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,m,fac[505],inv[505],a[505],sm[505],cnt[1005],f[20][(1<<18)+5],g[20][(1<<18)+5];
vector<int> vc[20];
string s;
int Pow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=1ll*x*x%mod)
		if(y&1)
			res=1ll*res*x%mod;
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>s,m=n-m;
	for(int i=1;i<=n;i++) sm[i]=sm[i-1]+(s[i-1]=='0');
	for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
	sort(a+1,a+n+1);
	for(int i=1;i<=2*n;i++) cnt[i]+=cnt[i-1];
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=Pow(fac[n],mod-2);
	for(int i=n-1;~i;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	if(n<=18){
		f[0][0]=1;
		for(int i=0;i<(1<<n);i++) vc[__builtin_popcount(i)].push_back(i);
		for(int i=0;i<n;i++){
			for(int j=0;j<=min(i+1,m);j++) 
				for(int k:vc[i+1])
					g[j][k]=0;
			for(int j=0;j<=min(i,m);j++)
				for(int k:vc[i])
					for(int o=1;o<=n;o++)
						if(!((k>>o-1)&1)){
							bool op=(a[o]<=j||s[i]=='0');
							g[j+op][k|(1<<o-1)]=(g[j+op][k|(1<<o-1)]+f[j][k])%mod;
						}
			for(int j=0;j<=min(i+1,m);j++) 
				for(int k:vc[i+1])
					f[j][k]=g[j][k];
		}
		int ans=0;
		for(int i=0;i<=m;i++) ans=(ans+f[i][(1<<n)-1])%mod;
		cout<<ans<<'\n';
		return 0;
	}
	if(!m){
		if(sm[n]||cnt[0]){
			cout<<"0\n";
			return 0;
		}
		cout<<fac[n]<<'\n';
		return 0;
	}
	if(m==n-1){
		int res=1,ct=0;
		for(int i=0;i<n;i++) 
			if(s[i]=='1')
				res=1ll*res*(cnt[i]-ct)%mod,ct++;
		cout<<(fac[n]-1ll*res*fac[sm[n]]%mod+mod)%mod<<'\n';
		return 0;
	}
	return 0;
}
