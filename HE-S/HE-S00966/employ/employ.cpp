#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 512;
const ll M = 998244353;
int limit[N];
ll fac[N] = {1, 1};
int sumzero[N];
vector<int> zeros;
char diff[N];
ll A(ll n, ll m) {
	return fac[m] / fac[m-n] % M;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	for (int i=2;i<N;i++) {
		fac[i] = fac[i-1] * i % M;
	}
	int n,m;
	scanf("%d%d",&n,&m);
	ll p = fac[n];
	ll f = fac[n-1];
	scanf("%s",diff);
	int len = strlen(diff);
	for (int i=0;i<len;i++) {
		sumzero[i+1] = sumzero[i] + (diff[i]=='0');
		if (diff[i]=='0') {
			zeros.push_back(i+1);
		}
	}
	
	for (int i=0;i<n;i++) {
		int lim;
		scanf("%d",&lim);
		limit[lim]++;
	}
	
	for (int i=1;i<=sumzero[m];i++) {
//		printf("i = %d sumzero[m] = %d zeros[i] = %d limit[i] = %d\n",i,sumzero[m],zeros[i],limit[i]);
		p /= A(n-zeros[i-1], limit[i]);
	}
	
	printf("%lld\n",p);
	return 0;
}
