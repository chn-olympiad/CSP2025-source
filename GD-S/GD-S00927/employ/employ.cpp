#include<bits/stdc++.h>
using namespace std;

#define LL long long

void read(LL &x){
	scanf("%lld",&x);
}

void write(LL x){
	printf("%lld\n",x);
}

void write(LL x,LL op){
	if(!op) printf("%lld ",x);
	else printf("%lld\n",x);
}

const LL N=5e2+10,M=20,K=1<<18,mod=998244353;

LL n,m,p[N];

int f[2][M][K];

char s[N];

void solve1(){
	LL S=1<<n;
	f[0][0][0]=1;
	for(LL i=0,op=0;i<n;i++,op^=1){
		for(LL j=0;j<=i;j++){
			for(LL k=0;k<S;k++){
				for(LL l=0;l<n;l++){
					if((k>>l)&1) continue;
					f[op^1][j+((p[l+1]>(i-j))&&(s[i+1]=='1'))][k|(1<<l)]=(f[op^1][j+((p[l+1]>(i-j))&&(s[i+1]=='1'))][k|(1<<l)]+f[op][j][k])%mod;
				}
			}
		}
		for(LL j=0;j<=i;j++) for(LL k=0;k<S;k++) f[op][j][k]=0;
	}
	LL ans=0;
	for(LL i=m;i<=n;i++) ans=(ans+f[n&1][i][S-1])%mod;
	write(ans);
}

LL g[N];

void solve2(){
	for(LL i=1;i<=n;i++) g[p[i]]++;
	LL ans=0;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=n;j++){
			if(p[i]<=j-1||s[j]=='0') continue;
			LL sum=1,cnt=0,ss=0;
			for(LL k=1;k<j;k++){
				cnt+=g[k-1];
				if(p[i]==k-1) cnt--;
				if(s[k]=='0'){
					ss++; 
					continue;
				}
				sum=sum*cnt%mod;
				cnt--;
			}
			for(LL k=1;k<=n-j+ss;k++) sum=sum*k%mod;
			ans=(ans+sum)%mod;
		}
	}
	write(ans);
}

void solve3(){
	bool bl=true;
	for(LL i=1;i<=n;i++){
		if(s[i]=='0') bl=false;
	}
	for(LL i=1;i<=n;i++){
		if(p[i]==0) bl=false;
	}
	if(!bl) write(0);
	else{
		LL ans=1;
		for(LL i=1;i<=n;i++) ans=ans*i%mod;
		write(ans);
	}
}

void solve(){
	read(n),read(m);
	scanf("%s",s+1);
	for(LL i=1;i<=n;i++) read(p[i]);
	if(n<=18){
		solve1();
		return ;
	}
	if(m==1){
		solve2();
		return ;
	}
	if(m==n){
		solve3();
		return ;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	LL T=1;
//	read(T);
	while(T--){
		solve();
	}
	return 0;
}

