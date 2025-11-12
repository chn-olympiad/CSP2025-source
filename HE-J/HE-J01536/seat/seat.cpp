#include<Bits/stdc++.h>
using namespace std;
int n,m;
int cmp(int a,int b) {
	return a>b;
}
int a[1005];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int j,k;
	for(int i=1; i<=n*m; i++) {
		j=i%(2*m);
		if(j>m) {
			j=m+1-j%m;
		}
		if(j==0) {
			j=1;
		}
		k=(i-1)/m+1;
		if(a[i]==r) {
			cout<<k<<' '<<j;
		}
	}
	return 0;
}
