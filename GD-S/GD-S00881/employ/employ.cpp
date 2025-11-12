#include <bits/stdc++.h>
#define ll long long
#define pii array<ll,2>
using namespace std;
ll read(){
	ll s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s*f;
}
// bool st;
int fac[510],ifac[510],inv[510];
const int mod=998244353;
int power(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m,s[510],c[510],f[110][110][110],ans,g[510][510];
char S[510];
int C(int a,int b){
	if(a<0||b<0||a<b) return 0;
	return 1ll*fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}
void add(int &x,int y){
	x+=y;
	if(x>=mod) x-=mod;
}
// bool ed;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=fac[0]=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=power(fac[n],mod-2);
	for(int i=n;i;i--) ifac[i-1]=1ll*ifac[i]*i%mod,inv[i]=1ll*ifac[i]*fac[i-1]%mod;
	scanf("%s",S);
	for(int i=1;i<=n;i++) c[read()]++;
	s[0]=c[0];
	for(int i=1;i<=n;i++) s[i]=s[i-1]+c[i];
	int fl=0;
	for(int i=0;i<n;i++) if(S[i]=='0') fl=1;
	if(m==n){
		if(fl||c[0]){
			puts("0");
			return 0;
		}
		printf("%d\n",fac[n]);
		return 0;
	}
	if(n>100&&!fl){
		g[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=s[i-1];j++){
				if(j<i) add(g[i][j+c[i]],1ll*g[i-1][j]*C(j+c[i],j)%mod);
				else
					for(int x=0;x<=c[i];x++)
						add(g[i][j+x],1ll*g[i-1][j]*C(x+(j-i),x)%mod*C(s[i-1]-j+(i-1)+(c[i]-x),c[i]-x)%mod);
			}
		}
		for(int i=m;i<=n;i++) add(ans,g[n][n-i]);
		printf("%d\n",ans);
		return 0;
	}
	f[0][0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<=i&&k<=s[j];k++){
				if(!f[i][j][k]) continue;
				if(S[i]=='1') add(f[i+1][j][k],f[i][j][k]);
				for(int x=0;x<=c[j+1];x++){
					add(f[i+1][j+1][k+x+1],1ll*f[i][j][k]*(s[j]-k)%mod*C(i-k,x)%mod*C(c[j+1],x)%mod*fac[x]%mod);
					if(S[i]=='0')
						add(f[i+1][j+1][k+x],1ll*f[i][j][k]*C(i-k+1,x)%mod*C(c[j+1],x)%mod*fac[x]%mod);
				}
			}
	for(int i=m;i<=n;i++)
		add(ans,1ll*f[n][n-i][s[n-i]]*fac[n-s[n-i]]%mod);
	printf("%d\n",ans);
	// fprintf(stderr,"%.3lf\n",(&st-&ed)/1024.0/1024.0);
	return 0;
}
//g++ employ.cpp -o employ -std=c++14 -O2 -Wall -Wextra -fno-ms-extensions