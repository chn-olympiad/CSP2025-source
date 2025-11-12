#include<bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod=998244353, maxn=1e7+5;

int n, m, cnt;
int zero;
int mem[maxn];

int fpow(int a, int b) {
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int inv(int x) {
	return fpow(x,mod-2);
}

int fac(int x) {
	if(mem[x]) return mem[x];
	mem[x]=x*fac(x-1)%mod;
	return mem[x];
}

int C(int n, int m) {
	return fac(n)*inv(fac(m)*fac(n-m))%mod;
}

signed main() {
	mem[0]=1;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	string str;
	cin>>str;
	for(int i=1;i<=n;i++) {
		int x;
		scanf("%lld",&x);
		if(x==0) cnt++;
	}
	int res=0;
	for(int i=m;i<=n;i++) {
		int mult=1;
		for(int k=0;k<i;k++) {
			mult=(mult*(n-k))%mod;
		}
		res=(res+mult)%mod;
	}
	printf("%lld\n",res);
	return 0;
}
