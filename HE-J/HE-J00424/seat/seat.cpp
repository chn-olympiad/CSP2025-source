#include<bits/stdc++.h>
#define ll int
using namespace std;
ll a[150],s[20][20];
ll m,n,t,p,q;
bool cmp(ll x,ll y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
		if(i==1) t=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	p=0;
	for(int i=1; i<=m; i++) {
		if(i%2==1) {
			for(int j=1; j<=n; j++) {
				s[j][i]=a[++p];
				if(a[p]==t) {
					printf("%lld %lld",i,j);
					return 0;
				}
			}
		} else {
			for(int j=n; j>=1; j--) {
				s[j][i]=a[++p];
				if(a[p]==t) {
					printf("%lld %lld",i,j);
					return 0;
				}
			}

		}
	}
	return 0;
}
