#include<bits/stdc++.h>
using namespace std;
#define N 505
#define int long long
#define mod 998244353ll
int fpow(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=r*x%mod;
		x=x*x%mod;
		y>>=1;
	} 
	return r;
}
int n,m;
int mul;
int fac[N],inv[N];
int _[2][N][N];
int (*f)[N]=_[0],(*g)[N]=_[1];
char s[N];
int a[N];
int C(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
	inv[N-1]=fpow(fac[N-1],mod-2);
	for(int i=N-1;i;i--)inv[i-1]=inv[i]*i%mod;
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1,o;i<=n;i++){
		cin>>o;
		a[o]++;
	}
	for(int i=1;i<=n;i++)mul+=(s[i]=='0');
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=0;i<=a[0];i++)f[0][mul-i]=C(mul,i)%mod; 
//		for(int i=0;i<=m;i++){
//			for(int j=0;j<=m;j++)cout<<f[i][j]<<' ';
//			cout<<endl;
//		}cout<<endl;
	for(int i=0;i<n;i++){
		int o=s[i+1]-'0';
		memset(g,0,sizeof(_[0]));
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(o){
					(g[j][k+1]+=f[j][k])%=mod;
//					if(i==0&&j==0&&k==1)cout<<op<<endl;
//					if(op==0)continue;
					int d=a[j+1]-a[j];
					for(int l=0;l<=min(d,k);l++){
						(g[j+1][k-l]+=f[j][k]*C(k,l)%mod*(a[j]-(i+mul-k)))%=mod;
					}
				}else{
					int d=a[j+1]-a[j];
					for(int l=0;l<=min(d,k);l++){
						(g[j+1][k-l]+=f[j][k]*C(k,l)%mod)%=mod;
					}
				}
			}
		}
		if(!o)mul--;
		swap(f,g);
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++)cout<<f[i][j]<<' ';
			cout<<endl;
		}cout<<endl;
	}
	int ans=0;
	int d=a[n]-a[n-m];
	ans=f[n-m][d];
	for(int i=n;i;i--)a[i]-=a[i-1];
	for(int i=0;i<=n;i++)ans=ans*fac[a[i]]%mod,cout<<a[i]<<' '<<ans<<endl;
	cout<<ans<<endl;
	return 0;
} 
