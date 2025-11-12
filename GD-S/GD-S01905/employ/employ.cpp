#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=505,mod=998244353;

int mi(int o,int p){
	int res=1;
	while(p){
		if(p&1) res*=o,res%=mod;
		o*=o;
		o%=mod;
		p>>=1;
	}
	return res;
}

long long n,m,c[N],f[N][N][N],t[N],fac[N],ifac[N],g[N],A[N][N],C[N][N],ans;
string s;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod,ifac[i]=mi(fac[i],mod-2);
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) if(i>=j) A[i][j]=fac[i]*ifac[i-j]%mod,C[i][j]=A[i][j]*ifac[j]%mod;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i],t[c[i]]++;
	g[0]=t[0];
	for(int i=1;i<=n;i++) g[i]=t[i]+g[i-1];
	f[0][0][0]=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++){
					for(int p=k;p>=0&&k-p<=t[i-j];p--) if(i-1-j>=0&&g[i-1-j]-(i-1-k)>=0) f[i][j][p]+=f[i-1][j][k]*(g[i-1-j]-(i-1-k))%mod*A[t[i-j]][k-p]%mod*C[k][p]%mod;
					f[i][j+1][k+1]+=f[i-1][j][k]%mod;
				}
			}
		}
		else{
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++){
					for(int p=k;p>=0&&k-p<=t[i-j];p--) if(i-j-1>=0&&g[i-j-1]-(i-1-k)>=0) f[i][j][p]+=f[i-1][j][k]*(g[i-j-1]-(i-1-k))%mod*A[t[i-j]][k-p]%mod*C[k][p]%mod;
					for(int p=k+1;p>=0&&k+1-p<=t[i-j];p--) f[i][j][p]+=f[i-1][j][k]*A[t[i-j]][k+1-p]%mod*C[k+1][p]%mod;//,cout<<i-1<<" "<<j<<" "<<k<<" "<<p<<"  "<<f[i-1][j][k]*A[t[i-j]][k+1-p]%mod<<"ggg\n";
				}
			}
		}
		for(int j=0;j<=i;j++) for(int k=0;k<=i;k++) f[i][j][k]%=mod;//,cout<<i<<" "<<j<<" "<<k<<"  "<<f[i][j][k]<<"\n";
	}
	for(int j=m;j<=n;j++) for(int k=0;k<=n;k++) if(g[n]-g[n-j]>=k&&f[n][j][k]) ans+=f[n][j][k]*fac[k]%mod;//,cout<<n<<" "<<j<<" "<<k<<"  "<<f[n][j][k]<<"hhh\n";
	ans=(ans%mod+mod)%mod;
	cout<<ans;
}
