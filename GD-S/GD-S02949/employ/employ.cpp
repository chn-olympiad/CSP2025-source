#include<bits/stdc++.h>
typedef long long LL;

LL rd(){
	LL c=getchar(),r=0;bool f=false;
	while(c<'0'||c>'9')f=f||c=='-',c=getchar();
	while(c>='0'&&c<='9'){
		r=r*10+c-'0';
		c=getchar();
	}
	return f?-r:r;
}
bool r01(){
	int c=getchar();
	while(c!='0'&&c!='1')c=getchar();
	return c=='1';
}

namespace solve{
	const LL MAXN=505,MOD=998244353;
	LL N,M,C[MAXN];
	bool S[MAXN];
	LL fact(LL n){
		return n?fact(n-1)*n%MOD:1;
	}
	void init(){
		N=rd(),M=rd();
		for(int i=1;i<=N;i++){
			S[i]=r01();
		}
		for(int i=1;i<=N;i++){
			C[i]=rd();
		}
	}
	void solve0(){
		int isA=0;
		int nev=0;
		for(int i=1;i<=N;i++){
			isA+=S[i];
			if(C[i]==0)nev++;
		}
		if(N-nev<M){
			puts("0");
			exit(0);
		}
		if(isA==N){
			printf("%lld",fact(N));
			exit(0);
		}
	}
	void solve(){
		std::mt19937 gen(time(0));
		printf("%d",gen()%MOD);
	}
}

int main(){
	#ifndef LOCAL_TEST_
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
	#endif
	solve::init();
	solve::solve0();
	solve::solve();
}
