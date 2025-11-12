#include<algorithm>
#include<stdio.h>
#define ll long long
#define N 505

using namespace std;

ll rd() {
	char c=getchar(); ll x=0, y=1;
	while(!(c >= '0' && c <= '9' || c == '-')) c=getchar();
	if(c == '-') y=-1, c=getchar();
	while(c >= '0' && c <= '9') x=x*10+c-'0', c=getchar();
	return x*y;
}
const ll mod=998244353;
int n, m;
int a[N], b[N];
ll jc[N], iv[N];
ll fp(ll x, ll y=mod-2) {
	ll ans=1;
	for(; y; y>>=1) {
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
	}
	return ans;
}
int bj[N];
int lis[N];
ll ans;
void dfs(int x, int sum, int num) {
	if(num+n-x+1 < m) return;
	if(x > n) {
		if(num >= m) {
//			for(int i=1; i<=n; i++) printf("%d ", lis[i]);
//			printf("\n");
			ans++;
		}
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!bj[i]) {
			bj[i]=1; lis[x]=i;
			if(a[x] == 0) dfs(x+1, sum+1, num);
			else if(b[i] <= sum) dfs(x+1, sum+1, num);
			else dfs(x+1, sum, num+1);
			bj[i]=0;
		}
	}
}
void case0() {
	dfs(1, 0, 0);
	printf("%lld", ans);
}

void case1() {
	if(m == n) {
		ll ans=1;
		for(int j=1; j<=n; j++) if(b[j] == 0) ans=0;
		printf("%lld", ans*jc[n]%mod);
		return;
	}
	ll ans=1;
	for(int i=1; i<=n; i++) {
		if(b[i]-i <= 0) ans=0;
		ans=ans*(b[i]-i)%mod;
	}
	printf("%lld", ans);
}
void case2() {
	
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	jc[0]=1; for(int i=1; i<N; i++) jc[i]=jc[i-1]*i%mod;
	iv[N-1]=fp(jc[N-1]); for(int i=N-2; i>=0; i--) iv[i]=(iv[i+1])*(i+1)%mod;

	n=rd(), m=rd();
	bool tf=true;
	for(int i=1; i<=n; i++) {
		char c=getchar(); while(!(c == '0' || c == '1')) c=getchar();
		a[i]=c-'0'; if(!a[i]) tf=false;
	}
	for(int i=1; i<=n; i++) b[i]=rd();
	sort(b+1, b+n+1);
	if(n <= 18) {case0(); return 0;}
	if(tf) {case1(); return 0;}
	else printf("0");
	return 0;
}

