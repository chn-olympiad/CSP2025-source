#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,fs,pm;
bool mep(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n*m; i++) {
		cin>>a[i];
	}
	fs=a[0];
	sort(a,a+n*m,mep);
	for(int i=0; i<n*m; i++) {
		if(a[i]==fs) {
			pm=i;
			break;
		}
	}
	int h,l;
	h=(pm+n)/n;
	if(h%2) {
		l=pm%n+1;
	} else {
		l=n-pm%n;
	}
	cout<<pm<<" "<<h<<" "<<l;
	return 0;
}