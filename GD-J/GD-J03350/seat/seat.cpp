#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001];
int l;
int sum;
int c,d;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1; i<=l; i++) {
		cin>>a[i];
	}
	for(int i=2; i<=l; i++) {
		if(a[i]>a[1]) {
			sum++;
		}
	}
	sum++;
	c=ceil((double)sum/(double)n);
	if(c%2==1) {
		if(sum%n==0) {
			d=n;
		} else {
			d=sum%n;
		}
	} else {
		d=n-(sum%n)+1;
	}
	cout<<c<<" "<<d;
	return 0;
}
