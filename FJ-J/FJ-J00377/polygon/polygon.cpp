#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353,MAXN=5000;
long long ans,n,a[MAXN];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	int zong=a[1]+a[2]+a[3];
	int maxx=max(a[1],max(a[2],a[3]));
	if(zong>2*maxx) {
		printf("1");
		return 0;
	} else {
		printf("0");
		return 0;
	}
	return 0;
}
