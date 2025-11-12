#include<bits/stdc++.h>
using namespace std;
#define int long long
int cmp(int x,int y) {
	return x>y;
}
int n,m,zj,h;
int a[1000];
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	zj=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=m; i++) {
		if(i%2) {
			for(int j=1; j<=n; j++) {
				if(a[++h]==zj) {
					cout<<i<<" "<<j;
					return 0;
				}
			}
		} else {
			for(int j=n; j>=1; j--) {
				if(a[++h]==zj) {
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
