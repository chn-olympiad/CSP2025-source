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

const LL N=1e5+10,M=2e2+10,INF=1e18;

LL n,a[N][4],f[M][M][M];

void solve1(){
	for(LL i=0;i<=n;i++) for(LL j=0;j<=n;j++) for(LL k=0;k<=n;k++) f[i][j][k]=-INF;
	f[0][0][0]=0;
	for(LL i=1;i<=n;i++){
		for(LL j=0;j<=i;j++){
			if(j>n/2) break;
			for(LL k=0;k<=i-j;k++){
				if(k>n/2) break;
				LL l=i-j-k;
				if(l>n/2) continue;
				f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
				if(k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
				if(j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
			}
		}
	}
	LL ans=0;
	for(LL i=0;i<=n/2;i++){
		for(LL j=0;j<=n/2;j++){
			if(n-i-j>n/2) continue;
			ans=max(ans,f[n][i][j]);
		}
	}
	write(ans);
}

LL p[N];

void solve2(){
	LL ans=0;
	for(LL i=1;i<=n;i++) ans+=a[i][1];
	for(LL i=1;i<=n;i++) p[i]=a[i][2]-a[i][1];
	sort(p+1,p+n+1);
	for(LL i=n;i>=n/2+1;i--) ans+=p[i];
	write(ans);
}

void solve(){
	read(n);
	for(LL i=1;i<=n;i++) for(LL j=1;j<=3;j++) read(a[i][j]);
	if(n<=200){
		solve1();
		return ;
	}
	solve2();
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	LL T=1;
	read(T);
	while(T--){
		solve();
	}
	return 0;
}

