#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1005],cnt,fff=1;
bool cmp(long long a,long long b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	long long zong=n*m;
	for(long long i=1; i<=zong; i++) {
		scanf("%lld",&a[i]);
	}
	cnt=a[1];
	sort(a+1,a+zong+1,cmp);
	for(long long i=1; i<=m; i++) {
		if(i%2==1) {
			for(long long j=1; j<=n; j++) {
				if(a[fff]==cnt) {
					printf("%lld %lld",i,j);
					return 0;
				}
				fff++;
			}
		} else {
			for(long long j=n; j>=1; j--) {
				if(a[fff]==cnt) {
					printf("%lld %lld",i,j);
					return 0;
				}
				fff++;
			}
		}
	}
	return 0;
}
