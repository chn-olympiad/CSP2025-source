#include<bits/stdc++.h>
using namespace std;
int n,m,sc,a[105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1; i<=n*m; i++) {
		if(a[i]!=sc) {
			continue;
		}
		if((i+n-1)/n%2) {
			if(i%n) {
				cout<<(i/n+1)<<" "<<(i%n);
			} else {
				cout<<(i/n)<<" "<<n;
			}
		} else {
			if(i%n) {
				cout<<(i/n+1)<<" "<<(n-i%n+1);
			} else {
				cout<<(i/n)<<" "<<1;
			}
		}
	}
	return 0;
}