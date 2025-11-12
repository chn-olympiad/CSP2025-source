#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=5e2+7,mod=998244353;
int n,m,ans;
int f[2][maxn][maxn],c[maxn][maxn],s[maxn],t[maxn],fac[maxn],finv[maxn];
char p[maxn];

inline int _mod(int x){
	return x>=mod?x-mod:x;
}

inline int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod,y>>=1;
	}
	return res;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",p+1);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		t[x]++; 
	}
	s[0]=t[0];
	for(int i=1;i<=n;i++) s[i]=s[i-1]+t[i];
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++) c[i][j]=_mod(c[i-1][j]+c[i-1][j-1]);
	}
	fac[0]=finv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	finv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i;i--) finv[i]=(ll)finv[i+1]*(i+1)%mod;
	
	f[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i;k++) f[i&1][j][k]=0;
		}
		for(int j=(p[i]=='0');j<=i;j++){
			for(int k=0;k<=i;k++){
				if(p[i]=='0'){
					if(j>0){
						int up=min(i-1,t[j]+k);
						for(int l=k-1;l<=up;l++){
							if(!f[i-1&1][j-1][l]) continue;
							f[i&1][j][k]=(f[i&1][j][k]+(ll)f[i-1&1][j-1][l]*c[l][k-1]%mod*fac[l-k+1]%mod*c[t[j]][l-k+1])%mod;
							if(l>=k){
								f[i&1][j][k]=(f[i&1][j][k]+(ll)f[i-1&1][j-1][l]*t[j]%mod*c[l][k]%mod*fac[l-k]%mod*c[t[j]-1][l-k])%mod;
								f[i&1][j][k]=(f[i&1][j][k]+(ll)f[i-1&1][j-1][l]*(s[j-1]-i+1+l)%mod*c[l][k]%mod*fac[l-k]%mod*c[t[j]][l-k])%mod;
							}
						}
					}
				}else{
					if(k>0) f[i&1][j][k]=f[i-1&1][j][k-1];
					if(j>0){
						int up=min(i-1,t[j]+k);
						for(int l=k;l<=up;l++){
							if(f[i-1&1][j-1][l]){
								f[i&1][j][k]=(f[i&1][j][k]+(ll)f[i-1&1][j-1][l]*(s[j-1]-i+1+l)%mod*c[l][k]%mod*fac[l-k]%mod*c[t[j]][l-k])%mod;
							}
						}
					}
				}
			}
		}
	}
	for(int i=0;i<=n-m;i++) ans=(ans+(ll)f[n&1][i][n-s[i]]*fac[n-s[i]])%mod;
	printf("%d",ans);
	return 0;
}
